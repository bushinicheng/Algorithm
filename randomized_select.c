//返回第i小的元素
int randomized_select(int *a,int p,int r,int i){
	if(p==r){
		return a[p];
	}
	int q=randomized_partition(a,p,r);
	int k=q-p+1;
	if(i==k)
		return a[q];
	else if(i<k){
		return randomized_select(a,p,q-1,i);
	}
	else
		return randomized_select(a,q+1,r,i-k);
}