#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS on a graph
void BFS(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    // initialize an empty queue q
   
    // enque start  in queue use inbuilt function push

    // Mark the starting node as visited i.e make visited[start] true
    

    // till queue is not empty
    
        // store front of queue into node
    
        // Deque the node use inbuilt function pop for that
        // print the deque node
     

        // Explore all adjacent nodes
        // for neighbour in graph[node] 
        
            // if neighbour are not visited i.e !=visited[neighbour]
           
                // push the neighbour
             
                // mark the neighbour as visited
           
        
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
