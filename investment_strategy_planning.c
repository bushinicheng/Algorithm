//from http://blog.csdn.net/z84616995z/article/details/38641919
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void investment_strategy_planning(int n,int m,double **r){
	double v[n+1][m+1];
	double f1=0.01,f2=0.84;
	int i,j;
	for(int i=1;i<=m;i++){
		v[1][i]	=r[i][1]+1.0;
	}
	for(int j=2;j<=n;j++){
		for(int k=1;k<=m;k++){
			v[j][k]=-0x7fffffff;
			for(int i=1;i<=m;i++){
				if((v[j-1][i]-(i==k?f1:f2))*(1.0+r[k][j])>v[j][k]){
					v[j][k]=(v[j-1][i]-(i==k?f1:f2))*(1.0+r[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%lf ", v[i][j]);
		}
		printf("\n");
	}
}
int main(){
	srand((unsigned)time(NULL));
	double **r;
	int m=8;
	int n=10;
	int i,j;
	r=(double**)malloc((m+1)*sizeof(double*));
	for(int i=0;i<=m;i++){
		r[i]=(double*)malloc((n+1)*sizeof(double));
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			r[i][j]=(((rand()%1000+1)/1000.0+1)-1)/10.0;
		}
	}
	investment_strategy_planning(n,m,r);
}