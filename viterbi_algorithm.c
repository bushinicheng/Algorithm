//from https://segmentfault.com/a/1190000008720143
#include "graph_algorithm.h"
#include "viterbi_graph.h"
int main(){
	GraphAdjList G;
    CreatALGraph(&G);

    print_graph(&G);

    int start,end;
    printf("Input the start of the edge : \n");
    scanf("%d",&start);
    printf("Input the end of the edge : \n" );
   	scanf("%d",&end);
    DFS(&G,start,end);
    printf("\n");
    printf("%d\n",path_exist);

    //cout<<G.adjList[start].color<<" "<<G.adjList[start].touch<<" "<<G.adjList[start].finish<<" "<<endl;
    //cout<<G.adjList[end].color<<" "<<G.adjList[end].touch<<" "<<G.adjList[end].finish<<" "<<endl;
    printf("%s\n", "The path is :");
    path_print(&G,start,end);
    return 0;
}