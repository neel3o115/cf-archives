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

const int N = 100005;
int SIEVE[N+1];

// O(nlog logn) approx O(n) 
void sieve() { 
    for (int x = 2; x <= N; x++) {
        if (SIEVE[x]) continue;
        for (int u = 2*x; u <= N; u += x) {
            SIEVE[u]++;
        }
    }
}


void solve() {
    sieve();
    int n, m; cin>>n>>m;
    vi a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
    vvi fac(100005);

    for (int i = 2; i < 100001; i++) {
        if (SIEVE[i] == 0) {
            for (int j = i; j < 100001; j+=i) {
                fac[j].pb(i);
            }
        }
    }

    print2(fac);

    set<int> st;
    for (int i = 1; i <= m; i++) st.insert(i);
    unordered_set<int> pr;

    for (int i = 0; i < n; i++) {
        for (int j: fac[a[i]]) {
            pr.insert(j);
        }
    }

    vi nee;
    for (int x = 1; x <= m; x++) {
        if (pr.count(x)) {
            for (int u = x; u <= m; u += x) {
                st.erase(u); 
            }
        }
    }

    // debug(st);

    // for (int i = 1; i <= m; i++) {  
    //     if (!st.count(i)) {
    //         nee.pb(i);
    //     } 
    // };

    cout << len(st) << endl;
    for (int i: st) {
        cout << i << endl;
    }
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

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