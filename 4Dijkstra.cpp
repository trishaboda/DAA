#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#include <algorithm> 

using namespace std;

int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(const vector<int>& dist, const vector<string>& vertices, int V) {
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << vertices[i] << " \t\t " << dist[i] << endl;
}

void printSPTSet(const vector<bool>& sptSet, const vector<string>& vertices, int V) {
    cout << "sptSet: ";
    for (int i = 0; i < V; i++)
        cout << (sptSet[i] ? vertices[i] : "_") << " ";
    cout << endl;
}

void dijkstra(const vector<vector<int>>& graph, int src, const vector<string>& vertices, int V) {
    vector<int> dist(V, INT_MAX); 
    vector<bool> sptSet(V, false); 

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];

        printSPTSet(sptSet, vertices, V);
    }

    printSolution(dist, vertices, V);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<string> vertices(V);
    cout << "Enter the vertex names:" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i + 1 << ": ";
        cin >> vertices[i];
    }

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix:" << endl;
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    string srcVertex;
    cout << "Enter the source vertex: ";
    cin >> srcVertex;

    auto it = find(vertices.begin(), vertices.end(), srcVertex);
    if (it == vertices.end()) {
        cout << "Invalid source vertex!" << endl;
        return -1;
    }
    int src = distance(vertices.begin(), it);

    dijkstra(graph, src, vertices, V);

    return 0;
}
