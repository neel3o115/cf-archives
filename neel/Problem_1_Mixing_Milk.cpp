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
    vi cap(4,0);
    vi crr(4,0);

    for (int i=1; i<=3; i++) {
        int a,b; cin>>a>>b;
        cap[i] = a;
        crr[i] = b;
    }

    for (int i=0; i<100; i++) {
        int x,y;
        int crrx, crry;

        if (i%3 == 0) {
            x=1; y=2;
            crrx = crr[x]; 
            crry = crr[y];

            crr[y] = min((crrx+crry), cap[y]);
            crr[x] = max(0LL, (crrx-cap[y]+crry));

        } else if (i%3 == 1) {
            x=2; y=3;
            crrx = crr[x]; 
            crry = crr[y];

            crr[y] = min((crrx+crry), cap[y]);
            crr[x] = max(0LL, (crrx-cap[y]+crry));

        } else if (i%3 == 2) {
            x=3; y=1;
            crrx = crr[x]; 
            crry = crr[y];

            crr[y] = min((crrx+crry), cap[y]);
            crr[x] = max(0LL, (crrx-cap[y]+crry));
        }
    }

    cout << crr[1] << endl;
    cout << crr[2] << endl;
    cout << crr[3];
}

int32_t main(){
    // cout << fixed << setprecision(10);
        freopen("mixmilk.in", "r+", stdin);
        freopen("mixmilk.out", "w+", stdout);

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