#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define i32 int
#define INF 1e18

const int N = 100005;
vector<int> indeg(N), gvis(N), topo;
vector<vector<int>> g(N);
bool imp = false;

void solve() {
    int n,m; cin >> n >> m;
    
    vector<int> vis(n+1);
    
    for (int i=0; i<m; i++) {
        int a,b; cin>>a>>b;
        indeg[b]++;
        g[a].push_back(b);
    }
    
    set<vector<int>> qu;
    
    for (int i = 1; i <= n; ++i) {
        qu.insert({indeg[i],i});
    }
    
    vector<int> res;
    
    while (qu.size()) {
        vector<int> xx = *qu.begin();
        qu.erase(xx);
        
        if ((vis[xx[1]]) or (xx[0] != 0)) continue;
        
        res.push_back(xx[1]);
        vis[xx[1]] = 1;
        
        for (auto it: g[xx[1]]) {
            indeg[it]--;
            qu.insert({indeg[it],it});
        }
    }
    
    if (res.size() == n) {
        for (auto it: res) {
            cout << it << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    } 
}

int32_t main() {
	// your code goes here
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t = 1;
// 	cin >> t;
	while (t--) {
	    solve();
	}
	return 0;
}