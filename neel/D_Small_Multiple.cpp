#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vis(n, 0);

    // each state stores: (current remainder, current digit sum)
    queue<pair<int, int>> q;       
    q.push({1, 1});                
    vis[1] = 1;

    while (!q.empty()) {
        auto [x, s] = q.front();  
        q.pop();

        if (x == 0) {             
            cout << s;
            return;
        }

        int y = (10*x) % n;
        while (!vis[y]) {
            vis[y] = 1;
            q.push({(y+1) % n, s + 1});
            y = (10 * y) % n;

            if (y == 0) {
                cout << s;
                return;
            }
        }

        q.push({(x+1) % n, s + 1});
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
