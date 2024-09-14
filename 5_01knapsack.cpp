#include <iostream>
#include <vector>
#include <iomanip> 
#include <algorithm> 
using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& profits) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], profits[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    int maxProfit = dp[n][capacity];

    cout << "\nDP Table:\n";
    for (const auto& row : dp) {
        for (int val : row) {
            cout << std::setw(5) << val << " "; 
        }
        cout << endl;
    }

    cout << "\nSelected items in the knapsack:\n";
    int w = capacity;
    for (int i = n; i > 0 && maxProfit > 0; --i) {
        if (maxProfit != dp[i - 1][w]) {
            cout << "Item " << i << ": (Profit: " << profits[i - 1] << ", Weight: " << weights[i - 1] << ")\n";
            maxProfit -= profits[i - 1];
            w -= weights[i - 1];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> weights(n), profits(n);
    
    for (int i = 0; i < n; ++i) {
        cout << "Enter the weight of item " << (i + 1) << ": ";
        cin >> weights[i];

        cout << "Enter the profit of item " << (i + 1) << ": ";
        cin >> profits[i];
    }

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) {
        indices[i] = i;
    }
    sort(indices.begin(), indices.end(), [&weights](int a, int b) {
        return weights[a] < weights[b];
    });

    vector<int> sortedWeights(n), sortedProfits(n);
    for (int i = 0; i < n; ++i) {
        sortedWeights[i] = weights[indices[i]];
        sortedProfits[i] = profits[indices[i]];
    }

    int maxProfit = knapsack(capacity, sortedWeights, sortedProfits);
    cout << "\nMaximum profit for the knapsack = " << maxProfit << endl;

    return 0;
}
