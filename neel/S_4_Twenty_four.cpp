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

#include <bits/stdc++.h>
using namespace std;

bool apply(int a, int b, int op, int &res) {
    if (op == 0) { res = a + b; return true; }
    if (op == 1) { res = a - b; return true; }
    if (op == 2) { res = a * b; return true; }
    if (op == 3) {
        if (b == 0) return false;
        if (a % b != 0) return false;
        res = a / b;
        return true;
    }
    return false;
}

void solve() {
    vector<int> a(4);
    for (int i = 0; i < 4; i++) cin >> a[i];

    int best = 0;
    sort(a.begin(), a.end());

    do {
        for (int o1 = 0; o1 < 4; o1++)
        for (int o2 = 0; o2 < 4; o2++)
        for (int o3 = 0; o3 < 4; o3++) {

            int x, y, z;

            // 1) ((a b) c) d
            if (apply(a[0], a[1], o1, x) &&
                apply(x, a[2], o2, y) &&
                apply(y, a[3], o3, z))
                if (z <= 24) best = max(best, z);

            // 2) (a (b c)) d
            if (apply(a[1], a[2], o2, x) &&
                apply(a[0], x, o1, y) &&
                apply(y, a[3], o3, z))
                if (z <= 24) best = max(best, z);

            // 3) a ((b c) d)
            if (apply(a[1], a[2], o2, x) &&
                apply(x, a[3], o3, y) &&
                apply(a[0], y, o1, z))
                if (z <= 24) best = max(best, z);

            // 4) a (b (c d))
            if (apply(a[2], a[3], o3, x) &&
                apply(a[1], x, o2, y) &&
                apply(a[0], y, o1, z))
                if (z <= 24) best = max(best, z);

            // 5) (a b) (c d)
            if (apply(a[0], a[1], o1, x) &&
                apply(a[2], a[3], o3, y) &&
                apply(x, y, o2, z))
                if (z <= 24) best = max(best, z);
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << best << "\n";
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifdef Local
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    int t = 1;
    cin >> t;   
    while (t--) {
        solve();
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}