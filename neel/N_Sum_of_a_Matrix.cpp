#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a, b, c;

void rec(int x, int y, int n, int m) {
    if (x == n || y == m)
        return;

    c[x][y] = a[x][y] + b[x][y];

    if (y == m - 1)
        rec(x + 1, 0, n, m);
    else
        rec(x, y + 1, n, m);
}

int main() {
    int n, m;
    cin >> n >> m;

    a.assign(n, vector<int>(m));
    b.assign(n, vector<int>(m));
    c.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];

    rec(0, 0, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
