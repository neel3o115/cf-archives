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

void solve() {
    int n; cin>>n;
    vi a(n);

    for (int i=0; i<n; i++) cin>>a[i];
    sort(all(a));
    
    map<int, int> fr1;
    map<int, int> fr2;
    
    vi bad1;
    vi bad2;
    bool ne = true;
    bool je = true; 
    int nee = a[0];
    int jee = a[1];
    int hk = a[0];
    int kh = a[1];

    for (int i=2; i<n; i++) hk = gcd(hk, a[i]);
    for (int i=2; i<n; i++) kh = gcd(kh, a[i]);

    for (int i=0; i<n; i++) {
        if (i != 0) {
            int x = gcd(a[i], a[0]);
            fr1[x]++;

            if (x==1 and ne) {
                ne = false;
            } else {
                nee = gcd(nee, a[i]);
            }
        }
    }
    
    for (int i=0; i<n; i++) {
        if (i != 1) {
            int x = gcd(a[i], a[1]);
            fr2[x]++;

            if (x==1 and je) {
                je = false;
            } else {
                jee = gcd(jee, a[i]);
            }
        }
    }


    debug(fr1);
    debug(fr2);

    if (fr1[1] > 1 and fr2[1] > 1) {
        cout << 1;
        return; 
    } else {
        cout << max(nee, max(jee, max(hk, kh)));
    }

    // cout << nee;
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