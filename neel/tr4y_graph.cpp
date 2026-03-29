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

void solve() {
    int n;cin >> n;


    vector<array<int,3>> dabba_1;
    vector<array<int,3>> dabba_2;
    int a,b,p;

    for(int i = 0;i < n;i++){
        cin >> a >> b >> p;
        dabba_1.pb({a,b,p});
        dabba_2.pb({b,a,p});
    }

    sort(all(dabba_1));
    sort(all(dabba_2));


    debug(dabba_1);

    set<array<int,2>> dp_1;
    set<array<int,2>> ends_1;
    ends_1.insert({0,0});

    for(int i = 0;i < n;i++){
        
        a = dabba_1[i][0];b = dabba_1[i][1];p = dabba_1[i][2];
        auto it1 = ends_1.lower_bound({a,0});
        --it1;
        int prev_cost = (*it1)[1];
        ends_1.insert({b,p+prev_cost});

        for(auto it = dp_1.lower_bound({-(p + prev_cost),b});it != dp_1.end();){
            if ((*it)[1] >= b){
                ends_1.erase(ends_1.lower_bound({(*it)[1],-(*it)[0]}));
                it = dp_1.erase(it);
            }else{
                break;
            }
        }

        dp_1.insert({-(p + prev_cost),b});
    }


    // set<array<int,2>> dp_2;
    // set<array<int,2>> ends_2;
    // ends_2.insert({0,0});

    // for(int i = 0;i < n;i++){   
    //     b = dabba_2[i][0];a = dabba_2[i][1];p = dabba_2[i][2];
    //     auto it2 = ends_2.lower_bound({a,0});
    //     --it2;
    //     int prev_cost = (*it2)[1];
    //     ends_2.insert({b,p+prev_cost});

    //     for(auto it = dp_2.lower_bound({-(p + prev_cost),b});it != dp_2.end();){
    //         if ((*it)[1] >= b){
    //             ends_2.erase(ends_2.lower_bound({(*it)[1],-(*it)[0]}));
    //             it = dp_2.erase(it);
    //         }else{
    //             break;
    //         }
    //     }

    //     dp_2.insert({-(p + prev_cost),b});
    // }
    cout << -(*dp_1.begin())[0] << endl;
    // cout << -(*dp_2.begin())[0] << endl;
}

int32_t main(){
    // cout << fixed << setprecision(10);
    #ifdef Local
        // freopen("input.txt", "r+", stdin);
        // freopen("output.txt", "w+", stdout);
    #endif

    execute
    int t = 1;
    // cin >> t;B
    while (t--) {
        solve();
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}