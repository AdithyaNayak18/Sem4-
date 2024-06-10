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

	for(int i=0;i<max;i++){
		for(int j=0;j<max;j++){
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

void dfs(graph* g,int start){
	int stack[max];
	int top=-1;
	bool visited[g->n];

	visited[start]=true;
	stack[++top]=start;

	while(top>=0)
	{
		int t=stack[top--];
		printf("%d ",t);

		for(int j=0;j<g->n;j++)
			if(g->adj[t][j] && !visited[j])
			{
				stack[++top]=j;
				visited[j]=true;
			}
	}
	printf("\n");
}
int main() {
    graph* g = createG(6);
    addEdge(g, 1, 2);
    addEdge(g, 1, 0);
    addEdge(g, 2, 3);
    addEdge(g, 3, 4);
    addEdge(g, 4, 5);
    addEdge(g, 5, 1);
    addEdge(g, 5, 2);
    
    printf("Following is depthh First Traversal (starting from vertex 2)\n");
    dfs(g, 2);
    delG(g);

    return 0;
}
