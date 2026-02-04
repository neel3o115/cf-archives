// #include <bits/stdc++.h>
// using namespace std;

// // ---------- debug utilities ----------
// #ifndef Local
//     #define debug(...)
//     #define debugArr(...)
// #else
//     #include <debug.cpp>
//     auto start = chrono::high_resolution_clock::now();
// #endif


// // ---------- shortcut macros ----------
// #define all(a) (a).begin(), (a).end()
// #define rall(a) (a).rbegin(), (a).rend()
// #define len(x) (int)(x).size()
// #define pb push_back
// #define print(zzz) cout << zzz << ' '<<endl;
// #define print1(zzz) for(auto zzzz: zzz) cout << zzzz << ' ';cout<<endl;
// #define print2(zzz) for (auto &zzzzz : zzz) {print1(zzzzz)}
// #define space cout << endl;
// #define sum(v) (accumulate((v).begin(), (v).end(), 0LL))
// #define lb(v, x) (lower_bound((v).begin(), (v).end(), (x)) - (v).begin())  
// #define ub(v, x) (upper_bound((v).begin(), (v).end(), (x)) - (v).begin())  
// #define execute ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// // ----------- constants -----------
// #define PI 3.14159265358979323846
// #define INF 1e18
// #define MOD 1000000007
// #define MOD2 998244353

// // ---------- type aliases ----------
// #define ll long long
// #define int long long
// #define vi vector<int> 
// #define vc vector<char> 
// #define vs vector<string> 
// #define vvc vector<vector<char>> 
// #define vvi vector<vector<int>> 
// #define pii pair<int, int> 

// // ---------- input macros ----------
// #define msb(x) (x == 0 ? -1 : 1ll<<(63 - __builtin_clzll(x)))      
// #define lsb(x) (x == 0 ? -1 : 1ll<<(__builtin_ctzll(x)))   
// #define pc(x) (__builtin_popcountll(x))
// ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
// ll lcm(ll a, ll b) {return a * b / gcd(a, b);}



// void solve() {
//     string s; cin >> s;
//     vector<int> vpr;

//     for (int i = 0; i < s.size() - 1;) {
//         int j = i;
//         int cnt = 1;
//         while (j < s.size() && s[j] == s[j+1]) {
//             j++;
//         }
//         vpr.push_back(s[i] - '0');
//         i = j + 1;
//     }

//     if (s.size() > 1 && s[s.size() - 2] != s[s.size() - 1]) {
//         vpr.push_back(s[(s.size() - 1)] - '0');
//     } else if (s.size() == 1) {
//         vpr.push_back(s[s.size() - 1] - '0');
//     }

//     // debug(vpr);
//     int cnt1 = 0;
//     for (int i = 0; i < vpr.size(); ++i) {
//         if (vpr[i] == 1) {cnt1++;}
//     }


//     if (vpr[vpr.size() - 1] == 1) {
//         cout << cnt1 - 1 << endl;
//     } else {
//         cout << cnt1 << endl;
//     }
    
// }

// int32_t main(){
//     // cout << fixed << setprecision(10);
//     #ifdef Local
//         // freopen("input.txt", "r+", stdin);
//         // freopen("output.txt", "w+", stdout);
//     #endif

//     execute
//     int t = 1;
//     // cin >> t;
//     while (t--) {
//         solve();
//     }
    
//     #ifdef Local
//         chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
//         cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
//     #endif
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// ---------- debug utilities ----------
template<typename... Args>

// ---------- shortcut macros ----------
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(x) (int)(x).size()
#define pb push_back
#define print1(zzz) for(auto zzzz: zzz) cout << zzzz << ' ';cout<<endl;
#define print2(zzz) for (auto &zzzzz : zzz) {print1(zzzzz)}
#define space cout << endl;
#define sum(v) (accumulate((v).begin(), (v).end(), 0LL))
#define execute ios_base::sync_with_stdio(false);cin.tie(NULL);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, n) for (int i = (n) - 1; i >= 0; --i)
#define per1(i, a, b) for (int i = (b); i >= (a); --i)
void print(Args&&... args) {((cout << args << " "), ...);cout << '\n';}

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
#define invi(v, n) vi v(n); rep(i, n) cin >> v[i]
#define invs(v, n) vs> v(n); rep(i, n) cin >> v[i]
#define rdvi(v) for (auto &x : v) cin >> x
#define rdvs(v) for (auto &s : v) cin >> s
#define msb(x) (x == 0 ? -1 : 1<<(63 - __builtin_clzll(x)))      
#define lsb(x) (x == 0 ? -1 : 1<<(__builtin_ctzll(x)))   
#define pc(x) (__builtin_popcountll(x))
string d2b(long long num, ll pad = 0) { if (num == 0) return string(max(1LL, pad), '0');string res;while (num) {res += '0' + (num & 1);num >>= 1;}reverse(res.begin(), res.end());if (len(res) < pad) res = string(pad - res.size(), '0') + res;return res;}

void solve() {
    
}

int32_t main(){
    // cout << fixed << setprecision(10);
    execute
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}