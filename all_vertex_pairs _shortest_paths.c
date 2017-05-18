//beetween all Vertex pairs  shortest paths
#include <stdio.h>
#include <stdlib.h>
#define INFINITE 10000


void print_all_pairs_shortest_path(int **PI,int i,int j);
int ** extended_shortest_paths(int **L,int L_ROWS,int **W);
int min(int a,int b);
int ** slow_all_paths_shortest_paths(int **W,int W_ROWS);
int getsum(int a,int b);
int **get_PI(int **L,int L_ROWS,int **W);
void print_all_pairs_shortest_paths(int **PI,int i,int j){
	if(i==j){
		printf("-->%d",i);
	}
	else if(PI[i][j]==INFINITE){
		printf("no paths from %d to %d\n",i,j);
	}
	else {
		print_all_pairs_shortest_paths(PI,i,PI[i][j]);
		printf("-->%d",j);
	}
}
int **get_PI(int **L,int L_ROWS,int **W){
	int n=L_ROWS;
	int **PI=(int **)malloc((n+1)*sizeof(int *));
	for(int i=1;i<=n;i++){
		PI[i]=(int *)malloc((n+1)*sizeof(int));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			PI[i][j]=INFINITE;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(L[i][k]+W[k][j]==L[i][j]){
					PI[i][j]=k;
				}
			}
		}
	}
	return PI;	
}
int ** extended_shortest_paths(int **L,int L_ROWS,int **W){
	int n=L_ROWS;
	int **L_NEW=(int **)malloc((n+1)*sizeof(int *));
	for(int i=1;i<=n;i++){
		L_NEW[i]=(int *)malloc((n+1)*sizeof(int));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			L_NEW[i][j]=INFINITE;
			for(int k=1;k<=n;k++){
				int sum=getsum(L[i][k],W[k][j]);
				L_NEW[i][j]=min(L_NEW[i][j],sum);
			}
		}
	}
	return L_NEW;
}
int getsum(int a,int b){
	if(a==INFINITE){
		if(b!=INFINITE)
			return INFINITE;
		return a+INFINITE;
	}
	else{
		if(b==INFINITE)
			return INFINITE;
		return a+b;
	}
}
int min(int a,int b){
	if(a>b)
		return b;
	return a;
}
int ** slow_all_paths_shortest_paths(int **W,int W_ROWS){
	int n=W_ROWS;
	int **L_m_1=W;
	int **L_m;
	for(int m=2;m<=n-1;m++){
		L_m=extended_shortest_paths(L_m_1,n,W);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				printf("%d ",L_m[i][j]);		
			}
			printf("\n");
		}
		printf("\n\n");
		L_m_1=L_m;
	}
	return L_m;
}
int **fast_all_pairs_shortest_paths(int **W,int W_ROWS){
	int n=W_ROWS;
	int **L_m=W;
	int **L_2m;
	int m=1;
	while(m<n-1){
		L_2m=extended_shortest_paths(L_m,n,L_m);
		m=2*m;
	}
	return L_2m;
}

void singal_source_shortest_paths(){
	
}
int **floyd_warshall(int **W,int W_ROWS){
	int n=W_ROWS;
	int **D=W;
	int **D_NEW;
	for(int k=1;k<=n;k++){
		D_NEW=(int **)malloc((n+1)*sizeof(int *));
		for(int v=1;v<=n;v++){
			D_NEW[v]=(int *)malloc((n+1)*sizeof(int));
		}
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				D_NEW[x][y]=INFINITE;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				int sum=getsum(D[i][k],D[k][j]);
				D_NEW[i][j]=min(D[i][j],sum);
			}
		}
		D=D_NEW;
	}
	return D_NEW;
}
int main()
{
	int n=5;
	int **W=(int **)malloc((n+1)*sizeof(int *));
	for(int i=1;i<=n;i++){
		W[i]=(int *)malloc((n+1)*sizeof(int));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			//printf("%d %d\n", i,j);
			scanf(" %d",&W[i][j]);
		}
	}
	int **L;
	L=slow_all_paths_shortest_paths(W,n);
	int **PI=get_PI(L,n,W);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			print_all_pairs_shortest_paths(PI,i,j);
			printf("\n");
		}
	}

	return 0;
}
