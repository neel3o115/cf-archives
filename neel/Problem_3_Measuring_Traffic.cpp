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
    int n; cin>>n;
    vvi road(n+1);

    for (int i=1; i<=n; i++) {
        string s; cin>>s;
        int x,y; cin>>x>>y;

        if (s == "on") road[i] = {1,x,y};
        else if (s == "off") road[i] = {-1,x,y};
        else if (s == "none") road[i] = {0,x,y};
    }

    int x,y;

    int idx = n;

    while ((idx > 1) and (road[idx][0] != 0)) idx--;

    x = road[idx][1];
    y = road[idx][2];

    for (int i=idx; i>0; i--) {
        if (road[i][0] == 0) {
            x = max(x, road[i][1]);
            y = min(y, road[i][2]);
        } else if (road[i][0] == -1) {
            x += road[i][1];
            y += road[i][2];
        } else if (road[i][0] == 1) {
            x -= road[i][2];
            y -= road[i][1];
        }
    }


    x = max(x, 0LL);
    y = max(y, 0LL);
    cout << x << " " << y << endl;

    idx = 1;

    while ((idx < n) and (road[idx][0] != 0)) idx++;

    x = road[idx][1];
    y = road[idx][2];

    for (int i=idx; i<=n; i++) {
        if (road[i][0] == 0) {
            x = max(x, road[i][1]);
            y = min(y, road[i][2]);
        } else if (road[i][0] == 1) {
            x += road[i][1];
            y += road[i][2];
        } else if (road[i][0] == -1) {
            x -= road[i][2];
            y -= road[i][1];
        }
    };

    x = max(x, 0LL);
    y = max(y, 0LL);
    cout << x << " " << y << endl;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("traffic.in", "r+", stdin);
    freopen("traffic.out", "w+", stdout);

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