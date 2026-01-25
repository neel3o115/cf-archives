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

// -----------------------------------------------------------
// ----------------- MATRIX MULTIPLICATION -------------------
// -----------------------------------------------------------

vvi mat_mul(const vvi &A, const vvi &B, int mod = MOD) {
    int n = A.size();
    int p = B.size();
    int m = B[0].size();

    vvi R(n, vi(m, 0));

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < p; k++) {
            if (A[i][k] == 0) continue;
            int x = A[i][k];
            for (int j = 0; j < m; j++) {
                R[i][j] = (R[i][j] + x * B[k][j]) % mod;
            }
        }
    }
    return R;
}

vvi mat_pow(vvi M, long long exp, int mod = MOD) {
    int n = M.size();
    vvi R(n, vi(n, 0));

    for (int i = 0; i < n; i++) R[i][i] = 1;

    while (exp > 0) {
        if (exp & 1) R = mat_mul(R, M, mod);
        M = mat_mul(M, M, mod);
        exp >>= 1;
    }
    return R;
}

void solve() {
    vvi M = {{2, 1}, {1, 0}};            
    vvi V = {{1}, {0}};                
    int n; cin >> n;
    auto Mn = mat_pow(M, n-1);           
    auto ans = mat_mul(Mn, V);
    cout << ans[0][0];
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