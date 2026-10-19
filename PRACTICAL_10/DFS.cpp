#include <iostream>
#include <vector>
#include <iomanip>

class Graph {
private:
    int V; // Number of vertices
    std::vector<std::vector<int>> adj; // Adjacency list

    void DFSUtil(int v, std::vector<bool>& visited) {
        visited[v] = true;
        std::cout << v << " ";

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(vertices);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //construct and print the Adjacency Matrix
    void printAdjacencyMatrix() {
        std::vector<std::vector<int>> matrix(V, std::vector<int>(V, 0));

        for (int i = 0; i < V; ++i) {
            for (int neighbor : adj[i]) {
                matrix[i][neighbor] = 1;
            }
        }

        std::cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    void DFS(int startVertex) {
        std::vector<bool> visited(V, false);
        std::cout << "Depth First Traversal (starting from vertex " << startVertex << "):\n";
        DFSUtil(startVertex, visited);
        std::cout << "\n";
    }
};

int main() {
    
    Graph g(5);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    //Adjacency Matrix
    g.printAdjacencyMatrix();

    //DFS Traversal
    g.DFS(0);

    return 0;
}
