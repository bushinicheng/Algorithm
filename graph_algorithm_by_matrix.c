//from http://blog.csdn.net/yeruby/article/details/38615045
/*
6 10  
1 2 6  
1 3 1  
1 4 5  
2 3 5  
2 5 3  
3 4 5  
3 5 6  
3 6 4  
4 6 2  
5 6 6  
*/
#include<stdio.h>
#define MAX 100
#define MAXCOST 0x7fffffff

int graph[MAX][MAX];

int prim(int graph[][MAX], int n)
{
	int lowcost[MAX];//表示以i为终点的边的最小权值,当lowcost[i]=0说明以i为终点的边的最小权值=0
	int mst[MAX];//表示对应lowcost[i]的起点，即说明边<mst[i],i>是MST的一条边，当mst[i]=0表示起点i加入MST
	int i, j, min, minid, sum = 0;
	for (i = 2; i <= n; i++)
	{
		lowcost[i] = graph[1][i];//1 is the begin point and i is the final point
		mst[i] = 1;//initial point is 1
	}
	mst[1] = 0;
	for (i = 2; i <= n; i++)
	{
		min = MAXCOST;
		minid = 0; //min cross ver
		// find the min cross point 
		for (j = 2; j <= n; j++)
		{
			if (lowcost[j] < min && lowcost[j] != 0)
			{
				min = lowcost[j];
				minid = j;
			}
		}
		printf("V%d-V%d=%d\n",mst[minid],minid,min);
		sum += min;
		lowcost[minid] = 0;
		
		for (j = 2; j <= n; j++)
		{
			if (graph[minid][j] < lowcost[j])
			{
				lowcost[j] = graph[minid][j];
				mst[j] = minid;
			}
		}
	}
	return sum;
}

int main()
{
	int i, j, k, m, n;
	int x, y, cost;
	printf("%s\n", "input num of ver and edges");
	scanf(" %d",&m);
	scanf(" %d",&n);//m=顶点的个数，n=边的个数
	//初始化图G
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= m; j++)
		{
			graph[i][j] = MAXCOST;
		}
	}
	//构建图G
	for (k = 1; k <= n; k++)
	{
		scanf(" %d",&i);
		scanf(" %d",&j);
		scanf(" %d",&cost);
		graph[i][j] = cost;
		graph[j][i] = cost;
	}
	//求解最小生成树
	cost = prim(graph, m);
	//输出最小权值和
	printf("%s%d\n","最小权值和=",cost);
	getchar();
	return 0;
}