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



void solve() {
    int n; cin >> n; 
    vector<int> p,s;
    set<int> checkp,checks,checkoddp,checkodds;
    bool check = true;

    for (int i = 1; i <= 2 * n; ++i) {
        if (i % 2 == 0) {
            checkp.insert(i);
            checks.insert(i);
        } else {
            checkoddp.insert(i);
            checkodds.insert(i);
        }
    }

    for (int i = 0; i < n; ++i) {
        int pp,ss; cin >> pp >> ss;
        p.pb(pp);
        s.pb(ss);

        if (pp % 2 == 0 && ss % 2 == 0) {
            if (pp != ss) {
                check = false;
            }
        } else {
            check = false;
        }
        checkp.erase(pp);
        checks.erase(ss);
        checkodds.erase(ss);
        checkoddp.erase(pp);
    }

    if (checkp.size()) {
        cout << "YES" << endl;
        int touse = *begin(checkp);
        for (int i = 1; i <= n; ++i) {
            cout << touse/2 << ' ' << i << endl;
        }
    } else if (checks.size()) {
        cout << "YES" << endl;
        int touse = *begin(checks);
        for (int i = 1; i <= n; ++i) {
            cout << i << ' ' << touse/2 << endl;
        }
    } else {
        if (n == 1) {
            cout << "NO" << endl;
            return;
        }
        if (check) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) {
                cout << i << ' ' << n - i + 1 << endl;
            }
            return;
        }
        cout << "NO" << endl;
    }
    
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