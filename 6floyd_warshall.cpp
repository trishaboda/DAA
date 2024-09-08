#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class floyed_2 {
public:
    const int INF = numeric_limits<int>::max();  // Define infinity

    // Modified Floyd-Warshall Algorithm
    void floydWarshall(vector<vector<int>>& weight) {
        int n = weight.size();
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (weight[i][k] != INF && weight[k][j] != INF && weight[i][k] + weight[k][j] < weight[i][j]) {
                        weight[i][j] = weight[i][k] + weight[k][j];
                    }
                }
            }
        }
        printSolution(weight);
    }

    // Print the solution matrix
    void printSolution(const vector<vector<int>>& weight) {
        int n = weight.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (weight[i][j] == INF) {
                    cout << "INF   "; // Represent infinity
                } else {
                    cout << weight[i][j] << "   ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> G(n, vector<int>(n));
    floyed_2 a;

    cout << "Enter the adjacency matrix (use -1 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int input;
            cin >> input;
            G[i][j] = (input == -1) ? a.INF : input;  // Replace -1 with INF
        }
    }
    cout << "\nShortest path:\n";
    a.floydWarshall(G);
    return 0;
}
