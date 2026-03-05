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
    int n;
    cin >> n;
    vvi adj(n);
    vi dis(n);
    vi vis(n);
    queue<vi> q;
    q.push({0,0});
    dis[0] = 0;
    vis[0] = 1;
 
    rep (i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
 
    while (!q.empty()) {
        vi nxt = q.front();
        dis[nxt[0]] = nxt[1];
        q.pop();
        for (auto nbr : adj[nxt[0]]) {
            if (!vis[nbr]) {
                q.push({nbr, nxt[1]+1});
                vis[nbr] = 1;
            }
        }
    }
 
    int idx = 0;
    int mxx = 0;
 
    rep (i, n) {
        if (dis[i] >= mxx) {
            idx = i;
            mxx = dis[i];
        }
    }
 
    vis.assign(n, 0);
    q.push({idx, 0});
    dis[idx] = 0;
    vis[idx] = 1;
    
    while (!q.empty()) {
        vi nxt = q.front();
        dis[nxt[0]] = nxt[1];
        q.pop();
        for (auto nbr : adj[nxt[0]]) {
            if (!vis[nbr]) {
                q.push({nbr, nxt[1]+1});
                vis[nbr] = 1;
            }
        }
    }

    vi ee(n,0);
    
    int nee = *max_element(all(dis));

    for (int i=0; i<n; i++) {
        if ((dis[i] == 0) or (dis[i] == nee)) {
            ee[i] = 1;
        } 
    }

    idx = 0;
    mxx = 0;
 
    rep (i, n) {
        if (dis[i] >= mxx) {
            idx = i;
            mxx = dis[i];
        }
    }
 
    vis.assign(n, 0);
    q.push({idx, 0});
    dis[idx] = 0;
    vis[idx] = 1;
    
    while (!q.empty()) {
        vi nxt = q.front();
        dis[nxt[0]] = nxt[1];
        q.pop();
        for (auto nbr : adj[nxt[0]]) {
            if (!vis[nbr]) {
                q.push({nbr, nxt[1]+1});
                vis[nbr] = 1;
            }
        }
    }

    for (int i=0; i<n; i++) {
        if ((dis[i] == 0) or (dis[i] == nee)) {
            ee[i] = 1;
        } 
    }

    for (int i=0; i<n; i++) {
        if (ee[i] == 1) {
            print(nee+1);
        } else {
            print(nee);
        }
    }

    // print1(ee);
}
 
int32_t main(){
    // cout << fixed << setprecision(10);
    execute
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}