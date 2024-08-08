#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bfs(const vector<vector<int>>& adjList, int startNode, int vertices) {
    queue<int> q;
    
    vector<bool> visited(vertices, false);
    
    visited[startNode] = true;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                // Mark the neighbor as visited and enqueue it
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices = 5;
    
    // Adjacency list representation of the graph
    vector<vector<int>> adjList(vertices);
    
    // Adding edges to the graph
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    adjList[2].push_back(4);
    
    int startNode = 0;
    
    // Measure time required for BFS
    auto start = high_resolution_clock::now();
    
    cout << "Breadth-First Search starting from vertex " << startNode << ": ";
    bfs(adjList, startNode,vertices);
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    
    cout << "Time taken for BFS: " << duration.count() << " milliseconds\n";
    
    return 0;
}
