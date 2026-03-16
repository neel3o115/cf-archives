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
    vi a(n);

    for (int i=0; i<n; i++) cin>>a[i];
    map<int, int> fr;

    int s1 = 0;
    int s2 = 0;

    vi nee;
    int cnt = 0;

    for (int i=0; i<n; i++) fr[a[i]]++;

    for (auto it: fr) {
        int key = it.first;
        int val = it.second;
        if (fr[key]%2==0) cnt += fr[key];

        s1 += key * (val/2);
        s2 += key * (val/2);
        fr[key] = val%2;

        if (fr[key]) nee.pb(key);
    }

    sort(all(nee));
    reverse(all(nee));

    int s3 = 0;
    int s4 = 0;

    if (len(nee) == 0) {
        if (cnt == 2) {
            print(0);
        } else {
            print(s1+s2);
        }
    }

    if (len(nee) == 1) {
        s3 = nee[0];

        if (s1+s2 > s3) {
            print(s1+s2+s3+s4);
        } else {
            if (cnt == 2) {
                print(0);
            } else {
                print(s1+s2);
            }
        }
    }

    if (len(nee) > 1) {
        s3 = nee[0];
        s4 = nee[1];

        if (s3 < s4) {
            swap(s3, s4);
        }

        if ((s1+s2+s3 > s4) and (s1+s2+s4 > s3)) {
            print(s1+s2+s3+s4);
        } else if ((s1+s2 > s3)) {
            print(s1+s2+s3);
        } else if ((s1+s2 > s4)) {
            print(s1+s2+s4);
        } else {
            print(0);
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