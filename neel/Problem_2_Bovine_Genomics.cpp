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
    map<char,int> c2i;

    c2i['A'] = 0;
    c2i['C'] = 1;
    c2i['G'] = 2;
    c2i['T'] = 3;

    vvi spoty_cow(n, vi(m));
    vvi plain_cow(n, vi(m));

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char gene; cin>>gene;
            spoty_cow[i][j] = c2i[gene];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char gene; cin>>gene;
            plain_cow[i][j] = c2i[gene];
        }
    }

    int res = 0;

    for (int i=0; i<m; i++) {
        vi spc(4,0); 
        vi plc(4,0);

        for (int j=0; j<n; j++) {
            spc[spoty_cow[j][i]] = 1;
        }

        for (int j=0; j<n; j++) {
            plc[plain_cow[j][i]] = 1;
        }

        int found = true;

        for (int k=0; k<4; k++) {
            if (spc[k] and plc[k]) found = false;
        }

        if (found) res++;
    }

    cout << res;
    // print2(spoty_cow);
    // space;
    // print2(plain_cow);
}

int32_t main(){
    // cout << fixed << setprecision(10);
        freopen("cownomics.in", "r+", stdin);
        freopen("cownomics.out", "w+", stdout);

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