#include <stdio.h>
typedef struct MaxSum{
	int start;
	int end;
	int sum;
}maxsum;
maxsum find_maximum_subarray_linear(int *a,int n){
	//当我们加上一个正数时，和会增加；当我们加上一个负数时，和会减少。如果当前得到的和是个负数，那么这个和在接下来的累加中应该抛弃并重新清零，不然的话这个负数将会减少接下来的和
	maxsum mysum={0,0,0};
	maxsum cursum={0,0,0};
    for(int i=0;i<n;i++)  
    {  
        cursum.sum += a[i];
        cursum.end=i;
        if(cursum.sum > mysum.sum){
            mysum.sum = cursum.sum;
            mysum.start=cursum.start;
            mysum.end=cursum.end;
        }  
        if(cursum.sum < 0){
            cursum.sum = 0;
            cursum.start=cursum.end+1;
        }  
    }  
    printf("maxsum:%d\n",mysum.sum);
    printf("start:%d\n",mysum.start);
    printf("end:%d\n",mysum.end);
    return mysum;
}