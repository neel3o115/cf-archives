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

const int N = 1003;
int n,m,k;
int grid[N][N];
int vis[N][N];
int ans[N][N];
vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0};

int dfs(int x, int y) {
    if (grid[x][y]) {
        ans[x][y] = 0;
        return ans[x][y];
    }

    vis[x][y] = 1;

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if ((nx<0) or (ny<0) or (nx>=n) or (ny>=m)) continue;
        if (grid[nx][ny]) ans[x][y] += 1;
        else if (vis[nx][ny] == -1) ans[x][y] += dfs(nx, ny);
    }


    return ans[x][y];
}


void dfs2(int x, int y, int z) {
    ans[x][y] = z;
    vis[x][y] = 2;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if ((nx<0) or (ny<0) or (nx>=n) or (ny>=m) or grid[nx][ny]) continue;
        else if (vis[nx][ny] == 1) dfs2(nx, ny, z);
    }
}

void solve() {
    cin>>n>>m>>k;
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin>>c;
            if (c == '*') grid[i][j] = 1;
            vis[i][j] = -1;
        }
    }

    for (int i=0; i<k; i++) {
        int a,b; cin>>a>>b;
        a--,b--;
        if (vis[a][b] == -1) {
            dfs(a,b);
            dfs2(a,b,ans[a][b]);
        }
        print(ans[a][b]);
    }

    // print2(grid);
    // space 
    // print2(vis);
    // space
    // print2(ans);
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