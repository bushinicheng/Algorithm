//from http://blog.csdn.net/xiajun07061225/article/details/8088784
#include <stdio.h>
#define MAXVAL 9999
void optimal_bst(double* p,double* q,int n,double w[][n+2],double e[][n+2],int root[][n+1]){
	for(int i=1;i<=n+1;i++){
		w[i][i-1]=q[i-1];
		e[i][i-1]=q[i-1];
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i<=n-len+1;i++){
			int j=i+len-1;
			e[i][j]=MAXVAL;
			w[i][j]=w[i][j-1]+p[j]+q[j];
			for(int k=i;k<=j;k++){
				double	temp=e[i][k-1]+e[k+1][j]+w[i][j];
				if(temp<e[i][j]){
					e[i][j]=temp;
					root[i][j]=k;
				}
			}
		}
	}
}
void print_root(int n,int root[][n+1]){
	printf("%s\n", "root of every sub-tree");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d\t", root[i][j]);
		}
		printf("\n");
	}
}
void print_optimal_bst(int i,int j,int r,int n,int root[][n+1]){
	int root_child=root[i][j];
	if(root_child==root[1][n]){
		printf("%s->%d\n","root",root_child);
		print_optimal_bst(1,root_child-1,root_child,n,root);
		print_optimal_bst(root_child+1,j,root_child,n,root);
		return;
	}
	if(j<i-1){
		return;
	}
	else if(j==i-1){
		if(j<r){
			printf("d%d is k%d's left child\n", j,r);
		}
		else{
			printf("d%d is k%d's left child\n", j,r);	
		}
		return;
	}
	else{
		if(root_child<r){
			printf("k%d is k%d's left child\n", j,r);
		}
		else{
			printf("k%d is k%d's right child\n", j,r);
		}
		print_optimal_bst(i,root_child-1,root_child,n,root);
		print_optimal_bst(root_child+1,j,root_child,n,root);
	}
}
int main(int argc, char const *argv[])
{	int n=5;
	double p[6] = {-1,0.15,0.1,0.05,0.1,0.2};  
	double q[6] = {0.05,0.1,0.05,0.05,0.05,0.1};  	
	int root[n + 1][n + 1];//记录根节点
	double w[n + 2][n + 2];//子树概率总和  
	double e[n + 2][n + 2];//子树期望代价
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++){
			root[i][j]=0;
		}
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++){
			w[i][j] = 0;
			e[i][j]=0;
		}

	optimal_bst(p,q,n,w,e,root); 
	print_root(n,root);
	printf("%s\n", "optimal bst:");
	print_optimal_bst(1,n,-1,n,root);
	return 0;
}