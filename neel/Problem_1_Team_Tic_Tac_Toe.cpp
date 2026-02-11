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
    vvc grid(3, vc(3,'_'));

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            char c; cin>>c;
            grid[i][j] = c;
        }
    }

    vector<set<char>> row(3);
    vector<set<char>> col(3);

    set<char> dia1; 
    set<char> dia2;

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            row[i].insert(grid[i][j]);
        }
    }

    for (int j=0; j<3; j++) {
        for (int i=0; i<3; i++) {
            col[j].insert(grid[i][j]);
        }
    }



    dia1.insert(grid[0][0]);
    dia1.insert(grid[1][1]);
    dia1.insert(grid[2][2]);

    dia2.insert(grid[0][2]);
    dia2.insert(grid[1][1]);
    dia2.insert(grid[2][0]);

    set<set<char>> one;
    set<set<char>> two;

    for (int i=0; i<3; i++) {
        if (len(row[i]) == 1) one.insert(row[i]);
        if (len(row[i]) == 2) two.insert(row[i]);
    }

    for (int i=0; i<3; i++) {
        if (len(col[i]) == 1) one.insert(col[i]);
        if (len(col[i]) == 2) two.insert(col[i]);
    }

    if (len(dia1) == 1) one.insert(dia1);
    if (len(dia1) == 2) two.insert(dia1);
    if (len(dia2) == 1) one.insert(dia2);
    if (len(dia2) == 2) two.insert(dia2);

    cout << len(one) << endl << len(two);
}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("tttt.in", "r+", stdin);
    freopen("tttt.out", "w+", stdout);

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