#include <stdio.h>
int main (){
	float a[]={0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
	bucket_sort(a,10);
	for(int i=0;i<10;i++)
	{
		printf("%f\t",a[i]);
	}
}