#include <stdlib.h>
void count_sort(int *a,int n){
	int max=0;
	for(int i=0;i<n;i++){
		max=max>a[i]?max:a[i];
	}
	//n is the length of a
	max++;
	int *c=(int *)calloc(max,sizeof(int));
	int *b=(int *)calloc(n,sizeof(int));
	int temp=0;
	for(int i=0;i<n;i++){
		temp=a[i];
		c[temp]++;
	}
	for(int j=1;j<max;j++){
		c[j]=c[j]+c[j-1];
	}
	int temp1=0;
	for(int w=n-1;w>=0;w--){
		temp=a[w];
		temp1=c[temp]-1;
		b[temp1]=a[w];
		c[temp]--;
	}

	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
}