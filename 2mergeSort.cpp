#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void merge(int a[], int l, int m, int r, int n)
{
    int x;
    static int c = 1;
    int i = l;
    int j = m + 1;
    int k = l;
    int* temp = new int[n];
    while (i <= m && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= m)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (int p = l; p <= r; p++)
    {
        a[p] = temp[p];
    }
    cout << "\n\nPass " << c++ << ": ";
    for (x = 0; x < n; x++)
    {
        cout << a[x] << " ";
    }
    delete[] temp;
}

void mergeSort(int a[], int l, int r, int n)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m, n);
        mergeSort(a, m + 1, r, n);
        merge(a, l, m, r, n);
    }
}

// Function to remove duplicate elements This function
// returns new size of modified array.
int removeDuplicates(int arr[], int n)
{
    // Return, if array is empty or 
    // contains a single element
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    // Start traversing elements
    int j = 0;
  
    // If current element is not equal to next element
    // then store that current element
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    // Store the last element as whether it is unique or
    // repeated, it hasn't stored previously
    temp[j++] = arr[n - 1];

    // Modify original array
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

int main()
{
    int n, i;
    cout << "Enter the number of elements: ";
    cin >> n;

    srand(time(0));

    int* a = new int[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;  
    }

    cout << "\nUnsorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    clock_t start = clock();
    mergeSort(a, 0, n - 1, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    cout << "\nSorted Array: ";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    n = removeDuplicates(a, n);

    cout << "\n\nTime taken for merge sort: " << time_taken << " seconds\n";

    cout << "\nArray after removing duplicates: ";

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    delete[] a;
    return 0;
}
