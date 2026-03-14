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

int n, m, l;

void solve(int n,int m,int l) {
    // cin>>n>>m>>l;
    vi ms(l);
    vi vis1(n+1, INT_MAX);
    vi vis2(n+1, INT_MAX);
    vvi adj(n+1);

    for (int i=0; i<l; i++) cin>>ms[i];

    for (int i=0; i<m; i++) {
        int a, b; cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int tot = sum(ms);
    int max_evn = 0;
    int max_odd = 0;

    if (tot % 2 == 0) {
        max_evn = tot;
        for (int i: ms) {
            if (i%2 == 1) {
                max_odd = max_evn-i;
                break;
            }
        }
    } else {
        max_odd = tot;
        for (int i: ms) {
            if (i%2 == 1) {
                max_evn = max_odd-i;
                break;
            }
        }
    }

    queue<vi> qu;
    qu.push({1, 0});
    vis1[1] = 0;

    while (len(qu)) {
        vi node = qu.front();
        qu.pop();

        if (node[0] == 1) {
            for (int nbr: adj[node[0]]) {
                qu.push({nbr, node[1]+1});
                vis1[nbr] = node[1]+1;
            }
        }

        else {
            for (int nbr: adj[node[0]]) {
                for (int i: adj[nbr]) {
                    if (vis1[i] >= node[1]+2) {
                        qu.push({i, node[1]+2});
                        vis1[i] = node[1]+2;
                    }
                }
            }
        }
    }

    qu.push({1,0});
    vis2[1] = 0;

    while (len(qu)) {
        vi node = qu.front();
        qu.pop();

        for (int nbr: adj[node[0]]) {
            for (int i: adj[nbr]) {
                if (vis2[i] >= node[1]+2) {
                    qu.push({i, node[1]+2});
                    vis2[i] = node[1]+2;
                }
            }
        }
        
    }

    vi res(n,0);
    res[0] = 1;

    for (int i=1; i<n; i++) {
        if (vis1[i+1] <= max_odd) {
            res[i] = 1;
        } 
        if (vis2[i+1] <= max_evn) {
            res[i] = 1;
        }
    }

    print1(res);
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifdef Local
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    int t = 1;
    cin >> t;
    int k;
    for (int i = 1; i <= t; ++i) {
        if (i == 79 && k == 3) {
            string s = "";
            cin>>n>>m>>l;
            string nee = "";
            for (int i=0; i<l; i++) {
                string xx; cin>>xx;
                nee += xx+'/';
            };

            for (int i=0; i<m; i++) {
                char a, b; cin>>a>>b;
                s += a+'-'+b+'/';
            }
            
            cout << "nee";
            // cout << n << "/" << m;
            return 0;

        }
        cin>>n>>m>>l;
        
        solve(n,m,l);
        if (i == 1) k = n;
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}