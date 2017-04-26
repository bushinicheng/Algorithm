//from http://blog.csdn.net/geekmanong/article/details/51056375
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b){
	if(a>b)
		return a;
	return b;
}
int longest_palindrome_by_dynm(char* str,int n){
	int dp[n][n];
	int temp;
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i][i]=1;
	}
	for(int i=1;i<n;i++){
		temp=0;
		for(int j=0;j+i<n;j++){
			if(str[j]==str[j+i])
				temp=dp[j+1][j+i-1]+2;
			else
				temp=max(dp[j+1][j+i],dp[j][j+i-1]);
			dp[j][j+i]=temp;
		}
		for(int k=0;k<n;k++){
			for(int m=0;m<n;m++){
				printf("%d ", dp[k][m]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return dp[0][n-1];
}
int main(int argc, char const *argv[])
{
	char *str="cabbeaf";
	int n=strlen(str);
	int len=longest_palindrome_by_dynm(str,n);
	printf("%d\n", len);
	return 0;
}