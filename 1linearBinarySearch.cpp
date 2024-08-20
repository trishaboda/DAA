#include <iostream>
#include <cstdlib>
#include <algorithm> // for std::sort
#include <ctime>     // for clock()

using namespace std;

// Generate numbers randomly 
void generateRandomNumbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

// Perform a linear search
void linearSearch(int arr[], int n, int m) {
    int occ = 0;
    cout << "Linear search for " << m << ":\n";
    cout << "Elements exist at indices: ";
    for (int i = 0; i < n; i++) {
        if (arr[i] == m) {
            occ++;
            cout << i << " ";
        }
    }
    if (occ == 0) {
        cout << "Element not found.";
    } else {
        cout << "\nTotal occurrences: " << occ;
    }
    cout << endl;
}

// Perform a recursive binary search
int recursiveBinarySearch(int a[], int start, int end, int element) {
    if (start <= end) {
        int mid = (start + end) / 2;
        cout << "Checking middle index " << mid << " with value " << a[mid] << endl;

        if (a[mid] == element) {
            return mid;
        } else if (a[mid] < element) {
            return recursiveBinarySearch(a, mid + 1, end, element);
        } else {
            return recursiveBinarySearch(a, start, mid - 1, element);
        }
    }
    return -1;
}

// Print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    const int n = 25;
    int arr[n];

    generateRandomNumbers(arr, n);
    cout << "Original array:\n";
    printArray(arr, n);

    int element;
    cout << "Enter the element to search for: ";
    cin >> element;

    clock_t start, end;
    double duration;

    // Linear search
    start = clock();
    linearSearch(arr, n, element);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken for linear search: " << duration << " seconds" << endl;

    // Sort the array for binary search
    sort(arr, arr + n);
    cout << "\nSorted array:\n";
    printArray(arr, n);

    // Binary search
    start = clock();
    cout << "Binary search for " << element << ":\n";
    int result = recursiveBinarySearch(arr, 0, n - 1, element);
    end = clock();
    duration = double(end - start) / CLOCKS_PER_SEC;
    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found.\n";
    }
    cout << "Time taken for binary search: " << duration << " seconds" << endl;

    return 0;
}
