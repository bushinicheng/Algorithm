#include <stdlib.h>
int randomized_partition(int *a,int p,int r){
	int i=(rand() % (r-p+1))+ p;
	int temp=a[r];
	a[r]=a[i];
	a[i]=temp;
	return partition(a,p,r);
}
int partition(int *a,int p,int r){
	int x=a[r];
	int temp;
	int i=p-1;
	for(int j=p;j<=r-1;j++){
		if(a[j]<=x){
			i++;
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}