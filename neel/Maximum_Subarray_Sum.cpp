#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll currentSum = a[0];
    ll bestSum = a[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(a[i], currentSum + a[i]);
        bestSum = max(bestSum, currentSum);
    }

    cout << bestSum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
}