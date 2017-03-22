int **creat_list_by_array(int n){
	int **mylist=(int **)malloc(4*sizeof(int *));
	for (int i=0;i<3;i++){
		mylist[i]=(int *)malloc(n*sizeof(int));
	}
	mylist[3]=(int *)malloc(sizeof(int));
	mylist[3][0]=-1;
	return mylist;
}
int 