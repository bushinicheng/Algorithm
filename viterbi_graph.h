//from https://segmentfault.com/a/1190000008720143
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#ifndef _viterbi_graph_
#define _viterbi_graph_
#define MAXVEX 100
enum color{WHITE,GRAY,BLACK};
enum which_edge{NONE,TREE,BACK,FORWARD,CROSS};
typedef int status;
typedef char* VertexType;
typedef int EdgeType;
typedef struct  EdgeNode{
	int Edgestart;
	int Edgeend;//邻接点域，储存该顶点对应的下标
	EdgeType weight;

	int type;
	struct EdgeNode *next;
}EdgeNode;
typedef struct VertexNode{
	VertexType data;
	int color;
	int touch,finish;
	EdgeNode* FirstEdge;
	int parent;
}VertexNode,AdjList[MAXVEX];
typedef struct{
	AdjList adjList;
	int numNodes,numEdges;
}GraphAdjList;
void CreatALGraph(GraphAdjList *G){
	EdgeNode *e;
	printf("%s\n","Input the number of vertexes and edges: ");
	scanf("%d",&G->numNodes);
	scanf("%d",&G->numEdges);
	for(int i=0;i<G->numNodes;i++){
		printf("Input the %dth data (information) of vertexes",i+1);
		scanf("%s",G->adjList[i].data);
		G->adjList[i].FirstEdge=NULL;
		G->adjList[i].parent=-1;

		G->adjList[i].color=WHITE;
		G->adjList[i].touch=G->adjList[i].finish=-1;
	}
	int beg,end;
	for(int k=0;k<G->numEdges;k++){
		 printf("Input the serial number of edges (Vi,Vj) ");
		 printf("Input the vertex of beginning: ");
		 scanf("%d",&beg);
		 printf("Input the vertex of endding: ");
		 scanf("%d",&end);
		 e=(EdgeNode *)malloc(sizeof(EdgeNode));
		 e->Edgeend=end;
		 e->Edgestart=beg;
		 e->weight=0;
		 e->type=NONE;
		 e->next=G->adjList[beg].FirstEdge;
		 G->adjList[beg].FirstEdge=e;
	}
}
#endif