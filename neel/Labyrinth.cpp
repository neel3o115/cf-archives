#include <bits/stdc++.h>
using namespace std;

// ---------- debug utilities ----------
#ifndef ONLINE_JUDGE
    #include <debug.cpp>
    auto start = chrono::high_resolution_clock::now();
#else 
    #define debug(...)
    #define debugArr(...)
#endif


// ---------- shortcut macros ----------
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(x) (int)(x).size()
#define pb push_back
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

int n, m;
vvc grid;
vvi vis(1000, vi(1000, 0));
vi dx = {0,0,1,-1};
vi dy = {1,-1,0,0};
vc dr = {'R','L','D','U'};

void solve() {
    cin>>n>>m;
    vi st = {-1,-1,-1};
    vi nd = {-1,-1,-1};
    for (int i=0; i<n; i++) { 
        vc row(m);
        for (int j=0; j<m; j++) {
            cin>>row[j];
            if (row[j] == 'A') st = {i, j}; 
            if (row[j] == 'B') nd = {i, j};
        }
        grid.pb(row);
    }

    queue<vi> qu;
    qu.push({st[0],st[1],0});
    vis[st[0]][st[1]] = 5;

    while (!qu.empty()) {
        vi cor = qu.front();
        qu.pop();

        for (int i=0; i<4; i++) {
            int nx = cor[0]+dx[i];
            int ny = cor[1]+dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (vis[nx][ny] != 0) continue;
            
            qu.push({nx, ny, cor[2]});
            vis[nx][ny] = i+1;
        }
    }

    if (vis[nd[0]][nd[1]] == 0) {
        cout << "NO";
        return;
    }

    string path;
    int i = nd[0];
    int j = nd[1];

    while (vis[i][j] != 5) {
        if (vis[i][j] == 1) {   
            path += 'R';
            j -= 1;
        } else if (vis[i][j] == 2) {
            path += 'L';
            j += 1;
        } else if (vis[i][j] == 3) {
            path += 'D';
            i -= 1;
        } else if (vis[i][j] == 4) {
            path += 'U';
            i += 1;
        }
    }

    reverse(all(path));

    if (len(path) > 0) {
        cout << "YES" << endl;
        cout << len(path) << endl;
        cout << path;
    } else {
        cout << "NO" << endl;
    }
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifndef ONLINE_JUDGE
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    #ifndef ONLINE_JUDGE
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}