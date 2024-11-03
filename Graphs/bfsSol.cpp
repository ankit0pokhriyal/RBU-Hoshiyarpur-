#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on a graph
void BFS(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    // initialize an empty queue q
    queue<int> q;
    // enque start  in queue use inbuilt function push
    q.push(start);
    // Mark the starting node as visited i.e make visited[start] true
    visited[start] = true;

    // till queue is not empty
    while (!q.empty()) {
        // store front of queue into node
        int node = q.front();
        // Deque the node use inbuilt function pop for that
        q.pop();
        // print the deque node
        cout << node << " ";

        // Explore all adjacent nodes
        // for neighbour in graph[node] 
        for (int neighbor : graph[node]) {
            // if neighbour are not visited i.e !=visited[neighbour]
            if (!visited[neighbor]) {
                // push the neighbour
                q.push(neighbor);
                // mark the neighbour as visited
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    // Number of nodes in the graph
    int nodes = 6; 
    // vector of vector 
    vector<vector<int>> graph(nodes);

    // Creating a sample graph (undirected)
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1, 5};
    graph[4] = {1, 2, 5};
    graph[5] = {3, 4};

    // Vector to track visited nodes
    vector<bool> visited(nodes, false);

    // Starting BFS from node 0
    cout << "BFS starting from node 0: ";
    BFS(0, graph, visited);

    return 0;
}
