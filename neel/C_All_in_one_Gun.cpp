#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, h, k;
    cin >> n >> h >> k;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    ll s = 0;
    for (ll x : a) s += x;

    ll x = h / s;
    ll y = h % s;

    ll ans = x * n + max(0LL, x - 1) * k;

    if (y > 0) ans += k;

    vector<ll> sff = a;

    for (ll i = n - 2; i >= 0; i--)
        sff[i] = max(sff[i], sff[i + 1]);

    for (ll i = 0; i < n; i++) {
        if (sff[i] > y) {
            ans += 1;
            break;
        } else {
            y -= a[i];
            ans += 1;
        }
    }

    cout << ans - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}