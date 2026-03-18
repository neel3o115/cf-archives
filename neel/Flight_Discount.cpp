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

const int N = 100005;
int n, m;
vvi adj(N);
map<pii, int> w;

void solve() {
    cin>>n>>m;  
    vi dis0(n+1, INF);
    vi dis1(n+1, INF);

    for (int i=0; i<m; i++) {
        int a,b,c; cin>>a>>b>>c;
        adj[a].pb(b);

        if (w.count({a,b})) {
            w[{a,b}] = min(w[{a,b}], c);
        } else {
            w[{a,b}] = c;
        } 
    }

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    dis0[1] = 0;
    dis1[1] = 0;

    for (int i: adj[1]) {
        dis0[i] = w[{1,i}];
        dis1[i] = w[{1,i}]/2;
        pq.push({dis0[i], i});
    }
    
    while (len(pq)) {
        vi node = pq.top();
        pq.pop();

        int x = node[1];
        int y = node[0];

        if (y != dis0[x]) continue;

        for (int i: adj[x]) {
            int dis = w[{x,i}];
            if (y+dis < dis0[i]) {
                dis0[i] = y+dis;
                pq.push({dis0[i],i});
            }
        }
    }

    for (int i: adj[1]) {
        dis1[i] = w[{1,i}]/2;
        pq.push({dis1[i], i});
    }

    while (len(pq)) {
        vi node = pq.top();
        pq.pop();

        int x = node[1];
        int y = node[0];

        if (y != dis1[x]) continue;

        for (int i: adj[x]) {
            int dis = w[{x,i}];
            if (min(dis1[x]+dis, dis0[x]+dis/2) < dis1[i]) {
                dis1[i] = min(dis1[x]+dis, dis0[x]+dis/2);
                pq.push({dis1[i],i});
            }
        }
    }

    print(dis1[n]); 
    // print1(dis0);
    // print1(dis1);
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