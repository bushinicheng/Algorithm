#include "find_maximum_subarry.h"
mystruct find_max_crossing_subarray(int *a,int low,int mid, int high){
	int leftsum= INT_MIN;
	int rightsum =INT_MIN;
	int maxleft=0,maxright=0;
	int sum=0;
	for(int i=mid;i>=low;i--){
		sum+=a[i];
		if(sum>leftsum){
			leftsum=sum;
			maxleft=i;
		}
	}
	sum=0;
	for(int i=mid+1;i<=high;i++){
		sum+=a[i];
		if(sum>rightsum){
			rightsum=sum;
			maxright=i;
		}
	}
        mystruct crossresult={maxleft,maxright,leftsum+rightsum};
        return crossresult;
}
mystruct find_maximum_subarry(int *a,int low,int high){
	if(low>=high){
            mystruct temp={low,high,a[low]};
            return temp;
	}
        mystruct left;
        mystruct right;
        mystruct cross;
	
	int mid=(low+high)/2;
	left=find_maximum_subarry(a,low,mid);
        right=find_maximum_subarry(a,mid+1,high);
	cross=find_max_crossing_subarray(a,low,mid,high);
	
	if(left.maxsum>right.maxsum&&left.maxsum>cross.maxsum){
            return left;
	}
	else if(right.maxsum>left.maxsum&&right.maxsum>cross.maxsum){
            return right;
	}
	else
            return cross;
		
}