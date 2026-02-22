#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 1e18;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

unordered_map<ll, ll> dp;
vector<int> coin = {1, 3, 6, 10, 15};

ll rec(ll n) {
    if (dp.count(n)) return dp[n];

    ll res = INF;

    for (int i = 0; i < 5; i++) {
        if (n - coin[i] >= 0) {
            res = min(res, 1 + rec(n - coin[i]));
        }
    }

    return dp[n] = res;
}

void solve() {
    ll n;
    cin >> n;
    cout << rec(n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}