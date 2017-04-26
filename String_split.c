#include <stdio.h>
#include <string.h>
int main(){
	printf("%s\n","please input the length of the string: ");
	int n;
	scanf("%d",&n);
	printf("\n");
	printf("please input the 拆分点的个数与数目：");
	int m;
	scanf("%d",&m);
	printf("\n");
	int l[m+2];
	for(int i=1;i<=m;i++){
		scanf("%d",&l[i]);
	}
	l[0]=0;
	l[m+1]=n;
	int max_num=0x0fffffff;
	int s[m+2][m+2];
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=m+1;j++){
			s[i][j]=0;
		}
	}
	for(int j=0;j<=m;j++){
		s[l[j]][l[j+1]]=0;
	}
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=m+1;j++){
			printf("%d\t",s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int k=2;k<=m+1;k++){
		int q=m+1-k;
		for(int x=0;x<=q;x++){
			max_num=0x0fffffff;
			for(int y=1;y<k;y++){
				int temp=s[l[x]][l[x+y]]+s[l[x+y]][l[x+k]]+l[x+k]-l[x];
				if(temp<max_num){
					s[l[x]][l[x+k]]=temp;
					max_num=temp;
				}
			}
		}
		for(int i=0;i<=m+1;i++){
			for(int j=0;j<=m+1;j++){
				printf("%d\t",s[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("%s: %d\n", "the answer is",s[0][l[m+1]]);
}
