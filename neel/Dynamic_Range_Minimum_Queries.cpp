#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    // Input array
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Block size (approximately sqrt(n))
    int blockSize = 400;
    int numBlocks = (n + blockSize - 1) / blockSize;

    // Each block stores the minimum value in its range
    vector<long long> block(numBlocks, LLONG_MAX);

    // Preprocess: calculate block-wise minimums
    for (int i = 0; i < n; i++) {
        block[i / blockSize] = min(block[i / blockSize], arr[i]);
    }

    // Process queries
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Type 1: update operation
            // Update value at position x to y
            int index;
            long long newValue;
            cin >> index >> newValue;
            index--; // 0-based index

            arr[index] = newValue;

            // Recalculate block minimum for affected block
            int blockIndex = index / blockSize;
            long long newMin = LLONG_MAX;
            int start = blockIndex * blockSize;
            int end = min(n, start + blockSize);

            for (int i = start; i < end; i++) {
                newMin = min(newMin, arr[i]);
            }
            block[blockIndex] = newMin;

        } else if (type == 2) {
            // Type 2: range minimum query
            int left, right;
            cin >> left >> right;
            left--; // 0-based index

            long long answer = LLONG_MAX;
            int i = left;

            // Traverse blocks efficiently
            while (i < right) {
                if (i % blockSize == 0 && i + blockSize <= right) {
                    // If full block fits inside range
                    answer = min(answer, block[i / blockSize]);
                    i += blockSize;
                } else {
                    // Otherwise, check individual elements
                    answer = min(answer, arr[i]);
                    i++;
                }
            }

            cout << answer << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
