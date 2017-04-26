void swap(int a[][2],int i,int b[][2],int j){
	int temp=0;
	temp=a[i][0];
	a[j][0]=b[j][0];
	b[j][0]=temp;
	temp=a[i][1];
	a[j][1]=b[j][1];
	b[j][1]=temp;
}
int partition(int a[][2],int p,int r){
	int x=a[r][0];
	int temp;
	int i=p-1;
	for(int j=p;j<=r-1;j++){
		if(a[j][0]<=x){
			i++;
			swap(a,i,a,j);
		}
	}
	swap(a,i+1,a,r);
	return i+1;
}
void quick_sort(int a[][2],int p,int r){
	if(p<r){
		int q=partition(a,p,r);
		quick_sort(a,p,q-1);
		quick_sort(a,q+1,r);
	}
}
int get_distance(int* a,int* b){
	return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
}
int longest_simple_path(int pos[][2],int n){

}
