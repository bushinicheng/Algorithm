#include <limits.h>
#include <stdio.h>
static int heapsize;
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
int getparent(int i){
	if(i%2==0){
		return i/2-1;
	}
	else
		return i/2;
}
void min_heapify(int *a,int root){
	int l=left(root);
	int r=right(root);
	int min=root;
	int temp=0;
	if(l<heapsize&&a[root]>a[l]){
		min=l;
	}
	if(r<heapsize&&a[min]>a[r]){
		min=r;
	}
	if(min!=root){
		temp=a[root];
		a[root]=a[min];
		a[min]=temp;
		min_heapify(a,min);
	}
}
int heap_minimum(int *a){
	return a[0];
}
int heap_extract_min(int *a){
	if(heapsize<1){
		printf("%s\n", "underflow");
		return INT_MAX;
	}
	int min=a[0];
	a[0]=a[heapsize-1];
	heapsize--;
	min_heapify(a,0);
	return min;
}
void heap_decrease_key(int *a,int i,int key){
	if(key>a[i]){
		printf("%s\n", "new key is bigger than current key");
		return;
	}
	a[i]=key;
	while(i>=0){
		int parent=getparent(i);
		if(parent<0)
			break;
		if(a[i]<a[parent]){
			int temp=a[i];
			a[i]=a[parent];
			a[parent]=temp;
			i=parent;
		}
		else
			break;
	}
}
void min_heap_insert(int *a,int key,int n){
	if(heapsize+1>n){
		printf("%s\n", "overflow");
		return;
	}
	a[heapsize]==INT_MAX;
	heap_decrease_key(a,heapsize,key);
	heapsize++;
}
int heap_delete(int *a,int i){
	if(i>=heapsize){
		printf("%s\n", "error");
		return INT_MAX;
	}
	int deleted=a[i];
	for(int j=i;j<heapsize-1;j++){
		a[j]=a[j+1];
	}
	heapsize--;
}

int main (){
	int a[]={4,7,5,8,4,3,2,1};
	min_heap_insert(a,4,8);
	min_heap_insert(a,7,8);
	min_heap_insert(a,5,8);
	min_heap_insert(a,8,8);
	min_heap_insert(a,4,8);
	min_heap_insert(a,3,8);
	min_heap_insert(a,2,8);
	min_heap_insert(a,1,8);
	for(int i=0;i<8;i++)
	{
		printf(heap_extract_min(a));
	}
}