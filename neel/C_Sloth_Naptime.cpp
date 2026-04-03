#include <bits/stdc++.h>
using namespace std;

// ---------- debug utilities ----------
#ifndef Local
    #define debug(...)
    #define debugArr(...)
#else
    #include <debug.cpp>
    auto start = chrono::high_resolution_clock::now();
#endif


// ---------- shortcut macros ----------
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(x) (int)(x).size()
#define pb push_back
#define print(zzz) cout << zzz << ' '<<endl;
#define print1(zzz) for(auto zzzz: zzz) cout << zzzz << ' ';cout<<endl;
#define print2(zzz) for (auto &zzzzz : zzz) {print1(zzzzz)}
#define space cout << endl;
#define sum(v) (accumulate((v).begin(), (v).end(), 0LL))
#define lb(v, x) (lower_bound((v).begin(), (v).end(), (x)) - (v).begin())  
#define ub(v, x) (upper_bound((v).begin(), (v).end(), (x)) - (v).begin())  
#define execute ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// ----------- constants -----------
#define PI 3.14159265358979323846
#define INF 1e18
#define MOD 1000000007
#define MOD2 998244353

// ---------- type aliases ----------
#define ll long long
#define int long long
#define vi vector<int> 
#define vc vector<char> 
#define vs vector<string> 
#define vvc vector<vector<char>> 
#define vvi vector<vector<int>> 
#define pii pair<int, int> 

// ---------- input macros ----------
#define msb(x) (x == 0 ? -1 : 1ll<<(63 - __builtin_clzll(x)))      
#define lsb(x) (x == 0 ? -1 : 1ll<<(__builtin_ctzll(x)))   
#define pc(x) (__builtin_popcountll(x))
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}

const int N = 300005;
const int LOG = 20;
int par[N][LOG];
vvi adj(N);
int vis[N];
int depth[N];

void dfs(int node, int p, int d) {
    if (vis[node]) return;
    vis[node] = 1;
    par[node][0] = p;
    depth[node] = d;
    
    for (int cld: adj[node]) {
        dfs(cld,node,d+1);
    }
}

void precompute(int n) {
    for (int j=1; j<LOG; j++) {
        for (int i=1; i<=n; i++) {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u]<depth[v]) swap(u,v);

    int diff = depth[u]-depth[v];
    for (int i=0; i<LOG; i++) {
        if (diff&(1<<i)) u = par[u][i];
    }

    if (u == v) return u;

    for (int i=LOG-1; i>=0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int kth(int u, int k) {
    for (int i=0; i<LOG; i++) {
        if (k&(1<<i)) {
            u = par[u][i];
            if (u == 0) return 0;
        }
    }
    return u;
}

int dist(int u, int v) {
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}

void solve() {
    int n; cin>>n;

    for (int i=0; i<n-1; i++) {
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    dfs(1,0,0);
    precompute(n);

    int q; cin>>q;

    for (int i=0; i<q; i++) {
        int a,b,c; cin>>a>>b>>c;
        int d = dist(a,b);
        if (d <= c) {
            print(b);
        } else {
            int l = lca(a,b);
            int x = dist(a,l);
            int y = dist(b,l);
            
            if (c <= x) {
                print(kth(a,c));
            } else {
                print(kth(b,d-c));
            }
        }
    }

    // for (int i=0; i<=n; i++) {
    //     print1(par[i]);
    // }
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifdef Local
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}