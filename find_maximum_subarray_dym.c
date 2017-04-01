#include <stdio.h>
typedef struct MaxSum{
	int start;
	int end;
	int sum;
}maxsum;
/*设sum[i]为以第i个元素结尾且和最大的连续子数组。假设对于元素i，
所有以它前面的元素结尾的子数组的长度都已经求得，
那么以第i个元素结尾且和最大的连续子数组实际上，
要么是以第i-1个元素结尾且和最大的连续子数组加上这个元素，
要么是只包含第i个元素，即sum[i] = max(sum[i-1] + a[i], a[i])。
可以通过判断sum[i-1] + a[i]是否大于a[i]来做选择，
而这实际上等价于判断sum[i-1]是否大于0。由于每次运算只需要前一次的结果，
因此并不需要像普通的动态规划那样保留之前所有的计算结果，只需要保留上一次的即可，
因此算法的时间和空间复杂度都很小。
*/
maxsum find_maximum_subarray_dym(int *a,int n){
	maxsum mysum={0,0,0};
	maxsum presum={0,0,0};
	mysum.sum=a[0];
	presum.sum=a[0];
	for(int i=1;i<n;i++){
		if(presum.sum>0){
			presum.sum+=a[i];
			presum.end=i;
		}
		else{
			presum.sum=a[i];
			presum.start=i;
		}
		if(presum.sum>mysum.sum){
			mysum.sum=presum.sum;
			mysum.start=presum.start;
			mysum.end=presum.end;
		}
	}
	printf("maxsum:%d\n",mysum.sum);
    printf("start:%d\n",mysum.start);
    printf("end:%d\n",mysum.end);
    return mysum;
}