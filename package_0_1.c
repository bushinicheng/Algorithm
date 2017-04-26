#include <stdio.h>
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
void package_0_1(int w[],int v[],int W,int n,int c[][11]){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=W;j++){
			if(i==1){
				if(j<w[i])
					c[i][j]=0;
			}
			else{
				if(j<w[i]){
					c[i][j]=c[i-1][j];
				}
				else{
					c[i][j]=max(c[i-1][j],v[i]+c[i-1][j-w[i]]);
				}
			}
		}
	}

}
void print_package_0_1(int c[][11],int w[]){
	int i=5;
	int j=10;
	printf("max value is %d\n",c[i][j]);
	while(i!=1){
		if(c[i][j]==c[i-1][j]){
			printf("%d not select\n", i);
		}
		else{
			printf("%d select\n", i);
			j=j-w[i];
		}
		i--;
	}
	if(c[i][j]==0){
		printf("%d not select\n", i);
	}
	else{
		printf("%d select\n", i);
	}
}
int main(){
	int w[]={0,3,6,3,8,6};
	int v[]={0,4,6,6,12,10};
	int W=10;
	int c[6][11]={0};
	package_0_1(w,v,W,5,c);
	print_package_0_1(c,w);
}
