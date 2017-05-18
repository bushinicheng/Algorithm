//from http://www.voidcn.com/blog/huanghanqian/article/p-6052935.html
#include <iostream>
#include <cstring> 
#include <queue>
using namespace std;
#define N 201
#define MaxInt 0x3f3f3f3f
int n,m,sum,s,t; //s is source and t is dest,m is the num of node
int flow[N][N],cap[N][N],a[N],p[N];
//分别为：flow[u][v]为<u,v>流量、cap[u][v]为<u,v>容量、a[i]表示源点s到节点i的路径上的最小残留量、p[i]记录i的前驱
int min(int a,int b){
	return a>b?b:a;
}
void Edmonds_Karp(){
	int i,u,v;
	queue<int> q;
	while(1){
		memset(a,0,sizeof(a));
		a[s]=MaxInt;
		q.push(s);
		while(!q.empty()){
			u=q.front();
			q.pop();
			for(v=1;v<=m;v++){
				if(!a[v]&&flow[u][v]<cap[u][v]){
					p[v]=u;
					q.push(v);
					a[v]=min(a[u],cap[u][v]-flow[u][v]);
				}
				
			}
		}
		if(a[m]==0){
			break;
		}
		sum+=a[m];
		for(i=m;i!=s;i=p[i]){
			flow[p[i]][i]+=a[m];
			flow[i][p[i]]-=a[m];
		}
	}
	cout<<sum<<endl;
}
int main (){
	int v,u,w;
	while(cin>>n){
		cin>>m;
		s=1;
		t=m;
		sum=0;
		memset(flow,0,sizeof(flow));
		memset(cap,0,sizeof(cap));
		for(int i=0;i<n;i++){
			cin>>u>>v>>w;
			cap[u][v]+=w;
		}
		Edmonds_Karp();
	}
	return 0;
}