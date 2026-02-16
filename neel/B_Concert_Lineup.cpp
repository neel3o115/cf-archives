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
    int n,q; cin >> n >> q;
    vector<int> v(n);
    set<int> st;

    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        st.insert(i);
    }

    while (q--) {
        int k; cin >> k;
        int ck = 0;
        auto it = begin(st);
        while (ck < k / 2 && next(it) != st.end() && next(next(it)) != st.end()) {
            auto it1 = next(next(it));
            st.erase(it);
            it = it1;
            ck++;
        }

        if (ck < k/2 && it != st.end()) {
            st.erase(it);
        }

        
        
        
        auto pt1 = st.begin(),pt2 = st.begin();
        ck = 1;
        while (ck < k / 2 && next(pt2) != st.end() ) {
            pt2 = next((pt2));
            ck++;
        }

        debug(*pt1,*pt2,st,k);
        
        int dist = k / 2;
        
        while (dist > 1) {
            dist -= 2;
            int idx1 = *pt1;
            int idx2 = *pt2;
            
            pt1 = next(pt1);
            pt2 = prev(pt2);
            
            swap(v[idx1],v[idx2]);
        }
        debug(st);
    }


    for (auto &e : st) {
        cout << v[e] << ' ';
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
    cin >> t;
    while (t--) {
        solve();
    }
    
    #ifdef Local
        chrono::duration<double> elapsed = chrono::high_resolution_clock::now() - start;
        cerr << fixed << setprecision(6) << "\nTime: " << elapsed.count() << "s\n"; 
    #endif
    return 0;
}