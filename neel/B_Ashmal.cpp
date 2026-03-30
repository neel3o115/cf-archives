#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string last = a[0];
    string s = a[0];

    for (int i = 1; i < n; i++) {
        string x = a[i];

        if (x < last) {
            s = x + s;
        } else {
            s = s + x;
        }

        last = min(last, x);
    }

    cout << s << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
