int heapsize;
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}
int parent(int i){
	return i/2;
}
void max_heapify(int *a,int root){
	int l=left(root);
	int r=right(root);
	int largest=root;
	int temp=0;
	if(l<heapsize&&a[root]<a[l]){
		largest=l;
	}
	if(r<heapsize&&a[largest]<a[r]){
		largest=r;
	}
	if(largest!=root){
		temp=a[root];
		a[root]=a[largest];
		a[largest]=temp;
		max_heapify(a,largest);
	}
}
void build_max_heap(int *a,int n){
	heapsize=n;
	for(int i=n/2;i>=0;i--){
		max_heapify(a,i);
	}
}
void heap_sort(int *a,int n){
	build_max_heap(a,n);
	heapsize=n;
	int temp=0;
	for(int i=n-1;i>0;i--){
		temp=a[i];
		a[i]=a[0];
		a[0]=temp;
		heapsize--;
		max_heapify(a,0);
	}
}
