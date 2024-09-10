#include <iostream>
#include <iomanip> 
#include <algorithm>

using namespace std;

double profitRatio(int profit, int weight) {
    return (double)profit / weight;
}

bool compare(int i, int j, int profit[], int weights[]) {
    return profitRatio(profit[i], weights[i]) > profitRatio(profit[j], weights[j]);
}

double fractionalKnapsack(int W, int weights[], int profit[], int n) {
    int indices[n];
    for (int i = 0; i < n; i++) {
        indices[i] = i;
    }

    sort(indices, indices + n, [&](int i, int j) {
        return compare(i, j, profit, weights);
    });

    double totalProfit = 0.0;

    cout << "\nProfit ratios in descending order (Profit/Weight):" << endl;
    for (int i = 0; i < n; i++) {
        int index = indices[i];
        cout << "Item " << index + 1 << ": " << fixed << setprecision(2)
             << profitRatio(profit[index], weights[index]) << " (Profit: "
             << profit[index] << ", Weight: " << weights[index] << ")" << endl;
    }

    cout << "\nAdding items to the knapsack:" << endl;
    for (int i = 0; i < n; i++) {
        int idx = indices[i];

        if (W == 0) break; 

        if (weights[idx] <= W) {
            W -= weights[idx];
            totalProfit += profit[idx];
            cout << "Added complete item " << idx + 1 << " (Profit: " 
                 << profit[idx] << ", Weight: " << weights[idx] << ")" << endl;
        } else {
            double fraction = (double)W / weights[idx];
            totalProfit += profit[idx] * fraction;
            cout << "Added " << fixed << setprecision(2) << (int)W << "/" << weights[idx] << " of item "
                 << idx + 1 << " (Profit: " << profit[idx] * fraction 
                 << ", Weight: " << W << ")" << endl;
            W = 0;
        }
    }

    return totalProfit;
}

int main() {
    int W, n;

    cout << "Enter the total capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    int weights[n], profit[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter weight for item " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> profit[i];
    }

    double maxProfit = fractionalKnapsack(W, weights, profit, n);

    cout << "\nMaximum Profit in Knapsack = " << maxProfit << endl;

    return 0;
}