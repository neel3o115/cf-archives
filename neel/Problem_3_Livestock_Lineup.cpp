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
    vi a(8);

    map<string,int> mp;

    mp["Beatrice"] = 0;
    mp["Belinda"] = 1;
    mp["Bella"] = 2;
    mp["Bessie"] = 3;
    mp["Betsy"] = 4;
    mp["Blue"] = 5;
    mp["Buttercup"] = 6;
    mp["Sue"] = 7;

    map<int,string> pm;

    pm[0] = "Beatrice";
    pm[1] = "Belinda";
    pm[2] = "Bella";
    pm[3] = "Bessie";
    pm[4] = "Betsy";
    pm[5] = "Blue";
    pm[6] = "Buttercup";
    pm[7] = "Sue";

    vvi rule(n);

    for (int i=0; i<n; i++) {
        vector<string> word(6);
        for (int j=0; j<6; j++) cin>>word[j];

        vi umm;
        umm.pb(mp[word[0]]);
        umm.pb(mp[word[5]]);

        sort(all(umm));
        rule[i] = umm;
    }

    for (int i=0; i<8; i++) a[i] = i;

    set<vi> res;

    do {
        bool check = true;

        for (int i=0; i<n; i++) {
            int idx0 = -1;
            int idx1 = -1;

            for (int j=0; j<8; j++) {
                if (a[j] == rule[i][0]) {
                    idx0 = j;
                    break;
                }
            }

            for (int j=0; j<8; j++) {
                if (a[j] == rule[i][1]) {
                    idx1 = j;
                    break;
                }
            }

            if (abs(idx0-idx1) != 1) {
                check = false;
                break;
            }
        }

        if (check) {
            res.insert(a);
        }
    } while (next_permutation(a.begin(), a.end()));

    for (auto i: res) {
        for (auto j: i) {
            cout << pm[j] << endl;
        }
        break;
    }
}

int32_t main(){
    // cout << fixed << setprecision(10);
        freopen("lineup.in", "r+", stdin);
        freopen("lineup.out", "w+", stdout);

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