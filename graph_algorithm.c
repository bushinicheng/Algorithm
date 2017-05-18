/*
8
14
a,b
b,e
e,a
b,f
e,f
f,g
g,f
b,c
c,d
d,c
g,c
g,h
d,h
h,h
*/
/*
a,b
b,a
a,c
c,a
b,c
c,b
b,d
d,b
e,g
g,e
e,f
f,e
h,i
i,h

*/
/*
a,b
4
b,a
4
a,h
8
h,a
8
b,h
11
h,b
11
b,c
8
c,b
8
i,c
2
c,i
2
h,i
7
i,h
7
h,g
1
g,h
1
i,g
6
g,i
6
g,f
2
f,g
2
c,d
7
d,c
7
c,f
4
f,c
4
d,f
14
f,d
14
d,e
9
e,d
9
f,e
10
e,f
10

*/
/*
5
10
a,b
6
a,d
7
b,c
5
c,b
-2
b,d
8
d,e
9
e,a
2
d,c
-3
b,e
-4
e,c
7
*/
/*
a,b
5
b,c
2
c,d
7
d,e
-1
e,f
-2
b,d
6
d,f
1
a,c
3
c,e
4
c,f
2
*/
/*
5
10
a,b
10
a,d
5
b,d
2
d,b
3
b,c
1
d,e
2
c,e
4
e,c
6
d,c
9
e,a
7
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFINITE 100000
#define MAXVEXDATA 100
#define NIL -1

typedef int EdgeWeight;
typedef char VertexData;
typedef enum Color{WHITE,GRAY,BLACK}Color;
typedef enum EdgeType{NONE,TREE,BACK,FORWARD,CROSS}EdgeType;
typedef struct UNION_FIND_TREE{
	VertexData data;
	struct UNION_FIND_TREE* parent;
	int rank;
}union_find_tree;

typedef struct Queue{
	int * a;
	int tail;
	int head;
	int n;
}Queue;
typedef struct Edge{
	int edge_start;
	int edge_end;
	EdgeWeight edge_weight;
	EdgeType edge_type;
	struct Edge* next;
}Edge;
typedef struct Vertex{
	VertexData data;
	int distance;
	int parent;
	int key;
	Color color;
	int touch;
	int finish;
	Edge* edge;
}Vertex;
typedef Vertex* AdjList;

typedef struct Graph_By_AdjList
{
	AdjList adjList;
	Vertex* topological_sort;
	int num_nodes;
	int num_edges;
}Graph;

Queue * creat_queue(int n);
int enqueue(Queue *myqueue,int x);
int dequeue(Queue *myqueue);
int queue_is_empty(Queue* queue);
void creat_graph(Graph *graph);
void print_graph(Graph* graph);
void BFS(Graph* graph,int s);
void DFS_VISIT(Graph *graph,int u,int* time,int *index_topsort);
void DFS(Graph* graph);
void DFS_FIN_DEC(Graph *graph,Graph *graph_t);
void print_path(Graph* graph,char s,char v);
void print_time_label(Graph*graph);
void print_edge_type(Graph *graph);
void print_topological_sort(Graph *graph);
Graph* creat_graph_t(Graph *graph);
void strongly_connected_components(Graph *graph);
void connected_components_by_union_find(Graph *graph);
union_find_tree* make_set(VertexData data);
union_find_tree* find_set(union_find_tree* x);
void union_set(union_find_tree* x,union_find_tree * y);
void link_set(union_find_tree* x,union_find_tree* y);
Edge** MST_KRUSKAL(Graph *graph);
void insert_edge_by_weight(Edge **a,int n);
int extract_min(Vertex **queue,int n);
int belong_queue(Vertex **queue,Vertex node,int n);
Edge **MST_PRIME(Graph *graph);

Queue * creat_queue(int n){
	Queue *myqueue=(Queue*)malloc(sizeof(Queue));
	myqueue->a=(int *)malloc(n*sizeof(int));
	myqueue->head=-1;
	myqueue->tail=-1;
	myqueue->n=n;
	return myqueue;
}
int enqueue(Queue *myqueue,int x){
	int temp=0;
	if(myqueue->head==-1){
		myqueue->head=myqueue->tail=0;
		myqueue->a[temp]=x;
	}
	else{
		myqueue->tail=myqueue->tail%myqueue->n+1;
		if(myqueue->tail!=myqueue->head-1){
			temp=myqueue->tail;
			myqueue->a[temp]=x;
		}
	}
	return x;
}
int dequeue(Queue *myqueue){
	if(myqueue->tail==myqueue->head){
		int temp=myqueue->head;
		myqueue->head=myqueue->tail=-1;
		return myqueue->a[temp];
	}
	else{
		int temp=0;
		temp=myqueue->head;
		myqueue->head=myqueue->head+1;
		return myqueue->a[temp];
	}
}
int queue_is_empty(Queue* queue){
	if(queue->head==-1)
		return 1;
	return 0;
}
void creat_graph(Graph *graph){
	printf("%s\n","Input the number of vertexes");
	scanf("%d",&graph->num_nodes);
	AdjList adjList=(AdjList)malloc((graph->num_nodes+1)*sizeof(Vertex));
	graph->topological_sort=(Vertex*)malloc((graph->num_nodes+1)*sizeof(Vertex));
	graph->adjList=adjList;
	printf("\n");
	printf("%s\n","Input the number of edges");
	scanf("%d",&graph->num_edges);
	//printf("\n");
	for(int i=0;i<graph->num_nodes;i++){
		//printf("Input the %dth data (information) of vertexes\n",i+1);
		//scanf(" %c",&(graph->adjList[i].data));
		graph->adjList[i].data='a'+i;
		//printf("\n");
		graph->adjList[i].color=WHITE;
		graph->adjList[i].touch=-1;
		graph->adjList[i].finish=-1;
		graph->adjList[i].edge=NULL;
		graph->adjList[i].parent=NIL;
		graph->adjList[i].distance=INFINITE;
	}
	int start=0;
	int end=0;
	char start_data;
	char end_data;
	int weight;
	Edge* edge;
	for(int i=0;i<graph->num_edges;i++){
		//printf("Input the serial number of edges (Vi,Vj)\n");
		scanf(" %c,%c",&start_data,&end_data);
		start=start_data-'a';
		end=end_data-'a';
		//printf("\n");
		//printf("input the weight of this edge\nweight: ");
		scanf("%d",&weight);
		//weight=0;
		printf("\n");
		edge=(Edge*)malloc(sizeof(Edge));
		edge->edge_start=start;
		edge->edge_end=end;
		edge->edge_weight=weight;
		edge->edge_type=NONE;
		Edge *p,*pre;;
		pre=p=graph->adjList[start].edge;
		if(graph->adjList[start].edge==NULL){
			graph->adjList[start].edge=edge;
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
			printf("(%c,%c)\t",graph->adjList[p->edge_start].data,graph->adjList[p->edge_end].data);
			p=p->next;
		}
		printf("\n");
	}
}
void BFS(Graph* graph,int s){
	s--;
	for(int i=0;i<graph->num_nodes;i++){
		if(i!=s){
			graph->adjList[i].color=WHITE;
			graph->adjList[i].distance=INFINITE;
			graph->adjList[i].parent=NIL;
		}
	}
	graph->adjList[s].color=GRAY;
	graph->adjList[s].distance=0;
	graph->adjList[s].parent=NIL;
	Queue* queue=creat_queue(graph->num_nodes);
	enqueue(queue,s);
	while(!queue_is_empty(queue)){
		int u=dequeue(queue);
		Edge*p=graph->adjList[u].edge;
		while(p!=NULL){
			int v=p->edge_end;
			if(graph->adjList[v].color==WHITE){
				graph->adjList[v].color=GRAY;
				graph->adjList[v].distance=graph->adjList[u].distance+1;
				graph->adjList[v].parent=u;
				enqueue(queue,v);
			}
			p=p->next;
		}
		graph->adjList[u].color=BLACK;
	}
}
void DFS_VISIT(Graph *graph,int u,int* time,int *index_topsort){
	(*time)++;
	graph->adjList[u].touch=*time;
	graph->adjList[u].color=GRAY;
	Edge *p=graph->adjList[u].edge;
	while(p!=NULL){
		int v=p->edge_end;
		if(graph->adjList[v].color==WHITE){
			p->edge_type=TREE;
			graph->adjList[v].parent=u;
			DFS_VISIT(graph,v,time,index_topsort);
		}
		else if(graph->adjList[v].color==GRAY){
			p->edge_type=BACK;
		}
		else{
			if(graph->adjList[u].touch>graph->adjList[v].touch){
				p->edge_type=FORWARD;
			}
			else{
				p->edge_type=CROSS;
			}
		}
		p=p->next;
	}
	graph->adjList[u].color=BLACK;
	//static int index_topsort=0;
	graph->topological_sort[*index_topsort]=graph->adjList[u];
	(*index_topsort)++;
	(*time)++;
	graph->adjList[u].finish=*time;
}
void DFS(Graph* graph){
	for(int i=0;i<graph->num_nodes;i++){
		graph->adjList[i].color=WHITE;
		graph->adjList[i].parent=NIL;
	}
	int time=0;
	int index_topsort=0;
	for(int i=0;i<graph->num_nodes;i++){
		if(graph->adjList[i].color==WHITE){
			DFS_VISIT(graph,i,&time,&index_topsort);
		}
	}
}
void DFS_FIN_DEC(Graph *graph,Graph *graph_t){
	for(int i=0;i<graph_t->num_nodes;i++){
		graph_t->adjList[i].color=WHITE;
		graph_t->adjList[i].parent=NIL;
	}
	int time=0;
	int index_topsort=0;
	for(int i=0;i<graph_t->num_nodes;i++){
		int u=graph->num_nodes-(graph->topological_sort[i].data-'a')-1;
		if(graph_t->adjList[u].color==WHITE){
			printf("%s: %c\n", "representation of strongly_connected_components",graph_t->adjList[u].data);
			DFS_VISIT(graph_t,u,&time,&index_topsort);
		}
	}
	/*for(int i=0;i<graph_t->num_nodes;i++){
		if(graph_t->adjList[i].color==WHITE){
			graph_t->adjList[i].color=BLACK;
			printf("%s: %c\n", "representation of strongly_connected_components",graph_t->adjList[i].data);
		}
	}
	*/
}
void print_path(Graph* graph,char s,char v){
	if(v==s){
		printf("->%c",s);
	}
	else if(graph->adjList[v-'a'].parent==NIL){
		printf("%s\n", "no such path");
	}
	else{
		int parent=graph->adjList[v-'a'].parent;
		print_path(graph,s,graph->adjList[parent].data);
		printf("->%c",v);
	}
}
void print_time_label(Graph*graph){
	for(int i=0;i<graph->num_nodes;i++){
		printf("node%d: (%d,%d)\t", i,graph->adjList[i].touch,graph->adjList[i].finish);
	}
}
void print_edge_type(Graph *graph){
	
}
void print_topological_sort(Graph *graph){
	for(int i=graph->num_nodes-1;i>=0;i--){
		printf("%c", graph->topological_sort[i].data);
	}
	printf("\n");
}
Graph* creat_graph_t(Graph *graph){
	Graph *graph_t=(Graph *)malloc(sizeof(Graph)); 
	graph_t->adjList=(AdjList)malloc((graph->num_nodes+1)*sizeof(Vertex));
	graph_t->topological_sort=(Vertex*)malloc((graph->num_nodes+1)*sizeof(Vertex));
	graph_t->num_nodes=graph->num_nodes;
	graph_t->num_edges=graph->num_edges;
	for(int i=0;i<graph->num_nodes;i++){
		graph_t->adjList[i].data=graph->adjList[i].data;
		graph_t->adjList[i].touch=-1;
		graph_t->adjList[i].finish=-1;
		graph_t->adjList[i]=graph->adjList[i];
		graph_t->adjList[i].distance=INFINITE;
		graph_t->adjList[i].color=WHITE;
		graph_t->adjList[i].parent=NIL;
		graph_t->adjList[i].edge=NULL;
	}
	Edge *p,*p1,*p2,*pre;
	for(int i=0;i<graph->num_nodes;i++){
		p1=graph->adjList[i].edge;
		while(p1!=NULL){
			p2=(Edge*)malloc(sizeof(Edge));
			p2->edge_start=p1->edge_end;
			p2->edge_end=p1->edge_start;
			p2->next=NULL;
			pre=p=graph_t->adjList[p2->edge_start].edge;
			if(graph_t->adjList[p2->edge_start].edge==NULL){
				graph_t->adjList[p2->edge_start].edge=p2;
				p2->next=NULL;
			}
			else{
				while(p!=NULL){
					pre=p;
					p=p->next;
				}
				pre->next=p2;
				p2->next=NULL;
			}
			p1=p1->next;
		}
	}
	return graph_t;
}
void strongly_connected_components(Graph *graph){
	DFS(graph);
	Graph* graph_t=creat_graph_t(graph);
	DFS_FIN_DEC(graph,graph_t);
}


