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

unordered_map <string, int> dis1;
unordered_map <string, int> dis2;

vs fun(string s) {
    vs res = {};

    swap(s[0], s[1]);
    res.pb(s);
    swap(s[0], s[1]);

    swap(s[0], s[3]);
    res.pb(s);
    swap(s[0], s[3]);

    swap(s[1], s[2]);
    res.pb(s);
    swap(s[1], s[2]);

    swap(s[1], s[4]);
    res.pb(s);
    swap(s[1], s[4]);

    swap(s[2], s[5]);
    res.pb(s);
    swap(s[2], s[5]);

    swap(s[3], s[4]);
    res.pb(s);
    swap(s[3], s[4]);

    swap(s[3], s[6]);
    res.pb(s);
    swap(s[3], s[6]);

    swap(s[4], s[5]);
    res.pb(s);
    swap(s[4], s[5]);

    swap(s[4], s[7]);
    res.pb(s);
    swap(s[4], s[7]);

    swap(s[5], s[8]);
    res.pb(s);
    swap(s[5], s[8]);

    swap(s[6], s[7]);
    res.pb(s);
    swap(s[6], s[7]);

    swap(s[7], s[8]);
    res.pb(s);
    swap(s[7], s[8]);
    
    return res;
}

void solve() {
    string s = "";

    for (int i=0; i<9; i++) {
        char c; cin>>c;
        s.pb(c);
    }

    string a = "123456789";

    queue<pair<string, int>> qu1;
    queue<pair<string, int>> qu2;

    qu1.push({a, 0});
    dis1[a] = 0;

    qu2.push({s, 0});
    dis2[s] = 0;

    while (len(qu1) and len(qu2)) {
        pair<string, int> node1 = qu1.front();
        pair<string, int> node2 = qu2.front();

        string x1 = node1.first;
        int y1 = node1.second;
        qu1.pop();

        string x2 = node2.first;
        int y2 = node2.second;
        qu2.pop();

        if (dis1.count(x2)) {
            // debug(dis1);
            print(dis1[x2]+y2);
            return;
        }

        if (dis2.count(x1)) {
            // debug(dis2);
            print(dis2[x1]+y1);
            return; 
        }

        vs adj1 = fun(x1);
        vs adj2 = fun(x2);

        // print("step 1");
        for (string c1: adj1) {
            if (!dis1.count(c1)) {
                qu1.push({c1, y1+1});
                dis1[c1] = y1+1;
            }
        }
        
        // print("step 2");
        for (string c2: adj2) {
            if (!dis2.count(c2)) {
                qu2.push({c2, y2+1});
                dis2[c2] = y2+1;
            }
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