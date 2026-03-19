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

    if (n == 1) {
        print(1); 
        return;
    }

    if (n < 4) {
        print("NO SOLUTION");
        return;
    }

    set<int> eve;
    set<int> odd;

    for (int i=1; i<=n; i++) {
        if (i%2 == 0) eve.insert(i);
        else odd.insert(i);
    }

    vi res;

    while (!eve.empty() and !odd.empty()) {
        auto eit = eve.begin();
        auto oit = odd.begin();

        if (len(res) > 0) {
            if (abs(res[len(res)-1]-(*eit)) == 1) {
                res.pb(*oit);
                odd.erase(oit);
                continue;
            } else if (abs(res[len(res)-1]-(*oit)) == 1) {
                res.pb(*eit);
                eve.erase(eit);
                continue;
            }
        }

        if (*eit < *oit) {
            res.pb(*eit);
            eve.erase(eit);
        } else {
            res.pb(*oit);
            odd.erase(oit);
        }
    }

    if (eve.empty() and odd.empty()) {
        print1(res);
        return;
    }

    if (eve.empty()) {
        auto oit = odd.begin();

        if (abs(res[len(res)-1]-(*oit)) != 1) {
            for (auto it: odd) res.pb(it);
            print1(res);
            return;
        } else {

            vi nee;
            for (auto it: odd) nee.pb(it);

            for (int i=len(res)-1; len(nee)<4; i--) { 
                nee.pb(res[i]);
                res.pop_back();
            } 

            sort(all(nee));

            do {
                bool check = true;

                if ((len(res) > 0) and (abs(res[len(res)-1]-nee[0]) == 1)) {
                    check = false;
                }

                for (int i=0; i<len(nee)-1; i++) {
                    if (abs(nee[i]-nee[i+1]) == 1) {
                        check = false; 
                        break;
                    } 
                }

                if (check) {
                    for (int i: nee) res.pb(i);
                    print1(res);
                    break;
                }

            } while (next_permutation(nee.begin(), nee.end()));
        }
    }

    if (odd.empty()) {
        auto eit = eve.begin();

        if (abs(res[len(res)-1]-(*eit)) != 1) {
            for (auto it: eve) res.pb(it);
            print1(res);
            return;
        } else {

            vi nee;
            for (auto it: eve) nee.pb(it);

            for (int i=len(res)-1; len(nee)<4; i--) { 
                nee.pb(res[i]);
                res.pop_back();
            } 

            sort(all(nee));

            do {
                bool check = true;

                if ((len(res) > 0) and (abs(res[len(res)-1]-nee[0]) == 1)) {
                    check = false;
                }

                for (int i=0; i<len(nee)-1; i++) {
                    if (abs(nee[i]-nee[i+1]) == 1) {
                        check = false; 
                        break;
                    } 
                }

                if (check) {
                    for (int i: nee) res.pb(i);
                    print1(res);
                    break;
                }

            } while (next_permutation(nee.begin(), nee.end()));
        }
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