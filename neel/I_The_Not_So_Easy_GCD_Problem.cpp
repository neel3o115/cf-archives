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

const int MAXA = 200000;
vector<int> spf(MAXA+1);

int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

map<int,int> factorise(int x) {
    map<int,int> mp;
    while (x > 1) {
        int p = spf[x];
        mp[p]++;
        x /= p;
    }
    return mp;
}

void solve() {
    for (int i=1; i<=MAXA; i++) spf[i] = i;
    for (int i=2; i*i<=MAXA; i++) {
        if (spf[i] == i) {
            for (int j=i*i; j<=MAXA; j+=i) {
                if (spf[j]==j) spf[j] = i;
            }
        }
    }

    int n,q; cin>>n>>q;

    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<map<int,int>> factors(n + 1);

    map<int, multiset<int>> freq;
    map<int, int> current_min;

    for (int i = 1; i <= n; i++) {
        factors[i] = factorise(a[i]);
        for (auto [p, cnt] : factors[i]) {
            freq[p].insert(cnt);
        }
    }

    int gcd_val = 1;

    for (auto &[p, ms] : freq) {
        if ((int)ms.size() == n) {
            int mn = *ms.begin();
            current_min[p] = mn;
            gcd_val = gcd_val * mod_pow(p, mn) % MOD;
        }
    }

    while (q--) {
        int i,x; cin>>i>>x;

        auto newf = factorise(x);

        for (auto &[p,add] : newf) {
            int old_cnt = factors[i][p];

            if (old_cnt > 0) {
                freq[p].erase(freq[p].find(old_cnt));
            }

            int new_cnt = old_cnt + add;
            factors[i][p] = new_cnt;
            freq[p].insert(new_cnt);

            if ((int)freq[p].size() == n) {
                int new_min = *freq[p].begin();
                int prev_min = current_min[p];

                if (new_min > prev_min) {
                    gcd_val = gcd_val*mod_pow(p,new_min-prev_min)%MOD;
                    current_min[p] = new_min;
                }
            }
        }

        print(gcd_val);
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
}