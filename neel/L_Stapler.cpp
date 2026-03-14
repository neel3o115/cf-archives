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

double x1,x2,y1,y2,xl,yl,xr,yr;


// bool ycheck(double num) {
//     if (num < y1 || num > y2) {
//         return false;
//     }

//     if (num < yl || num > yr) {
//         return false;
//     }

//     return true;
// }
// bool xcheck(double num) {
//     if (num < x1 || num > x2) {
//         return false;
//     }

//     if (num < xl || num > xr) {
//         return false;
//     }

//     return true;
// }

void solve() {
    cin>>xl>>yl>>xr>>yr;
    // cin>>x1>>y1>>x2>>y2;

    cout << xl << ' ' << xr << ' ' << yl << ' ' << yr << endl;

    // if (y1 > y2) {
    //     swap(y1,y2);
    // }
    // if (x1 > x2) {
    //     swap(x1,x2);
    // }

    // // eq => (y - y1)(x1 - x2) = (y1 - y2)(x - x1)
    // double slope = (y2 - y1) / (x2 - x1);

    // double yy1 = (xl - x1) * slope + y1;
    // double yy2 = (xr - x1) * slope + y1;
    // double xx1 = (yl - y1) / slope + x1;
    // double xx2 = (yr - y1) / slope + x1;

    // if (xcheck(xx1) || xcheck(xx2) || ycheck(yy1) || ycheck(yy2)) {
    //     cout << "STOP" << endl;
    // } else {
    //     cout << "OK" << endl;
    // }
    // return;





    // cout << xl << " " << yl << " "  << xr << " "  << yr << endl;
    // cout << x1 << " " << y1 << " "  << x2 << " "  << y2 << endl;
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