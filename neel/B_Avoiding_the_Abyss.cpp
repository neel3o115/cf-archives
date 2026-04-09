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
    int xs,ys,xt,yt,xp,yp;
    cin >> xs >> ys >> xt >> yt >> xp >> yp;

    vector<array<int,3>> pts = {{xs,ys,1},{xt,yt,2},{xp,yp,3}};

    sort(begin(pts),end(pts));

    // debug(pts);

    if (pts[0][2] == 1) {
        if (yp > yt) {
            cout << 3 << endl;
            cout << -100000 << ' ' << ys << endl;
            cout << -100000 << ' ' << -100000 << endl;
            cout << xt << ' ' << -100000 << endl;
        } else {
            cout << 3 << endl;
            cout << -100000 << ' ' << ys << endl;
            cout << -100000 << ' ' << 100000 << endl;
            cout << xt << ' ' << 100000 << endl;
        }
    } else if (pts[2][2] == 1) {
        if (yp > yt) {
            cout << 3 << endl;
            cout << 100000 << ' ' << ys << endl;
            cout << 100000 << ' ' << -100000 << endl;
            cout << xt << ' ' << -100000 << endl;
        } else {
            cout << 3 << endl;
            cout << 100000 << ' ' << ys << endl;
            cout << 100000 << ' ' << 100000 << endl;
            cout << xt << ' ' << 100000 << endl;
        }
    } else if (pts[0][2] == 3) {
        if (ys == yt) {
                cout << 0 << endl;
                return;
        }
        cout << 2 << endl;
        cout << 100000 << ' ' << ys << endl;
        cout << 100000 << ' ' << yt << endl;
    } else {
        if (ys == yt) {
                cout << 0 << endl;
                return;
        }
        cout << 2 << endl;
        cout << -100000 << ' ' << ys << endl;
        cout << -100000 << ' ' << yt << endl;
    }

    // int xxt = xt - xs;
    // int yyt = yt - ys;
    // int xxp = xp - xs;
    // int yyp = yp - ys;

    // if (xxt > 0 && yyt > 0 && xxp > 0 && yyp > 0) {
    //     if (xxt > xxp && yyt > yyp) {

    //     }
    //     else {
    //         cout << 0 << endl;
    //     }
    // } else if (xxt < 0 && yyt < 0 && xxp < 0 && yyp < 0) {
    //     if ()
    //     else {
    //         cout << 0 << endl;
    //     }

    // } else if (xxt > 0 && yyt < 0 && xxp > 0 && yyp < 0) {
    //     if ()
    //     else {
    //         cout << 0 << endl;
    //     }

    // } else if (xxt < 0 && yyt > 0 && xxp < 0 && yyp > 0) {
    //     if ()
    //     else {
    //         cout << 0 << endl;
    //     }

    // } else {
    //     cout << 0 << endl;
    // }

    // if (yyt > 0) {
    //     cout << 4 << endl;
    //     cout << -100000 << ' ' << ys << endl;
    //     cout << -100000 << ' ' << 100000 << endl;
    //     cout << xt << ' ' << 100000 << endl;
    // } else {
    //     cout << 3 << endl;
    //     cout << -100000 << ' ' << ys << endl;
    //     cout << -100000 << ' ' << -100000 << endl;
    //     cout << xt << ' ' << -100000 << endl;
    // }



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