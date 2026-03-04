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

const int N = 1001;
// const int N = 10;
int n,m,k;
int sx,sy;
int grid[N][N];
int dist[N][N];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
char dr[4] = {'D','L','R','U'};

bool found = false;
string ans = "";
string path = "";

void bfs() {
    queue<pii> q;

    q.push({sx,sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        pii p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();

        for (int i=0; i<4; i++) {
            int nx = x+dx[i];
            int ny = y+dy[i];

            if ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= m)) continue;
            if (!grid[nx][ny]) continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y]+1;
            q.push({nx,ny});
        }
    }
}

void dfs(int x,int y,int step) {
    if (step == 0) {
        if (x == sx and y == sy) {
            ans = path;
        }
        return;
    }

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if ((nx < 0) || (ny < 0) || (nx >= n) || (ny >= m)) continue;
        if (!grid[nx][ny]) continue;
        if (dist[nx][ny] <= step-1) {
            path.push_back(dr[i]);          
            dfs(nx,ny,step-1);
            return;
        }
    }
}

void solve() {
    memset(dist, -1, sizeof(dist));
    cin>>n>>m>>k;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin>>c;
            if (c == 'X') {
                sx = i;
                sy = j;
            }
            if (c == '*') continue;
            grid[i][j] = 1;
        }
    }

    
    bfs();
    dfs(sx,sy,k);

    // print2(dist);

    if (ans == "") {
        print("IMPOSSIBLE");
        return;
    }

    print(ans);
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