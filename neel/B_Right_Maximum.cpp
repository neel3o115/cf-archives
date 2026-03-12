#include <bits/stdc++.h>
using namespace std;

const long double PI = 3.14159265358979323846;
const long double E = 2.718281828459045;
const long long INF = 1000000000000000000;
const long long MOD1 = 1000000007;
const long long MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> ps(n);
    ps[0] = a[0];

    long long res = 0;

    for (int i = 1; i < n; i++) {
        if (ps[i-1] < a[i]) {
            ps[i] = a[i];
        } 
        else if (ps[i-1] == a[i]) {
            ps[i] = a[i];
            res++;
        } 
        else {
            ps[i] = ps[i-1];
        }
    }

    set<long long> nee(ps.begin(), ps.end());
    cout << nee.size() + res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}