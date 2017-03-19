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
void quick_sort(int *a,int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
