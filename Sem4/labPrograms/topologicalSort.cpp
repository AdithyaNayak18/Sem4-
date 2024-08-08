#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void topoUtil(const vector<vector<int>>& adj, vector<bool>& visited, stack<int>& Stack, int v) {
    visited[v] = true;
    for (int i : adj[v]) {
        if (!visited[i]) {
            topoUtil(adj, visited, Stack, i);
        }
    }
    Stack.push(v);
}

void topoLogicalSort(const vector<vector<int>>& adj, int vertices) {
    stack<int> Stack;
    vector<bool> visited(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topoUtil(adj, visited, Stack, i);
        }
    }

    cout << "Topological Sort: ";
    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    int v = 4;
    vector<vector<int>> adj(v);

    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);

    topoLogicalSort(adj, v);

    return 0;
}
