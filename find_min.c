#include <limits.h>
int find_min(int *a,int n){
	int min=INT_MAX;
	for(int i=0;i<n;i++){
		min=min<a[i]?min:a[i];
	}
	return min;
}