#include <stdio.h>
int main (){
	int a[]={4,1,5,8,4,3,9,0,10,67};
	count_sort(a,10);
	for(int i=0;i<10;i++)
	{
		printf("%d\t",a[i]);
	}
}