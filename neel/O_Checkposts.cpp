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

ll mod_mul(ll a,ll b) {return ((a % MOD) * (b % MOD)) % MOD;}
ll mod_add(ll a,ll b) {return ((a % MOD) + (b % MOD)) % MOD;}
ll mod_sub(ll a,ll b) {return ((a % MOD) - (b % MOD) + MOD) % MOD;}
ll mod_pow(ll a,ll b, ll m = MOD) {ll res = 1;a %= m;while (b) {if (b & 1ll) res = res * a % m;a = mod_mul(a, a);b >>= 1ll;}return res;}
ll mod_inv(ll a, ll m = MOD) {return mod_pow(a, m - 2, m);}  // fermat's little theorem
ll mod_div(ll a, ll b) {return mod_mul(a, mod_inv(b));}

 
const int N = 200005;
int n, m;
vvi adj(N);
vvi rdj(N);
int xit[N];
int vis[N];
int nee = 1;
int kin = 0;
 
void dfs(int node) {
    if (vis[node]) return;
    
    vis[node] = 1;
    nee++;
 
    for (int i: adj[node]) {
        dfs(i);
    }
 
    xit[node] = nee;
    nee++;
}
 
void dfs2(int node, int p) {
    if (vis[node] != 0) return;
    
    vis[node] = p;
    for (int i: rdj[node]) {
        dfs2(i, p);
    }
}
 
void solve() {
    cin>>n;
    vvi tim;
    
    vi cost(n+1);
    for (int i=1; i<=n; i++) cin>>cost[i];

    cin>>m;
    for (int i=0; i<m; i++) {
        int a,b; cin>>a>>b;
        adj[a].pb(b);
        rdj[b].pb(a);
    }
    
    for (int i=1; i<=n; i++) {
        dfs(i);
    }
 
    for (int i=1; i<=n; i++) {
        tim.pb({xit[i], i});
    }
 
    sort(all(tim));
    reverse(all(tim));
 
    for (int i=1; i<=n; i++) vis[i] = 0;
    
    for (int i=0; i<n; i++) {
        if (vis[tim[i][1]] == 0) {
            dfs2(tim[i][1], kin+1);
            kin++;
        }
    }
 
    map<int,array<int , 2>> mp;
    for(int i = 1;i < n+1;i++){
        if (mp.count({vis[i]})){
            if (mp[vis[i]][0] > cost[i]){
                mp[vis[i]] = {cost[i],1};
            }else if (mp[vis[i]][0] == cost[i]){
                mp[vis[i]][1] += 1;
            }
        }else{
            mp[vis[i]] = {cost[i],1};
        }
    }

    // map<int, int> mp;
    map<int, int> pm;

    // for (int i=1; i<=n; i++) {
    //     if (mp.count(vis[i])) mp[vis[i]] = min(cost[i],mp[vis[i]]);
    //     else mp[vis[i]] = cost[i];
    // }

    int ans = 0;
    int jee = 1;
    
    for (auto it: mp) {
        ans += it.second[0];
        jee = mod_mul(jee,it.second[1]);
    }

    cout << ans << " " << jee;
    // debug(mp);
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