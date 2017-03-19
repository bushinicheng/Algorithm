/*
a is an array and n is the length
*/
void insert_sort(int*a,int n){
	int key=0;
	int j=0;
	for(int i=1;i<n;i++){
		j=i-1;
		key=a[i];
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}	
}