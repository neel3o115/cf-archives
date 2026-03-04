#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    const int B = 31;

    vector<vector<int>> pref(B, vector<int>(n + 1, 0));

    for (int b = 0; b < B; b++) {
        for (int i = 1; i <= n; i++) {
            pref[b][i] = pref[b][i - 1] + ((a[i] >> b) & 1);
        }
    }

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        int len = r - l + 1;
        long long ans = 0;

        for (int b = 0; b < B; b++) {
            int cnt = pref[b][r] - pref[b][l - 1];

            if (t == 0) { 
                if (cnt % 2) ans |= (1LL << b);
            }
            else if (t == 1) {
                if (cnt == len) ans |= (1LL << b);
            }
            else {
                if (cnt > 0) ans |= (1LL << b);
            }
        }

        cout << ans << "\n";
    }
}
