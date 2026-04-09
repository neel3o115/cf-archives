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

int x, y, k, m;
int vis[111][111];

void solve() {
    cin>>x>>y>>k>>m;

    queue<vi> qu;
    qu.push({0, 0, 1});

    int ans = m;

    while (len(qu)) {
        vi node = qu.front();
        int a = node[0];
        int b = node[1];
        int c = node[2];
        qu.pop();

        // cout << a << " " << b << " " << c << endl; 
        
        if (c > k+1) break;
        ans = min(ans, abs(m-(a+b)));
        
        int nx, ny;

        nx = x;
        ny = b;

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

        nx = a;
        ny = y;

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

        nx = a-min(a,y-b);
        ny = min(y,a+b);

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

        nx = min(x,a+b);
        ny = b-min(b,x-a);

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

        nx = 0;
        ny = b;

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

        nx = a;
        ny = 0;

        if (!vis[nx][ny]) {
            qu.push({nx, ny, c+1});
            vis[nx][ny] = 1;
        }

    }
    
    cout << ans;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("pails.in", "r+", stdin);
    freopen("pails.out", "w+", stdout);

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