#include <stdio.h>
int main (){
	int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	int min=0;
	min=find_min(a,16);
	printf("%d",min);
}