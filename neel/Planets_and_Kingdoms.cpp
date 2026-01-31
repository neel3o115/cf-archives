#include <bits/stdc++.h>
using namespace std;

const int MAX_NODES = 200005;

int n, m;
vector<vector<int>> graph;
vector<int> disc, low, inStack, componentId;
stack<int> st;
int timer = 0, sccCount = 0;

void tarjanDFS(int u) {
    disc[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = 1;

    for (int v : graph[u]) {
        if (disc[v] == -1) {
            // If v is unvisited, explore it
            tarjanDFS(v);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            // If v is in stack, it's part of the current SCC
            low[u] = min(low[u], disc[v]);
        }
    }

    // If u is a root node of SCC
    if (low[u] == disc[u]) {
        sccCount++;
        while (true) {
            int node = st.top();
            st.pop();
            inStack[node] = 0;
            componentId[node] = sccCount;
            if (node == u) break;
        }
    }
}

void solve() {
    cin >> n >> m;

    graph.assign(n + 1, {});
    disc.assign(n + 1, -1);
    low.assign(n + 1, 0);
    inStack.assign(n + 1, 0);
    componentId.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (disc[i] == -1) {
            tarjanDFS(i);
        }
    }

    cout << sccCount << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << componentId[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