void connected_components_by_union_find(Graph *graph){
	union_find_tree** union_find=(union_find_tree**)malloc(graph->num_nodes*sizeof(union_find_tree*));
	for(int i=0;i<graph->num_nodes;i++){
		Vertex v=graph->adjList[i];
		union_find[i]=make_set(v.data);
	}
	Edge *p;
	for(int i=0;i<graph->num_nodes;i++){
		p=graph->adjList[i].edge;
		while(p!=NULL){
			int u=p->edge_end;
			int x=graph->adjList[i].data-'a';
			int y=graph->adjList[u].data-'a';
			if(find_set(union_find[x])!=find_set(union_find[y])){
				union_set(union_find[x],union_find[y]);
			}
			p=p->next;
		}
	}
	for(int i=0;i<graph->num_nodes;i++){
		printf("%c\n",union_find[i]->parent->data);
	}
}

union_find_tree* make_set(VertexData data){
	union_find_tree* ele_set=(union_find_tree*)malloc(sizeof(union_find_tree));
	ele_set->data=data;
	ele_set->parent=ele_set;
	ele_set->rank=0;
	return ele_set;
}
union_find_tree* find_set(union_find_tree* x){
	if(x!=x->parent){
		x->parent=find_set(x->parent);
	}
	return x->parent;
}
void union_set(union_find_tree* x,union_find_tree * y){
	link_set(find_set(x),find_set(y));
}
void link_set(union_find_tree* x,union_find_tree* y){
	if(x->rank>y->rank){
		y->parent=x;
	}
	else{
		x->parent=y;
		if(x->rank==y->rank){
			y->rank++;
		}
	}
}
Edge** MST_KRUSKAL(Graph *graph){
	Edge *sorted_by_weight_edge[graph->num_edges];
	Edge **mst=(Edge**)malloc(graph->num_edges*sizeof(Edge*));
	for(int i=0;i<graph->num_edges;i++){
		mst[i]=NULL;
	}
	int mst_count=0;
	Edge *p;
	int j=0;
	union_find_tree** union_find=(union_find_tree**)malloc(graph->num_nodes*sizeof(union_find_tree*));
	for(int i=0;i<graph->num_nodes;i++){
		Vertex v=graph->adjList[i];
		union_find[i]=make_set(v.data);
	}
	for(int i=0;i<graph->num_nodes;i++){
		p=graph->adjList[i].edge;
		while(p!=NULL){
			sorted_by_weight_edge[j++]=p;
			p=p->next;
		}
	}
	insert_edge_by_weight(sorted_by_weight_edge,graph->num_edges);
	for(int i=0;i<graph->num_edges;i++){
		int u=sorted_by_weight_edge[i]->edge_start;
		int v=sorted_by_weight_edge[i]->edge_end;
		if(find_set(union_find[u])!=find_set(union_find[v])){
			mst[mst_count++]=sorted_by_weight_edge[i];
			union_set(union_find[u],union_find[v]);
		}
	}
	for(int i=0;i<mst_count;i++){
		int u=mst[i]->edge_start;
		int v=mst[i]->edge_end;
		printf("(%c,%c)\n",graph->adjList[u].data,graph->adjList[v].data);
	}
	return mst;
}
void insert_edge_by_weight(Edge **a,int n){
	Edge* key=0;
	int j=0;
	for(int i=1;i<n;i++){
		j=i-1;
		key=a[i];
		while(j>=0&&a[j]->edge_weight > key->edge_weight){
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
	for(int i=0;i<n;i++){
		printf("%d\n", a[i]->edge_weight);
	}
}
Edge **MST_PRIME(Graph *graph){
	Vertex **temp=(Vertex **)malloc((graph->num_nodes)*(sizeof(Vertex*)));
	int n=graph->num_nodes;
	for(int i=0;i<graph->num_nodes;i++){
		temp[i]=&graph->adjList[i];
		graph->adjList[i].key=INFINITE;
		graph->adjList[i].parent=NIL;
	}
	temp[0]->key=0;
	while(n>0){
		int u=extract_min(temp,n);
		n--;
		Edge *p=graph->adjList[u].edge;
		while(p!=NULL){
			Vertex node=graph->adjList[p->edge_end];
			int index=belong_queue(temp,node,n);
			if((index!=-1)&&(p->edge_weight < node.key)){
				graph->adjList[p->edge_end].parent=u;
				graph->adjList[p->edge_end].key=p->edge_weight;
			}
			p=p->next;
		}
	}

}
int belong_queue(Vertex **queue,Vertex node,int n){
	for(int i=0;i<n;i++){
		if(queue[i]->data==node.data){
			return i;
		}
	}
	return -1;
}
int extract_min(Vertex **queue,int n){
	int min=queue[0]->key;
	int min_index=0;
	for(int i=0;i<n;i++){
		if(min>queue[i]->key){
			min=queue[i]->key;
			min_index=i;
		}
	}
	for(int i=min_index;i<n-1;i++){
		queue[i]=queue[i+1];
	}
	return min_index;
}
int extract_min_by_dis(Vertex **queue,int n){
	int min=queue[0]->distance;
	int min_index=0;
	for(int i=0;i<n;i++){
		if(min>queue[i]->distance){
			min=queue[i]->distance;
			min_index=queue[i]->data-'a';
		}
	}
	for(int i=min_index;i<n-1;i++){
		queue[i]=queue[i+1];
	}
	return min_index;
}
void initial_single_source(Graph *graph,int s){
	for(int i=0;i<graph->num_nodes;i++){
		graph->adjList[i].distance=INFINITE;
		graph->adjList[i].parent=NIL;
	}
	graph->adjList[s].distance=0;
}
void relex(Graph *graph,Edge *edge){
	int u=edge->edge_start;
	int v=edge->edge_end;
	int temp=0;
	if(graph->adjList[u].distance==INFINITE){
		if(edge->edge_weight==-INFINITE){
			temp=0;
		}
		else{
			temp=INFINITE;
		}
	}
	else{
		temp=graph->adjList[u].distance+edge->edge_weight;
	}
	
	if(graph->adjList[v].distance>temp){
		graph->adjList[v].distance=temp;
		graph->adjList[v].parent=u;
	}
}
int BELLMAN_FORD(Graph *graph,int s){
	initial_single_source(graph,s);
	Edge *p;
	for(int k=0;k<graph->num_nodes;k++){
		for(int i=0;i<graph->num_nodes;i++){
			p=graph->adjList[i].edge;
			while(p!=NULL){
				relex(graph,p);
				p=p->next;
			}
		}
	}
	for(int i=0;i<graph->num_nodes;i++){
		p=graph->adjList[i].edge;
		while(p!=NULL){
			int u=p->edge_start;
			int v=p->edge_end;
			if(graph->adjList[v].distance>graph->adjList[u].distance+p->edge_weight){
				return 0;
			}
			p=p->next;
		}
	}
	return 1;
}
void DAG_SHORTEST_PATHS(Graph *graph,int s){
	DFS(graph);
	initial_single_source(graph,s);
	for(int i=0;i<graph->num_nodes;i++){
		int u=graph->num_nodes-(graph->topological_sort[i].data-'a')-1;
		Edge *p=graph->adjList[u].edge;
		while(p!=NULL){
			relex(graph,p);
			p=p->next;
		}
	}
}
void find_critical_path(Graph* graph,int s){
	//let all weight of each edge become -weight the run DAG_SHORTEST_PATHS
}
void DIJKSTRA(Graph *graph,int s){
	initial_single_source(graph,s);
	Vertex **temp=(Vertex **)malloc((graph->num_nodes)*(sizeof(Vertex*)));
	int n=graph->num_nodes;
	for(int i=0;i<graph->num_nodes;i++){
		temp[i]=&graph->adjList[i];

	}
	while(n>0){
		int u=extract_min_by_dis(temp,n);
		n--;
		Edge *p=graph->adjList[u].edge;
		while(p!=NULL){
			relex(graph,p);
			p=p->next;
		}
	}
}
void differencial_cons_solve(){

}
int ** differencial_matrix_to_adjlist(int **matric,int m,int n){
	//m rows n colums
	int num_nodes=m+1;
	int num_edges=n+m;
}
int main()
{
	Graph mygraph,*mygraph_t;
	creat_graph(&mygraph);
	print_graph(&mygraph);
	//if(BELLMAN_FORD(&mygraph,4)){
	//	print_path(&mygraph,'e','b');	
	//}
	//DAG_SHORTEST_PATHS(&mygraph,0);
	DIJKSTRA(&mygraph,0);
	//MST_KRUSKAL(&mygraph);
	//MST_PRIME(&mygraph);
	//strongly_connected_components(&mygraph);
	//BFS(&mygraph,3);
	print_path(&mygraph,'a','e');
	
	//strongly_connected_components(&mygraph);
	//connected_components_by_union_find(&mygraph);
	//print_topological_sort(&mygraph);
	//print_time_label(&mygraph);
	return 0;
}