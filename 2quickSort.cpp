#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int* arr, int low, int high, int &pass) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    cout << "\nPass " << ++pass << ": ";
    printArray(arr, high + 1);
    return i + 1;
}

void quickSort(int* arr, int low, int high, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);
        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        arr[i] = std::rand() % 1000 + 1;
    }

    cout << "\nUnsorted array: ";
    printArray(arr, n);

    int pass = 0;
    auto start = chrono::high_resolution_clock::now();

    quickSort(arr, 0, n - 1, pass);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    cout << "\nSorted array: ";
    printArray(arr, n);

    cout << "\nTime taken by Quick Sort: " << duration.count() << " seconds" << endl;

    delete[] arr;
    return 0;
}
