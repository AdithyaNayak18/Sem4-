#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define max 10

typedef struct graph_t{
	int n;
	bool adj[max][max];
} graph;

graph* createG(int n){
	graph* g=(graph*)malloc(sizeof(graph));
	g->n=n;

	for(int i=0; i < max; i++){
		for(int j=0;j < max;j++){
			g->adj[i][j]=false;
		}
	}

	return g;
}
void delG(graph* g) { free(g); }

void addEdge(graph* g,int from,int to)
{
	g->adj[from][to]=true;
}

int topoSortUtil(graph* g, int v, bool visited[], int stack[],int top){
	visited[v]=true;

	for(int i=0;i<g->n;i++)
		if(g->adj[v][i] && !visited[i])
			top=topoSortUtil(g,i,visited,stack,top);
	stack[top++] = v;
	return top;
}
 void topoSort(graph* g){
 	bool visited[max] = {false};
 	int stack[max];
 	int top=0;

 	for(int i=0;i<g->n;i++){
 		if(!visited[i])
 			top=topoSortUtil(g,i,visited,stack,top);
 	}
 	printf("\n Topological sort : ");
 	for(int i=top-1;i>0;i--)
 		printf("%d ",stack[i]);
 }
 int main(int argc, char const *argv[])
 {
 	graph* g=createG(6);
 	addEdge(g,5,2);
 	addEdge(g, 5, 0);
    addEdge(g, 4, 0);
    addEdge(g, 4, 1);
    addEdge(g, 2, 3);
    addEdge(g, 3, 1);

    printf("Following is Topological Sort (starting from vertex 2):\n");
    topoSort(g);
    delG(g);

 	return 0;
 }
