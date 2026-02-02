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
#define INF 1000000000000000000
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

void solve() {
    int n; cin>>n;
    vc dir(n);
    vi x(n);
    vi y(n);
    vi res(n,INF);
    map<tuple<int,int>, int> reached;

    for (int i=0; i<n; i++) {
        cin>>dir[i]>>x[i]>>y[i];
    }

    vvi event;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if ((dir[i] == 'N') and (dir[j] == 'E')) {
                if ((x[j] > x[i]) or (y[i] > y[j])) continue;
                
                int tn = y[j]-y[i];
                int te = x[i]-x[j];

                if (tn == te) continue;
                
                event.pb({tn,x[i],y[i]+tn,i,j});
                event.pb({te,x[j]+te,y[j],j,i});
            } else if ((dir[i] == 'N') and (dir[j] == 'N') and (x[i] == x[j]) and (i != j)) {

                if (y[j] > y[i]) {
                    int tn = y[j]-y[i];
                    event.pb({0 ,x[j],   y[j],j,i});
                    event.pb({tn,x[i],y[i]+tn,i,j});
                }

            } else if ((dir[i] == 'E') and (dir[j] == 'E') and (y[i] == y[j]) and (i != j)) {

                if (x[j] > x[i]) {
                    int te = x[j]-x[i];
                    event.pb({0 ,x[j],   y[j],j,i});
                    event.pb({te,x[i]+te,y[j],i,j});
                } 
            }
        }
    }

    sort(all(event));

    for (int i=0; i<len(event); i++) {
        int t,xi,yi;

        t  = event[i][0];
        xi = event[i][1];
        yi = event[i][2];
        
        if (res[event[i][3]] != INF) {
            continue;
        }

        if (res[event[i][4]] != INF) {
            continue;
        }

        if (reached.count({xi,yi})) {
            if (reached[{xi,yi}] < t) res[event[i][3]] = t;
        } else {
            reached[{xi,yi}] = t;
        }
    }
    
    for (int i=0; i<n; i++) {
        if (res[i] == INF) cout << "Infinity" << endl;
        else cout << res[i] << endl;
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