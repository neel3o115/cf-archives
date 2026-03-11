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

int n;

void solve() {
    cin>>n;
    vi a(n);
    vi vis(n);

    for (int i=0; i<n; i++) cin>>a[i];

    priority_queue<vector<int>, vector<vector<int>>>pq;
    priority_queue<vector<int>, vector<vector<int>>>extra;

    for (int i=0; i<n; i++) pq.push({a[i],i});

    int ans = 0;
    while (len(pq)) {
        vi node = pq.top();
        pq.pop();

        int val = node[0];
        int idx = node[1];
        
        int nn1 = idx+1;
        int nn2 = idx-1;



        while(len(extra) and extra.top()[0] == val){
            vi rrr = extra.top();
            extra.pop();

            int idff = rrr[1];
            vis[idff] = 1;

            if (idff-1 >= 0 and !vis[idff-1]){
                extra.push({a[idff-1],idff-1});
            }
            if (idff+1 < n and !vis[idff+1]){
                extra.push({a[idff+1],idff+1});
            }
        }

        if (vis[idx]){
            continue;
        }





        if (nn1>=0 and nn1<n and vis[nn1]) {
            vis[idx] = 1;
            if (nn2 >= 0 and !vis[nn2]){
                extra.push({a[nn2],nn2});
            }
            continue;
        }

        if (nn2>=0 and nn2<n and vis[nn2]) {
            vis[idx] = 1;
            if (nn1 < n and !vis[nn1]){
                extra.push({a[nn1],nn1});
            }
            continue;
        }

        // print(val);
        vis[idx] = 1;
        if (nn2 >= 0 and !vis[nn2]){
            extra.push({a[nn2],nn2});
        }
        if (nn1 < n and !vis[nn1]){
            extra.push({a[nn1],nn1});
        }
        ans++;
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
    cin >> t;   
    while (t--) {
        solve();
    }
    
    #ifdef Local
        // chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        // cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}