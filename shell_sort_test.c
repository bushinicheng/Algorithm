#include <stdio.h>
int main (){
	int a[]={10,23,34,21,42,12,34,65};
	shell_sort(a,8);
	for(int i=0;i<8;i++)
	{
		printf("%d\t",a[i]);
	}
}