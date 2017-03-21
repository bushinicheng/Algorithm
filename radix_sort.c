#include <stdlib.h>
void radix_sort(int *a,int n){
	int *c=(int *)calloc(10,sizeof(int));
	int *b=(int *)calloc(n,sizeof(int));
	int max=0;
	for (int i=0;i<n;i++){
		max=max>a[i]?max:a[i];
	}
	int d;
	for(d=0;max!=0;d++){
		max/=10;
	}
	int k=1;
	max=0;
	for(int i=1;i<=d;i++){
		int temp=0;
		k*=10;
		for(int j=0;j<n;j++){

			temp=(a[j]%k)/(k/10);
			max=max>temp?max:temp;
			//printf("%d\t", temp);
			c[temp]++;
		}
		for(int w=1;w<=max;w++){
			c[w]=c[w]+c[w-1];
		}
		int temp1=0;
		for(int v=n-1;v>=0;v--){
			temp=(a[v]%k)/(k/10);
			temp1=c[temp]-1;
			b[temp1]=a[v];
			c[temp]--;
		}
		for(int z=0;z<n;z++){
			a[z]=b[z];
			b[z]=0;
		}
		for(int w=0;w<10;w++){
			c[w]=0;
		}
		temp=0;
		max=0;
		
	}
}