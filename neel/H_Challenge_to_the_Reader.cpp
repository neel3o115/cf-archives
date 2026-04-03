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

vi even;
vi odd;
vi rl;
vi neven;
vi nodd;
map<int, int> nee;

int check(int x) {
    auto it = lower_bound(begin(rl),end(rl),x);
    return nee[*it];
}

void set_maker() {
    int x = 1;
    int y = 2;
    int i = 1;
    while (x <= 200000) {
        if (x % 2 == 0) {
            even.pb(x);
            nodd.pb(x-1);
            rl.pb(x);
        } else {
            odd.pb(x);
            neven.pb(x-1);
            rl.pb(x);
        }

        nee[x] = i++;
        x += y;
        y++;
    }
}

vector<int> niga,pos;

void can_make(int target) {
    if (target <= 0) {
        return;
    }

    int x = check(target);

    niga.pb(x);

    can_make(target-x);
}

void solve() {
    int n; cin >> n;

    if (nee.count(n)) {
        print(nee[n]);
        cout << 1;
        for (int i=2; i<=nee[n]; i++) {
            cout << "+" << i;
        }
        cout << endl;

        return;
    } else if (nee.count(2-n)) {
        print(nee[2-n]);
        cout << 1;
        for (int i=2; i<=nee[2-n]; i++) {
            cout << "-" << i;
        }
        cout << endl;
    } else {
        int y;
        if () {
 
        } else {

        }

        sort(all(niga));
        bool one = false;

        for (int i = 1; i <= y; ++i) {
            auto it = lower_bound(begin(niga),end(niga),i);

            if (*it != i) {
                pos.pb(i);
            }
            if (i == 1 && (*it) == 1) {
                one = true;
            }
        }

        if (one) {
            y = niga[niga.size() - 1];
            bool continuous = true;
            int missing;
            for (int i = 2; i <= y; ++i) {
                auto it = lower_bound(begin(niga),end(niga),i);
                if (*it != i) {
                    missing = i;
                    continuous = false;
                    break;
                }



                if (!continuous) {
                    pos.pb(1);
                    pos.pb(y - 1);
                } else {
                    
                }

            }
        }




    }



    // debug(even);
    // debug(neven);
    // debug(odd);
    // debug(nodd);
    // debug(nee);
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
    set_maker();
    while (t--) {
        solve();
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}