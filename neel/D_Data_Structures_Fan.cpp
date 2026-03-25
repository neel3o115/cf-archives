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

int n, q;
void solve() {
    cin>>n;
    vi a(n);

    int B = sqrt(n)+1;
    vi b0(n/B+1, 0);
    vi b1(n/B+1, 0);
    vi flip(n/B+1,0);

    for (int i=0; i<n; i++) cin>>a[i];
    string s; cin>>s;
    vi sv(n);

    for (int i=0; i<n; i++) {
        if (s[i] == '0') {
            sv[i] = 0;
        } else {
            sv[i] = 1;
        }
    }

    for (int i = 0; i < n; i += 1) {
        if (s[i] == '0') b0[i/B] ^= a[i];
        else b1[i/B] ^= a[i];
    }

    cin>>q;

    for (int kk=0; kk<q; kk++) {
        int op; cin>>op;
        
        if (op == 1) {
            int l, r; cin>>l>>r;
            l--, r--;

            for (int i = l; i <= r;) {
                if (i % B == 0 && i + B - 1 <= r) {
                    swap(b0[i/B] , b1[i/B]);
                    // int xx = n-B*((i/B)+1);
                    // bit = bit ^ (blockbit << xx);
                    // flip[i/B] ^= 1;
                    i += B;
                } else {
                    b1[i/B] ^= a[i];
                    b0[i/B] ^= a[i];
                    sv[i] ^= 1;
                    i += 1;
                }
            }

        } else {
            int g; cin>>g;
            int res = 0;

            if (g == 0) {
                for (auto num : b0) {
                    res ^= num;
                }
            } else {
                for (auto num : b1) {
                    res ^= num;
                }
            }
            cout << res << " ";
        }
    }
    cout << endl;

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