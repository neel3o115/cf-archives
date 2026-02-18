#include <bits/stdc++.h>
using namespace std;

// ---------- shortcut macros ----------
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define execute ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// ----------- constants -----------
#define PI 3.14159265358979323846
#define INF 1e18
#define MOD 1000000007
#define MOD2 998244353

// ---------- type aliases ----------
#define ll long long
#define int long long
#define endl '\n'

// ---------- input macros ----------
#define msb(x) (x == 0 ? -1 : 1ll<<(63 - __builtin_clzll(x)))      
#define lsb(x) (x == 0 ? -1 : 1ll<<(__builtin_ctzll(x)))   
#define pc(x) (__builtin_popcountll(x))
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a,b) * b;}
ll mod_mul(ll a,ll b, ll m = MOD) {return ((a % m) * (b % m)) % m;}
ll mod_add(ll a,ll b, ll m = MOD) {return ((a % m) + (b % m)) % m;}
ll mod_sub(ll a,ll b, ll m = MOD) {return ((a % m) - (b % m) + m) % m;}
ll mod_pow(ll a,ll b, ll m = MOD) {ll res = 1;a %= m;while (b) {if (b & 1ll) res = res * a % m;a = mod_mul(a, a, m);b >>= 1ll;}return res;}
ll mod_inv(ll a, ll m = MOD) {return mod_pow(a, m - 2, m);}  // fermat's little theorem
ll mod_div(ll a, ll b, ll m = MOD) {return mod_mul(a, mod_inv(b,m));}


const int N = 1e5 + 10;
int f[N];
int inv[N];

void precompute() {
    f[0] = 1;
    inv[0] = mod_inv(f[0],MOD2);
    for (int i = 1; i < N; ++i) {
        f[i] = mod_mul(f[i-1],i,MOD2);
        inv[i] = mod_inv(f[i],MOD2);
    }
}

int nCr(int n, int r) {
    return mod_mul(f[n],mod_mul(inv[r],inv[n-r],MOD2),MOD2);
}

void solve() {
    int n; cin >> n;

    for (int x = 1; x <= n; ++x) {
        if (n <= 2 * x - 2) {
            cout << 0 << ' ';
        } else {
            int rest = n - (2 * x - 2);
            int s = x - 1;
            int g = n - s - 1;
            int res = mod_mul(mod_mul(nCr(g-1,x-2),f[2 * x - 2],MOD2),f[rest + 1],MOD2);
            cout << res << ' ';
        }
    }
    cout << endl;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    // freopen("input.txt", "r+", stdin);
    // freopen("output.txt", "w+", stdout);

    execute
    int t = 1;
    precompute();
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}