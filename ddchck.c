#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int mutex[10][2];
int adj[10][12];
int visit[10][12];
int visitlist[50];
int count=0,prev,from,to;
void push( int n, int id){
		prev=count;
		for(int i=0; i<10; i++){
			if(mutex[i][1] == 0){
				mutex[i][0] = id;
				mutex[i][1] = n;
				count=i;
				break;	
			}	
		}	
	}
int pushvisit(int n){
	for(int i=0; i<50; i++){
		if(visitlist[i]==0){
			visitlist[i]=n;
			return i;
		}
	}
}
void adjedge(int from,int to){
	for(int i=2; i<12; i++){
		if(adj[from][i]==0){
			adj[from][i]=to;
			break;
		}
	}
}
void adjpush(int from, int addr, int id){
	for(int i=0;i<10; i++){
		if(adj[i][0] == 0){
			adj[i][0]=addr;
			adj[i][1] = id;
			adjedge(from,i);
			break;
		}
	} 	
}
void mutexpop(int addr, int id){
	for(int i=0; i<10; i++){
		if(mutex[i][0]==id && mutex[i][1]==addr){
			mutex[i][0]=0; mutex[i][1]=0;
			break;
		}
	}
}
void adjpop(int addr, int id){
	int i=0;
	for(; i<10; i++){
		if(adj[i][0]==addr && adj[i][1]==id){
			adj[i][0]=0; adj[i][1]=0;
			break;
		}
	}
	for(int j=0; j<10; j++){
		for(k=2; k<12; k++){
			if(adj[j][k]==i){
				adj[j][k]=0;
			}
		}
	}
}
void findcycle(int n ){
	for(int i=2; i<12; i++){
		if(adj[n][i]==0){
			break;
		}
		if(visit[n][i]==0){
			visit[n][i]=1;
			int count = pushvisit(adj[n][i]);
			for(int k=0; k<count; k++){
				if(visitlist[k]==adj[n][i]){
					printf("Threr is a deadlock\n");
					exit(1);
				}
			}
			findcycle(adj[n][i]);
		}
		
	}
}
int main(){
	for(int i=0; i<10; i++){
		mutex[i][0]=0;
		mutex[i][1]=0;
	}
	for(int i=0; i<50; i++){
		visitlist[i]=0;
	}
	for(int i=0; i<10; i++){
		for(int j =0; j<12; j++){
			adj[i][j]=0;
			visit[i][j]=0;
		}
	
	}
	int fd = open(".ddtrace", O_RDONLY | O_SYNC) ;
	int id, addr,iden;
	while(1){
		to=-1; from=-1;
		read(fd,&iden,4);
		if(iden==0){
			read(fd,&addr,4);
			read(fd,&id,4);
			push(addr,id);
			for(int i=0; i<10; i++){
				if(id==mutex[i][0]){
					for(int j=0; j=10; j++){
						if(mutex[i][1]==adj[j][0])
							from=j;
						if(addr==adj[j][0])
							to =j;
					}		
				}
			}
			if(from==-1 && to==-1){
				for(int i=0; i<10; i++){
					if(adj[i][0]==0){
						adj[i][0]=addr;
						adj[i][1] = id;
						break;
					}
				}
			}
			else if(to!=-1)
				adjedge(from,to);
			else
				adjpush(from,addr,id);		
		}
		else if(iden==1){
			read(fd,&addr,4);
                        read(fd,&id,4);
			mutexpop(addr,id);
			adjpop(addr,id);	
		}
		for(int i=0; i<10; i++){
			findcycle(i);	
			
		}
		else
			break;
	}
	
	
}
