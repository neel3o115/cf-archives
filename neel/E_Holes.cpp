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
    int n,m; cin>>n>>m;
    vi pwr(n);
    vi nxt(n);
    vi cnt(n);

    int sq = sqrt(n)+1;
    if (n == 1) sq = 1;
    for (int i=0; i<n; i++) cin>>pwr[i];

    for (int i=n-1; i>=0; i--) {
        int nee = i+pwr[i];

        if (nee >= n) {
            nxt[i] = n;
            cnt[i] = 1;
        } else if (i/sq == nee/sq) {
            nxt[i] = nxt[nee];
            cnt[i] = cnt[nee]+1;
        } else {    
            nxt[i] = nee;
            cnt[i] = 1;
        }
    }

    while (m--) {
        int qu; cin>>qu;
        if (qu) {
            int a; cin>>a;
            a--;
            int step = 0;

            while (nxt[a] < n) {
                step += cnt[a];
                a = nxt[a];
            }

            step += cnt[a];
            if (a+pwr[a] >= n) {
                cout << a+1 << " " << step << endl;
            } else {
                while (a+pwr[a] < n) {
                    a = a+pwr[a];
                }
                cout << a+1 << " " << step << endl;
            }
        } else {
            int a,b; cin>>a>>b;
            a--;
            pwr[a] = b;

            for (int i=a; i>=sq*(a/sq); i--) {
                int nee = i+pwr[i];

                if (nee >= n) {
                    nxt[i] = n;
                    cnt[i] = 1;
                } else if (i/sq == nee/sq) {
                    nxt[i] = nxt[nee];
                    cnt[i] = cnt[nee]+1;
                } else {    
                    nxt[i] = nee;
                    cnt[i] = 1;
                }
            }
        }
        
        // debug(pwr);
        // debug(nxt);
        // debug(cnt);
        // debug(" ");
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
};