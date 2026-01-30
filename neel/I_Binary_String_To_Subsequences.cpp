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
    string s; cin>>s;
    set<int> zoro;
    set<int> mono;
    
    vi res(n);
    for (int i=0; i<n; i++) {
        if (s[i] == '0') {
            zoro.insert(i);
        } else {
            mono.insert(i);
        }
    }

    int par = 1;
    if (mono.count(0)) {
        mono.erase(0);
        par = 0;
    } else {
        zoro.erase(0);
    }
    int crr = 0;
    int itter = 1;
    res[crr] = itter;

    while ((len(zoro) or len(mono))) {
        if (par == 0) {
            auto it = zoro.upper_bound(crr);
            if (it != zoro.end()) {
                crr = *it;
                res[crr] = itter;
                zoro.erase(crr);
                par = 1;
            }

            else {
                itter++;
                if (len(zoro) == 0) {
                    crr = *mono.begin();
                    res[crr] = itter;
                    par = 0;
                    mono.erase(crr);
                } else if (len(mono) == 0) {
                    crr = *zoro.begin();
                    res[crr] = itter;
                    par = 1;
                    zoro.erase(crr);
                } else {
                    if (*mono.begin() < *zoro.begin()) {
                        crr = *mono.begin();
                        par = 0;
                        mono.erase(crr);
                    } else {
                        crr = *zoro.begin();
                        par = 1;
                        zoro.erase(crr);
                    }
                    res[crr] = itter;
                }
            }

        } else {
            auto it = mono.upper_bound(crr);
            if (it != mono.end()) {
                crr = *it;
                res[crr] = itter;
                mono.erase(crr);
                par = 0;
            }
            
            else {
                itter++;
                if (len(zoro) == 0) {
                    crr = *mono.begin();
                    res[crr] = itter;
                    par = 0;
                    mono.erase(crr);
                } else if (len(mono) == 0) {
                    crr = *zoro.begin();
                    res[crr] = itter;
                    par = 1;
                    zoro.erase(crr);
                } else {
                    if (*mono.begin() < *zoro.begin()) {
                        crr = *mono.begin();
                        par = 0;
                        mono.erase(crr);
                    } else {
                        crr = *zoro.begin();
                        par = 1;
                        zoro.erase(crr);
                    }
                    res[crr] = itter;
                }
            }
        }
    }

    print(*max_element(all(res)))
    print1(res);
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