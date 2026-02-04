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

set<int> factors(int n) {
    set<int> f;
    int N = n;
    for (int x = 2; x*x <= N; x++) {
        while (n%x == 0) {
            f.insert(x);
            n /= x;
        }
    }

    if (n > 1) f.insert(n);
    return f;
}

void solve() {
    int n,m; cin>>n>>m;
    map<int,set<int>> fac;

    for (int i=0; i<n; i++) {
        char o; 
        int x;
        cin>>o>>x;

        set<int> nee = factors(x);

        if (o == '+') {
            bool conflict = false;
            for (auto it:nee) {
                if (fac.count(it)) {
                    conflict = true;
                    cout << "Conflict with " << *fac[it].begin() << endl;
                }
            }

            if (!conflict) {
                for (auto it:nee) {
                    fac[it].insert(x);
                }
                print("Success");
            }
        } else {
            bool conflict = false;
            for (auto it:nee) {
                if (!fac.count(it)) {
                    conflict = true;
                    print("Already off");
                }
            }

            if (!conflict) {
                for (auto it:nee) {
                    fac[it].erase(x);
                }
                print("Success");
            }
        }
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