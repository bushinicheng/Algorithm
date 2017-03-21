#include "find_maximum_subarry.h"
int main (){
	int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
	mystruct result;
	result=find_maximum_subarry(a,0,15);
	printf("%d  %d  %d",result.low,result.high,result.maxsum);
}