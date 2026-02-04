#include <bits/stdc++.h>
using namespace std;

// ---------- debug utilities ----------
#ifndef ONLINE_JUDGE
    #include <debug.cpp>
    auto start = chrono::high_resolution_clock::now();
#else 
    #define debug(...)
    #define debugArr(...)
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
ll mod_mul(ll a,ll b) {return ((a % MOD) * (b % MOD)) % MOD;}
ll mod_add(ll a,ll b) {return ((a % MOD) + (b % MOD)) % MOD;}
ll mod_sub(ll a,ll b) {return ((a % MOD) - (b % MOD) + MOD) % MOD;}
ll mod_pow(ll a,ll b, ll m = MOD) {ll res = 1;a %= m;while (b) {if (b & 1ll) res = res * a % m;a = mod_mul(a, a);b >>= 1ll;}return res;}
ll mod_inv(ll a, ll m = MOD) {return mod_pow(a, m - 2, m);}  // fermat's little theorem
ll mod_div(ll a, ll b) {return mod_mul(a, mod_inv(b));}

map<int, int> factors(int n) {
    map<int, int> f;
    int N = n;

    for (int x = 2; x*x <= N; x++) {
        while (n%x == 0) {
            f[x]++;
            n /= x;
        }
    }

    if (n > 1) f[n]++;
    return f;
}

int fun(int p, int k, int b) {
    // debug(p, p%MOD);
    if(p%MOD == 1) {
        return (b*k+1) % MOD;
    }
    int res = mod_mul(mod_mul(mod_pow(mod_pow(p, k), b), p)+ MOD-1, mod_pow(p-1, MOD-2));
    // int res = (mod_pow(p, k*b+1) + MOD - 1) * mod_pow(p-1, MOD-2) % MOD;
    return res;
}

void solve() {
    int a, b; cin>>a>>b;
    map<int, int> f = factors(a);

    // b %= (MOD-1);
    int ans = 1;

    for (auto it: f) {
        ans = mod_mul(ans, fun(it.first, it.second, b));
    }

    debug(f);

    // cout << mod_pow(mod_pow(44000000309,2),9999999999999995) - 1;

    // cout << (15 * 44000000309);

    cout << ans <<endl;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("sumdiv.in", "r+", stdin);
    freopen("sumdiv.out", "w+", stdout);

    execute
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}