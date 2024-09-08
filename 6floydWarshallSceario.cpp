#include <iostream>
#include <vector>
#include <limits>
#include <sstream>
#include <iomanip>  // For formatting output

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

    // Function to convert seconds to MM:SS format
    string convertToMMSS(int totalSeconds) {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;
        stringstream ss;
        ss << setfill('0') << setw(2) << minutes << ":" << setfill('0') << setw(2) << seconds;
        return ss.str();
    }

    // Print the solution matrix
    void printSolution(const vector<vector<int>>& weight) {
        int n = weight.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (weight[i][j] == INF) {
                    cout << "INF   "; // Represent infinity
                } else {
                    cout << convertToMMSS(weight[i][j]) << "   "; // Convert seconds to MM:SS format
                }
            }
            cout << endl;
        }
    }

    // Function to convert MM:SS format input to seconds
    int convertToSeconds(const string& time) {
        int minutes, seconds;
        char colon;
        stringstream ss(time);
        ss >> minutes >> colon >> seconds;
        return minutes * 60 + seconds;
    }
};

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> G(n, vector<int>(n));
    floyed_2 a;

    cout << "Enter the adjacency matrix in MM:SS format (use -1 for infinity):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            string input;
            cin >> input;
            if (input == "-1") {
                G[i][j] = a.INF;  // Represent no path as INF
            } else {
                G[i][j] = a.convertToSeconds(input);  // Convert MM:SS input to seconds
            }
        }
    }

    cout << "\nShortest path in MM:SS format:\n";
    a.floydWarshall(G);

    return 0;
}
