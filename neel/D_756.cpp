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

vector<int> factors(int n) {
    vector<int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

void solve() {
    int n; cin>>n;
    map<int, int> mp;

    for (int i = 2; i <= n; i++) {
        vi f = factors(i);
        for (int j: f) {
            mp[j]++;
        }
    }

    map<int, int> fr;

    for (auto it: mp) {
        int x = it.second;
        if (x >= 2) fr[2]++;
        if (x >= 4) fr[4]++;
        if (x >= 14) fr[14]++;
        if (x >= 24 ) fr[24]++;
        if (x >= 74) fr[74]++;
    }

    int y = fr[2]-2;
    int h = fr[4];
    int a = (h*(h-1)/2)*(y);
    int b = fr[24]*(fr[2]-1);
    int c = fr[14]*(fr[4]-1);
    int d = fr[74];


    cout << a+b+c+d;
    // debug(fr);
    // debug(mp);
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