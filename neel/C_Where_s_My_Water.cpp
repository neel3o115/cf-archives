#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        ll h;
        cin >> n >> h;

        vector<ll> a(n), w(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            w[i] = h - a[i];
        }

        vector<ll> ps(n + 1);
        for (int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + w[i];

        vector<int> L(n), R(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && w[st.top()] >= w[i]) st.pop();
            L[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && w[st.top()] >= w[i]) st.pop();
            R[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }

        vector<ll> val(n);

        for (int i = 0; i < n; i++) {
            ll sum = ps[R[i] + 1] - ps[L[i]];
            ll len = R[i] - L[i] + 1;
            val[i] = sum - len * (w[i] - 1);
        }

        vector<ll> bestRight(n + 1);

        for (int i = n - 1; i >= 0; i--)
            bestRight[i] = max(bestRight[i + 1], val[i]);

        ll ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, val[i]);

            if (R[i] + 1 < n)
                ans = max(ans, val[i] + bestRight[R[i] + 1]);
        }

        cout << ans << "\n";
    }
}