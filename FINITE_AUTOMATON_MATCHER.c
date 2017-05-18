#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 127

int **compute_transition_function(char* P,char* sigma);
int is_postfix(int k,char* P, int q, char ch);

void FINITE_AUTOMATON_MATCHER(char* T,char*P,char* sigma){
	int n=strlen(T)-1;//T[0] is not used
	int m=strlen(P)-1;
	int q=0;
	int **delta=compute_transition_function(P,sigma);
	for(int i=1;i<=n;i++){
		q=delta[q][T[i]-'a'];
		if(q==m){
			printf("pattern occurs with shift %d\n", i-m);
		}
	}
}

int **compute_transition_function(char* P,char* sigma){
	int m=strlen(P)-1;
	int len=strlen(sigma);
	int **delta=(int **)malloc(MAXLEN*sizeof(int *));
	for(int i=0;i<MAXLEN;i++){
		delta[i]=(int *)malloc(MAXLEN*sizeof(int));
	}
	for(int q=0;q<=m;q++){
		for(int i=0;i<len;i++){
			int k=m+1>q+2?q+2:m+1;
			do{
				k--;
			}while(!is_postfix(k,P,q,sigma[i]));
			delta[q][sigma[i]-'a']=k;
		}
	}
	return delta;
}

int is_postfix(int k,char* P, int q, char ch){
	if(P[k]==ch){
		if(q==0){
			return 1;
		}
		int i;
		for(i=k-1;i>=1&&q>=1;i--){
			if(P[i]==P[q]){
				q--;
			}
			else{
				return 0;
			}
		}
		if(i==0){
			return 1;
		}

	}
	else{
		return 0;
	}
}
int main(){
	char *P="aababaca"; //P[0] is not used
	char *T="aabababacaba";//T[0] is not used
	
	char* sigma="abc";
	FINITE_AUTOMATON_MATCHER(T,P,sigma);
}
