#include <stdio.h>
int main (){
	int a[]={10,23,34,21,42,12,34,65};
	merge_sort_rc(a,0,7);
	for(int i=0;i<8;i++)
	{
		printf("%d\t",a[i]);
	}
}