//from http://blog.sina.com.cn/s/blog_77dc9e0801017vkr.html
/*
Sample Input:
n: 员工个数, 接下一行输入每个员工对这次party的喜欢程度.
接下的n行内, 每行输入u:员工编号, num: 该员工下属的个数, vi: 该员工的第i个下属的编号(0<=i<n)
 
Sample Output:
      输出最大的喜欢程度和.
 
Sample Input:
5
2 3 5 4 4
0 2 2 3
2 1 1
1 1 4
3 0
4 0
6
20 3 5 4 5 30
0 2 2 3
2 1 1
3 1 4
1 0
4 1 5
5 0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 105
int n;
int g[MAX][MAX];//保存员工树状关系
int a[MAX];//对party的喜欢程度
int root;//无上司的人 (boss)
int take_party[MAX][2];//take_party[i][0] i don't take
int max(int a,int b){
	return a>b?a:b;
}
void read_tree(){
	int i,j;
	memset(g,0,sizeof(g));
	memset(take_party,-1,sizeof(take_party));
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int u,v;
	int num;
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&num);//每个人得编号和下属个数
		for(j=0;j<num;j++){
			scanf("%d",&v);
			g[u][v]=1;
		}
	}
	root=0;
}
int get_max_score(int node,int state){//当前节点node, state: 是否参加party
	if(take_party[node][state]!=-1)
		return take_party[node][state];
	int ans;
	if(state==0){
		ans=0;
		for(int i=0;i<n;i++){
			if(g[node][i]){
				ans+=max(get_max_score(i,0),get_max_score(i,1));
			}
		}
		take_party[node][state]=ans;
		return ans;
	}
	else{
		ans=a[node];
		for(int i=0;i<n;i++){
			if(g[node][i]){
				ans+=get_max_score(i,0);
			}
		}
		take_party[node][state]=ans;
		return ans;
	}
}
int main(){
	while(scanf("%d",&n)!=EOF){
		read_tree();
		int result=get_max_score(root,0);
		memset(take_party,-1,sizeof(take_party));
		result = max(result,get_max_score(root,1));
		printf("%d\n", result);
	}
	return 0;
}