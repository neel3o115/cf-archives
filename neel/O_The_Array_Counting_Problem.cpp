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

ll mod_mul(ll a, ll b, ll m = MOD) {
    return ((a % m) * (b % m)) % m;
}

ll mod_add(ll a, ll b, ll m = MOD) {
    return ((a % m) + (b % m)) % m;
}

ll mod_sub(ll a, ll b, ll m = MOD) {
    return ((a % m) - (b % m) + m) % m;
}

ll mod_pow(ll a, ll b, ll m = MOD) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1LL) res = mod_mul(res, a, m);
        a = mod_mul(a, a, m);
        b >>= 1LL;
    }
    return res;
}

ll mod_inv(ll a, ll m = MOD) {
    return mod_pow(a, m - 2, m); // Fermat's Little Theorem
}

ll mod_div(ll a, ll b, ll m = MOD) {
    return mod_mul(a, mod_inv(b, m), m);
}

const int N = 100005;

int fac[N], inv[N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precompute() {
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % MOD;

    inv[N - 1] = power(fac[N - 1], MOD - 2);

    for (int i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}

void solve() {
    int n; cin>>n;
    int res = 0;
    
    for (int i=0; i<n; i++) {
        int x = nCr(n-1,i);
        int y = nCr(n,i+1);
        
        if (i == 0) res = mod_add(res,mod_mul(x,y));
        else        res = mod_add(res,mod_mul(mod_mul(x,y),2));
    }

    print(res);
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifdef Local
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    precompute();
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