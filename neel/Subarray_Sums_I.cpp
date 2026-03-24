#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n);
    for (int &v : a) cin >> v;

    long long res = 0;
    map<long long, long long> nee;
    nee[0] = 1;

    long long smm = 0;

    for (int i = 0; i < n; i++) {
        res += nee[smm+a[i]-x];
        smm += a[i];
        nee[smm]++;
    }

    cout << res << endl;
}