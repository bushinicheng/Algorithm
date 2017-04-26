//from http://blog.csdn.net/z84616995z/article/details/38562467
#include <stdio.h>
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int min_3(int n,int m,int A[][m+1],int i,int j){
	int min_d=0;
	if(j==1){
		min_d=min(A[i-1][j],A[i-1][j+1]);
	}
	else if(j==m){
		min_d=min(A[i-1][j],A[i-1][j-1]);
	}
	else{
		min_d=min(A[i-1][j],min(A[i-1][j-1],A[i-1][j+1]));
	}
	return min_d;
}
int min_3_return_index(int n,int m,int A[][m+1],int i,int j){
	if(j==1){
		return A[i][j]>A[i][j+1]?j+1:j;
	}
	else if(j==m){
		return A[i][j]>A[i][j-1]?j-1:j;
	}
	else{
		int min_d=min(A[i][j],min(A[i][j-1],A[i][j+1]));
		if(min_d==A[i][j])
			return j;
		else if(min_d==A[i][j-1])
			return j-1;
		else
			return j+1;
	}
}
void print_sequence(int n,int m,int A[][m+1],int i,int j){
	int T;
	if(i==0)
		return;
	else{
		T=min_3_return_index(n,m,A,i,j);
	}
	print_sequence(n,m,A,i-1,T);
	printf("the %dth line's and %dth colum can be deleted\n", i,T);
}
int find_min_seam_carving(int n,int m,int d[][m+1]){
	int A[n+1][m+1];
	for(int i=1;i<=m;i++){
		A[1][i]=d[1][i];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			A[i][j]=d[i][j]+min_3(n,m,A,i,j);
		}
	}
	int MIN=0x7fffffff;
	int t=0;
	for(int i=1;i<=m;i++){
		if(A[n][i]<MIN){
			MIN=A[n][i];
			t=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("%s %d\n", "the min sum is",MIN);
	print_sequence(n,m,A,n,t);
}

int main(){
	int n=6,m=5;
	int d[][6]={{0,0,0,0,0,0},{0,3,2,2,3,3},{0,1,2,1,2,1},{0,3,2,1,3,1},{0,2,1,1,2,2},{0,1,2,2,3,3},{0,2,2,2,1,1}};
	find_min_seam_carving(n,m,d);
}