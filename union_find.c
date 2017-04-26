//from http://www.xlgps.com/article/118473.html
#include <stdio.h>
#define N 100
int id[N];
int rank[N];// 节点高度的上界 
/*void init(){
    int i;
    for(i=0;i<N;i++)
        id[i]=-1;
}
*/
/*void Union(int x,int y){
    int rx=find_root(x);
    int ry=find_root(y);
    if(rx==ry)
        return;
    id[ry]=rx;
}*/


/*(1).路径压缩
刚才我们说过，寻找祖先时采用递归，但是一旦元素一多起来，或退化成一条链，每次GetFather都将会使用O（n）的复杂度，这显然不是我们想要的。
对此，我们必须要进行路径压缩，即我们找到最久远的祖先时“顺便”把它的子孙直接连接到它上面,这就是路径压缩了。

數據結構與算法分析 &ndash; Disjoint Set（並查集）
*/


 int find_root(int x){
     if(id[x]==-1)
         return x;    
     else
         id[x]=find_root(id[x]);
     return id[x];
 }
 int judge(int x, int y)
{
    return find_root(x) == find_root(y);
}
/*(2).rank合并
1.按照树的高度合并。
*/

//int rank[N]={0};// 节点高度的上界 
 
void Union(int x, int y)
{
    int rx=find_root(x);
    int ry=find_root(y);
    if(rx==ry){
    	return;
    }
    else if (rank[rx] > rank[ry])
        id[ry] = rx;
   	else {
        id[rx] = ry;
        if (rank[rx] == rank[ry])
            rank[ry]++;
    }
}
/*2.按照集合的大小合并*/

//int rank[N];// 集合的大小
 
void init(){
	for(int i=0;i<N;i++){
	    id[i]=-1;
	    rank[i]=1;
	}
}

/*void Union(int x, int y)
{
    int rx=find_root(x);
    int ry=find_root(y);
    if (rank[rx] > rank[ry]){
        rank[rx]+=rank[ry];
        id[ry] = rx;
    }
   else {
        rank[ry]+=rank[rx];
        id[rx] = ry;
    }
}
*/
int main(){
	int i;
	init();
	for(i=0;i<10;i++){
		Union(0,i);
	}
	find_root(9);
	for(i=0;i<10;i++){
		printf("%d ", id[i]);
	}
	return 0;
}