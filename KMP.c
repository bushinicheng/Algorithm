#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *compute_prefix_function(char* P);

void KMP(char* T,char *P){
	int n=strlen(T)-1;
	int m=strlen(P)-1;
	int *PI=compute_prefix_function(P);
	int q=0;
	for(int i=1;i<=n;i++){
		while(q>0&&P[q+1]!=T[i]){
			q=PI[q];
		}
		if(P[q+1]==T[i]){
			q++;
		}
		if(q==m){
			printf("patter occurs with shift %d\n", i-m);
		}
		//q=PI[q];
	}
}
int *compute_prefix_function(char* P){
	int m=strlen(P)-1;
	int *PI=(int *)malloc((m+1)*sizeof(int));
	PI[0]=0;
	PI[1]=0;
	int k=0;
	for(int q=2;q<=m;q++){
		while(k>0&&P[k+1]!=P[q]){
			k=PI[k];
		}
		if(P[k+1]==P[q]){
			k++;
		}
		PI[q]=k;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n", PI[i]);
	}
	return PI;
}
int main(){
	char *P="aababaca"; //P[0] is not used
	char *T="aabababacaba";//T[0] is not used
	KMP(T,P);

	return 0;
}