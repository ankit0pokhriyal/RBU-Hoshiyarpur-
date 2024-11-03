#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// Function to perform DFS on a graph
void DFS(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
     // initialize an empty stack s
    stack<int> s; 
     // push start  in stack                
    s.push(start);      
    // Mark the starting node as visited i.e make visited[start] true          
    visited[start] = true;        

    // till stack is not empty
    while (!s.empty()) {    
        // store top of stack into node     
        int node = s.top();   
        // pop the node 
        s.pop();
        // print the popped node
        cout << node << " ";      

        // Explore all adjacent nodes
        // for neighbour in graph[node] 
        for (int neighbor : graph[node]) {
            // if neighbour are not visited i.e !=visited[neighbour]
            if (!visited[neighbor]) {
                // push the neighbour
                s.push(neighbor);
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

    // Starting DFS from node 0
    cout << "DFS starting from node 0: ";
    DFS(0, graph, visited);

    return 0;
}
