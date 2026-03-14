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
#define inf INT_MAX/2

// ---------- input macros ----------
#define msb(x) (x == 0 ? -1 : 1ll<<(63 - __builtin_clzll(x)))      
#define lsb(x) (x == 0 ? -1 : 1ll<<(__builtin_ctzll(x)))   
#define pc(x) (__builtin_popcountll(x))
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a * b / gcd(a, b);}

int n,x,y,z;
int a[51];
int dp[51][51][51];
bool vis[51][51];

int rec(int l, int r, int v) {
    if (vis[l][r]) return dp[l][r][v];

    if (l == r) {
        if (v == a[l]) return dp[l][r][v] = 0;
        return dp[l][r][v] = inf;
    }

    if (l+1 == r) {
        vis[l][r] = true;
        if (v == (a[l]*x+a[r]*y+z)%50) return dp[l][r][v] = a[l]*a[r];
    }

    for (int i=l; i<r; i++) {
        for (int j=0; j<50; j++) {
            for (int k=0; k<50; k++) {
                int left = rec(l,i,j);
                int rght = rec(i+1,r,k);
                int res = left+rght+j*k;
                dp[l][r][(x*j+y*k+z)%50] = min(dp[l][r][(x*j+y*k+z)%50],res);
            }
        }
    }

    vis[l][r] = true;
    return dp[l][r][v];
}

void solve() {
    cin>>n>>x>>y>>z;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<50; k++) dp[i][j][k] = inf; 
        }
    }

    for (int i=0; i<n; i++) cin>>a[i];

    int ans = inf;
    for (int i=0; i<50; i++) {
        ans = min(rec(0, n-1, i), ans);
    };

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<50; k++) {
                cout << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    cout << ans << endl;
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