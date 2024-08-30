#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class graph{
public:
    int **cost;
    int *visited;
    int mincost = 0;
    int n;

    void initialize(){
        cout << "Enter the number of nodes: ";
        cin >> n;

        cost = new int *[n];
        visited = new int[n];

        for (int i = 0; i < n; i++)
        {
            visited[i] = 0;
            cost[i] = new int[n];
        }

        cout << "Enter adjacency matrix:\n";
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> cost[i][j];
                if (cost[i][j] == 0 && i != j) {
                    cost[i][j] = numeric_limits<int>::max();
                }
            }
        }
    }

    int find(int i){
        while (visited[i] != i)
            i = visited[i];
        return i;
    }

    void union_ij(int i, int j){
        if (i != j){
            visited[j] = i;
        }
    }

    void kruskal(){
        int minweight;

        for (int i = 0; i < n; i++){
            visited[i] = i;
        }

        cout << "Edges of the Minimum Spanning Tree:\n";
        for (int counter = 0; counter < n - 1; counter++){
            minweight = 9999;
            int u, v;
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    if (find(i) != find(j) && cost[i][j] < minweight){
                        minweight = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
            union_ij(find(u), find(v));
            cout << "\nEdge " << counter + 1 << ":(" << u << "," << v << ") Cost:" << minweight;
            mincost += minweight;
        }
        cout << "\nTOTAL COST OF MST: " << mincost;
    }
};

int main()
{
    graph g;
    g.initialize();
    g.kruskal();
    return 0;
}