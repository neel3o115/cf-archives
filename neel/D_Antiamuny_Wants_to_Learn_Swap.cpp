#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            vector<int> nee(a.begin() + l, a.begin() + r + 1);
            vector<int> jee = nee;
            sort(jee.begin(), jee.end());

            int i = 0;
            while (i < (int)nee.size() - 1) {
                if (nee[i] < nee[i + 1]) {
                    i++;
                } else {
                    swap(nee[i], nee[i + 1]);
                    i += 2;
                }
            }

            if (nee == jee) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
