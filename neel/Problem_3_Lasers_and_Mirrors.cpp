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

int n, a, b, c, d;
map<int, set<vi>> adjx;
map<int, set<vi>> adjy;
map<pii, int> vis;

void solve() {
    cin>>n>>a>>b>>c>>d;

    adjx[a].insert({a,b});
    adjy[b].insert({a,b});
    adjx[c].insert({c,d});
    adjy[d].insert({c,d});
    vis[{a,b}] = -1;
    vis[{c,d}] = -1;

    for (int i=0; i<n; i++) {
        int x, y; cin>>x>>y;
        adjx[x].insert({x,y});
        adjy[y].insert({x,y});
        vis[{x,y}] = -1;
    }

    // debug(adjx);
    // debug(adjy);

    queue<vi> qu;
    qu.push({a,b,0});
    vis[{a,b}] = 0;
    adjx[a].erase({a,b});
    adjy[b].erase({a,b});

    while (len(qu)) {
        vi node = qu.front();
        qu.pop();

        vvi popx;
        vvi popy;

        for (vi it: adjx[node[0]]) {
            if (vis[{it[0], it[1]}] == -1) {
                qu.push({it[0],it[1],node[2]+1});
                vis[{it[0], it[1]}] = node[2]+1;
                popx.pb({it[0],it[1]});
            }
        }

        for (vi it: adjy[node[1]]) {
            if (vis[{it[0], it[1]}] == -1) {
                qu.push({it[0],it[1],node[2]+1});
                vis[{it[0], it[1]}] = node[2]+1;
                popy.pb({it[0],it[1]});
            }
        }

        for (vi it: popx) {
            adjx[node[0]].erase({it[0],it[1]});
        }

        for (vi it: popy) {
            adjy[node[1]].erase({it[0],it[1]});
        }
    }

    if (vis[{c,d}]==-1) {
        cout << -1;
        return;
    }

    // debug(vis);
    // debug(adjx);

    cout << vis[{c, d}]-1;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("lasers.in", "r+", stdin);
    freopen("lasers.out", "w+", stdout);

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