#include <stdlib.h>
typedef struct Linkedlist{
	struct Linkedlist* next;
	float val;
}bucket;
void bucket_sort(float *a,int n){
	int bucketnum=n;
	bucket **bucketarray=(bucket**)calloc(n,sizeof(bucket*));
	for(int j=0;j<n;j++){
		bucketarray[j]=NULL;
	}
	int temp=0;
	for(int i=0;i<n;i++){
		temp=(int)(n*a[i]);
		bucket *p=NULL;
		bucket *pre=NULL;
		bucket *head=NULL;
		pre=p=bucketarray[temp];
		if(bucketarray[temp]==NULL){
			bucketarray[temp]=(bucket*)calloc(1,sizeof(bucket));
			bucketarray[temp]->next=NULL;
			bucketarray[temp]->val=a[i];
		}
		else{
			while(1){
				if(a[i]>p->val){
					if(p->next!=NULL){
						pre=p;
						p=p->next;
					}
					else{
						p->next=(bucket*)calloc(1,sizeof(bucket));
						p=p->next;
						p->val=a[i];
						p->next=NULL;
						break;
					}
				}
				else{
					if(p==bucketarray[temp]){
						pre=bucketarray[temp]=(bucket*)calloc(1,sizeof(bucket));
						bucketarray[temp]->val=a[i];
						bucketarray[temp]->next=p;
					}
					else{
						pre->next=(bucket*)calloc(1,sizeof(bucket));
						pre=pre->next;
						pre->val=a[i];
						pre->next=p;  
					}
					break;
				}
			}
		}
	}
	int k=0;
	for(int i=0;i<n;i++){
		if(bucketarray[i]!=NULL){
			bucket *p=bucketarray[i];
			while(p!=NULL){
				a[k++]=p->val;
				p=p->next;
			}
		}
	}
	
}