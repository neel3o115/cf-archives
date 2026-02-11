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

bool fun(int a, int b) {
    if ((a == 0) and (b == 0)) return true;
    if (a == b) return false;
    return true;
}
 
int n, m;
vvi adj(1001);
int ch[1001][1001][26];
int arr[1001][1001];

void solve() {
    cin>>n>>m;
    vi vis1(n+1);
    vi vis2(n+1);
    vi dis1(n+1);
    vi dis2(n+1);
    
    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        char c; cin>>c;

        adj[a].pb(b);
        adj[b].pb(a);

        ch[a][b][c-'a'] = 1;
        ch[b][a][c-'a'] = 1;
    }
    if (n == 1) {
        if (m == 0) {
            print(0);
        } else {
            print(1);
        }
        return;
    }

    queue<pair <int,int>> s1;
    queue<pair <int,int>> s2;

    s1.push({1,0});
    s2.push({n,0});
    arr[0][n]=1;
    dis1[1] = 0;
    dis1[n] = 0;

    int ans = 1e9;
    int pos = false;

    while (len(s1) && len(s2)) {
    	pair <int,int> x=s1.front();
    	pair <int,int> y=s2.front();
        int node1 = x.first;
        int node2 = y.first;
        s1.pop();
        s2.pop();

        bool yes = false;
        if (node1 == node2) {
            pos = true;
            ans = min(2*x.second, ans);
        }

        for (int nbr: adj[node1]) {
            if (nbr == node2) {
                pos = true;
                ans = min(x.second+y.second+1, ans);
            }
        }
        
        
        for (int i: adj[node1]) {
            for (int j: adj[node2]) {
                for (int k=0; k<26; k++) {      
                    if (((ch[node1][i][k] == 1) and (ch[node2][j][k] == 1)) and (!(arr[i][j]))) {
                        arr[i][j]=1;
                        int fe1 = x.second+1;
                        int fe2 = y.second+1;
                        s1.push({i,fe1});
                        s2.push({j,fe2});
                        break;
                    }
                }
            }
        }
    }

    if (pos) {
        print(ans);
    } else {
        print(-1);
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