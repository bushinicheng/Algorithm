#include <stdio.h>
#include <stdlib.h>
#define MAXVEX 100
typedef int EdgeWeight;
typedef int VertexData;
typedef enum Color{WHITE,GRAY,BLACK}Color;
typedef enum EdgeType{NONE,TREE,BACK,FORWARD,CROSS}EdgeType;
typedef struct Edge{
	int edge_start;
	int edge_end;
	EdgeWeight edge_weight;
	EdgeType edge_type;
	struct Edge* next;
}Edge;
typedef struct Vertex{
	VertexData data;
	Color color;
	int touch;
	int finish;
	Edge* edge;
}Vertex;
typedef Vertex* AdjList;
typedef struct Graph_By_AdjList
{
	AdjList adjList;
	int num_nodes;
	int num_edges;
}Graph;
void creat_graph(Graph *graph){
	printf("%s\n","Input the number of vertexes");
	scanf("%d",&graph->num_nodes);
	AdjList adjList=(AdjList)malloc((graph->num_nodes+1)*sizeof(Vertex));
	graph->adjList=adjList;
	printf("\n");
	printf("%s\n","Input the number of edges");
	scanf("%d",&graph->num_edges);
	printf("\n");
	for(int i=0;i<graph->num_nodes;i++){
		printf("Input the %dth data (information) of vertexes\n",i+1);
		scanf("%d",&(graph->adjList[i].data));
		printf("\n");
		graph->adjList[i].color=WHITE;
		graph->adjList[i].touch=-1;
		graph->adjList[i].finish=-1;
		graph->adjList[i].edge=NULL;
	}
	int start=0;
	int end=0;
	int weight;
	Edge* edge;
	for(int i=0;i<graph->num_edges;i++){
		printf("Input the serial number of edges (Vi,Vj)\n");
		scanf("%d,%d",&start,&end);
		printf("\n");
		printf("input the weight of this edge\nweight: ");
		scanf("%d",&weight);
		printf("\n");
		edge=(Edge*)malloc(sizeof(Edge));
		edge->edge_start=start-1;
		edge->edge_end=end-1;
		edge->edge_weight=weight;
		edge->edge_type=NONE;
		Edge *p,*pre;;
		pre=p=graph->adjList[start-1].edge;
		if(graph->adjList[start-1].edge==NULL){
			graph->adjList[start-1].edge=edge;
			edge->next=NULL;
		}
		else{
			while(p!=NULL){
				pre=p;
				p=p->next;
			}
			pre->next=edge;
			edge->next=NULL;
		}
	}
}
void print_graph(Graph* graph){
	for(int i=0;i<graph->num_nodes;i++){
		Edge*p=graph->adjList[i].edge;
		while(p!=NULL){
			printf("(%d,%d)\t",p->edge_start+1,p->edge_end+1);
			p=p->next;
		}
		printf("\n");
	}
}
int main()
{
	Graph mygraph;
	creat_graph(&mygraph);
	print_graph(&mygraph);
	return 0;
}
