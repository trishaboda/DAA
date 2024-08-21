#include <iostream>
#include <algorithm>
using namespace std;

int maxGoodSubsequenceLength(int A[], int N) {

    sort(A, A + N);

    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < N; ++end) {

        while (A[end] - A[start] > 10) {
            start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    int A[] = {1, 9,14,2,17,14,5,18};
    int N = sizeof(A) / sizeof(A[0]);

    int result = maxGoodSubsequenceLength(A, N);
    cout << "The maximum length of a good subsequence is: " << result << endl;

    return 0;
}