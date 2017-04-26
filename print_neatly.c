#include <stdio.h>
#define M 85//每行最多M个字符
#define N 49  //N个单词的输入序列
#define INFINITE (M*M*M) //定义无穷大为M的立方，各个lc永远无法取到该值 
int l[N+1]={4,2,4,7, 2, 6, 2, 2, 3, 11,4, 7, 9, 4, 2, 3, 10, 8, 2, 13,3, 7, 11, 4, 2, 5, 1, 7, 8, 13,13, 8, 12, 8, 7, 4, 6, 2, 3, 7, 11,3, 13, 3, 7, 2, 11, 10, 8};;//各个单词的字符数目 
int c[N+1];//问题的解
int r[N+1];//存放最优解，k值 
unsigned int lc[N+1][N+1];//lc[i][j]是第i个单词到第j个单词的额外空格符数量的立方 
void cal_lc(){//计算lc值 
	for(int i=1;i<=N;i++){
		for(int j=i;j<=N;j++){
			int words_length=0;
			for(int k=i;k<=j;k++){
				words_length+=l[k];
			}
			int extra=M-j+i- words_length;
			if(extra<0){
				lc[i][j]=INFINITE;
			}else if(j==N && extra>=0){
				lc[i][j]=0;
			}else{
				lc[i][j]=extra*extra*extra;
			}
		}
	}
}
int give_line(int j){
	int i=r[j],k;
	if(i==1){
		k=1;
	}else{
		k=give_line(i-1)+1;
	}
	printf("line Num\tstrat\tend\n");
	printf("%d\t%d\t%d\n",k,i,j);
	return k;
}
void print_neatly(){
	c[0]=0;
	cal_lc();
	for(int j=1;j<=N;j++){
		c[j]=c[0]+lc[1][j];
		r[j]=1;
		for(int k=1;k<=j;k++){
			int q=c[k-1]+lc[k][j];
			if(q<c[j]){
				c[j]=q;
				r[j]=k;
			}
		}
	}
}
int main(){
	print_neatly();
	give_line(N);
	printf("%s%d\n", "all lines other than the last line's extra spaces cubic is",c[N]);
	return 0;
}
