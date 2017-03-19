#include <stdio.h>
int main (){
	int a[]={8,7,6,5,4,3,2,1};
	heap_sort(a,8);
	for(int i=0;i<8;i++)
	{
		printf("%d\t",a[i]);
	}
}