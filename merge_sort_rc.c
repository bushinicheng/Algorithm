#include <stdlib.h>
void merge(int *a, int p, int q, int r){
	int n=r-p+1;
	int *temp=(int *)malloc(n*sizeof(int));
	int i1=p,i2=q+1;
	int k=0;
	while(k<n&&i1<q+1&&i2<r+1){
		if(a[i1]<a[i2]){
			temp[k++]=a[i1++];
		}
		else{
			temp[k++]=a[i2++];
		}
	}
	while(i1<q+1){
		temp[k++]=a[i1++];
	}
	while(i2<r+1){
		temp[k++]=a[i2++];
	}
	for(int i=0;i<k;i++){
		a[p+i]=temp[i];
	}
	free(temp);
}
void merge_sort_rc(int *a,int m,int n){
	if(m<n){
		int mid=(m+n)/2;
		merge_sort_rc(a,m,mid);
		merge_sort_rc(a,mid+1,n);
		merge(a,m,mid,n+1);
	}
}