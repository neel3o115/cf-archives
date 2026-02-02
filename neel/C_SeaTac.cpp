#include <bits/stdc++.h>
using namespace std;

#define int long long
#define i32 int
#define INF 1e18

int vis[200001];
int found = 0;

void dfs(int node, vector<vector<int>> &adj, int par) {
    if (vis[node]) {
        if (vis[node] != par) {
            cout << 0 << endl;
            found = 1;
            exit(0);
        }
    } else {
        vis[node] = par;
        for (int child : adj[node]) {
            dfs(child,adj,1-par);
        }
    }
}

void solve() {
    int n,m,g; cin >> n >> m >> g;
    vector<vector<int>> adj(n+1);
    
    for (int i = 0; i < m; ++i) {
        int u,v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1,adj,0);
    
    if (g == 2) {
        cout << vis[n] << endl;
    } else {
        cout << 0 << endl;
    }
}

int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t = 1;
// 	cin >> t;
	while(t--) {
	    solve();
	}
	return 0;
}