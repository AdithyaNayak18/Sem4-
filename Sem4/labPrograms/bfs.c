#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct graph_t {
    int v;
    bool adj[MAX][MAX];
} graph;

graph* createG(int v) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->v = v;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            g->adj[i][j] = false;
        }
    }
    return g;
}

void destroy(graph* g) {
    free(g);
}

void addEdge(graph* g, int v, int w) {
    g->adj[v][w] = true;
}

void bfs(graph* g, int a) {
    bool visited[MAX];
    for (int i = 0; i < g->v; i++)
        visited[i] = false;
    
    int queue[MAX];
    int front = 0, rear = 0;
    visited[a] = true;
    queue[rear++] = a;
    
    while (front != rear) {
        int s = queue[front++];
        printf("%d ", s);
        
        for (int j = 0; j < g->v; j++) {
            if (g->adj[s][j] && !visited[j]) {
                queue[rear++] = j;
                visited[j] = true;
            }
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
    
    printf("Following is Breadth First Traversal (starting from vertex 2)\n");
    bfs(g, 2);
    destroy(g);

    return 0;
}
