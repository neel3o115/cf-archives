#include<bits/stdc++.h>
using namespace std;

using namespace std;

void processTestCase() {
    long long totalRows, totalColumns, rowJumpStep, columnJumpStep;
    cin >> totalRows >> totalColumns >> rowJumpStep >> columnJumpStep;

    long long rowAlignment = std::gcd(totalRows, rowJumpStep);
    long long columnAlignment = std::gcd(totalColumns, columnJumpStep);
    long long gridAlignment = std::gcd(totalRows, totalColumns);

    if (rowAlignment == 1 && columnAlignment == 1 && gridAlignment <= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int totalTestCases;
    if (cin >> totalTestCases) {
        while (totalTestCases--) {
            processTestCase();
        }
    }
    return 0;
}