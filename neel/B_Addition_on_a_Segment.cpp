#include <bits/stdc++.h>
using namespace std;

const double PI = 3.14159265358979323846;
const double E  = 2.718281828459045;
const long long INF = 1000000000000000000LL;
const int MOD1 = 1000000007;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    long long ans = min(n,sum-n+1);

    if (ans > n)
        cout << n << "\n";
    else
        cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) solve();
}
