#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        vector<bool> vis(n + 1, false);
        int cur = 1;

        vis[cur] = true;

        for (int i = 0; i < n; i++) {
            if (s[cur - 1] == 'R') cur++;
            else cur--;

            vis[cur] = true;
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (vis[i]) ans++;

        cout << ans << "\n";
    }

    return 0;
}