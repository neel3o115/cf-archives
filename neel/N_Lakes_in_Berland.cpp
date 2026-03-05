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
#define print1(zzz) for(auto zzzz: zzz) cout << zzzz;cout<<endl;
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

// const int N = 6;
const int N = 55;
int n,m,k;
int grid[N][N];
int vis[N][N];
vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0};
set<int> discard;
map<int, int> mp;
int cccc;

void dfs(int x, int y, int z) {
    if (vis[x][y] != 0) return;
    if (x==0 or y==0 or x==n-1 or y==m-1) discard.insert(z);

    vis[x][y] = z;
    cccc++;

    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];

        if (nx<0 or ny<0 or nx>=n or ny>=m) continue;
        if (grid[nx][ny]) continue;
        if (nx==0 or ny==0 or nx==n-1 or ny==m-1) discard.insert(z);
        dfs(nx,ny,z);
    }
}

void solve() {
    cin>>n>>m>>k;
    vvc ans(n, vc(m, '*'));

    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char c; cin>>c;
            if (c == '*') grid[i][j] = 1;
            ans[i][j] = c;
        }
    }
    
    set<vi> st;

    int nee = 1;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (grid[i][j] == 0 and vis[i][j] == 0) {
                cccc = 0;
                dfs(i,j,nee);
                mp[nee] = cccc;

                if (!discard.count(nee)) {
                    st.insert({cccc,nee});
                }
                nee++;
            }
        }
    }

    int lakes = len(st);
    set<int> remove;

    int cc = 0;

    auto it = st.begin();
    for(auto x : st){
        if (cc == lakes-k){
            break;
        }
        remove.insert(x[1]);
        cc++;
    }

    int jee = 0;
    for (int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if (remove.count(vis[i][j])) {
                jee++;
                ans[i][j] = '*';
            }
        }
    }

    cout << jee << '\n';
    for (auto &row : ans) {
        for (auto c : row) cout << c;
        cout << '\n';
    }

    // space
    // print2(vis);
    // print1(discard);
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
        // chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        // cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}