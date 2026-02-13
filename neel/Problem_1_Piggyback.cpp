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

int a, b, c, n, m;
vvi adj(40001);

void solve() {
    cin >> a >> b >> c >> n >> m;
    
    for (int i=0; i<m; i++) {
        int x, y; cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vi visa(n+1, -1);
    vi visb(n+1, -1);
    vi visc(n+1, -1);

    queue<vi> qu;
    qu.push({1,0});
    visa[1] = 0;

    while (len(qu)) {
        vi now = qu.front();
        int node = now[0];
        int dist = now[1];
        qu.pop();

        for (int cld: adj[node]) {
            if (visa[cld] == -1) {
                qu.push({cld, dist+1});
                visa[cld] = a*(dist+1);
            }
        }
    }

    qu.push({2,0});
    visb[2] = 0;

    while (len(qu)) {
        vi now = qu.front();
        int node = now[0];
        int dist = now[1];
        qu.pop();

        for (int cld: adj[node]) {
            if (visb[cld] == -1) {
                qu.push({cld, dist+1});
                visb[cld] = b*(dist+1);
            }
        }
    }

    qu.push({n,0});
    visc[n] = 0;

    while (len(qu)) {
        vi now = qu.front();
        int node = now[0];
        int dist = now[1];
        qu.pop();

        for (int cld: adj[node]) {
            if (visc[cld] == -1) {
                qu.push({cld, dist+1});
                visc[cld] = c*(dist+1);
            }
        }
    }

    int ans = INT_MAX;

    for (int i=1; i<=n; i++) {
        ans = min(ans, visa[i]+visb[i]+visc[i]);
    }

    cout << ans << endl;
    // print1(visa);
    // print1(visb);
    // print1(visc);
    // print2(adj);
}

int32_t main(){
    // cout << fixed << setprecision(10);
    // #ifdef Local
    freopen("piggyback.in", "r+", stdin);
    freopen("piggyback.out", "w+", stdout);
    // #endif

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