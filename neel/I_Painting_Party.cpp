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

const int N = 100005;
int srr[N];                 // original arr
int seg[4*N];               // segment tree array (needs up to ~4*N space)
const int NEUTRAL = 0;      

int combine(int a, int b) {
    return a+b;             
}

// node -> current position in segment tree
// st, nd -> start and end indices of the current segment
void build(int node, int st, int nd) {
    // base case: leaf node (only one element)
    if (st == nd) {
        seg[node] = srr[st];
        return;
    }

    // recursive case: split range into two halves
    int mid = (st+nd)/2;
    build(2*node, st, mid);         // build left child
    build(2*node+1, mid+1, nd);     // build right child

    // combine results from left and right children
    seg[node] = combine(seg[2*node], seg[2*node+1]);
}

int update(int node, int st, int nd, int idx) {
    // debug(st,nd,idx);
    if (nd - st == 0) {
        return seg[node];
    }

    if (st <= idx && idx <= nd) {
        if (seg[node] != 0) {
            return seg[node];
        }
    }

    int mid = (st+nd)/2;

    // recurse to the side where the index 'idx' lies
    if (idx <= mid) 
        return update(2*node, st, mid, idx);          // update in left half
    else 
        return update(2*node+1, mid+1, nd, idx);      // update in right half
}   

void query(int node, int st, int nd, int L, int R, int val, int antival) {
    // case 1: complete overlap (current segment is fully inside [L, R])
    if (L <= st and nd <= R) {
        seg[node] = val;
        return;
    }

    // case 2: no overlap (current segment is completely outside [L, R])
    if (R < st or L > nd) {
        if (antival != 0) seg[node] = antival;
        return;
    }

    // case 3: partial overlap → query both halves
    int pre;
    if (antival == 0) {
        pre = seg[node];
    } else {
        pre = antival;
    }

    seg[node] = 0;
    int mid = (st+nd)/2;
    query(2*node, st, mid, L, R, val, pre);          // query left half
    query(2*node+1, mid+1, nd, L, R, val, pre);      // query right half
}

void solve() {
    int n,q; cin>>n>>q;

    for(int i = 1;i <= n;i++){
        srr[i] = 0;
    }

    build(1, 1, n);
    bool flip = false;

    for (int i=0; i<q; i++) {
        int o; cin >> o;
        if (o == 1) {
            int l,r,c; cin >> l >> r >> c;
            if (flip) {
                int temp = l;
                l = n - r + 1;
                r = n - temp + 1;
            }

            query(1,1,n,l,r,c,seg[1]);
        } else {
            flip = !flip;
        }
    }

    vi res(n);
    for (int i=0; i<n; i++) res[i] = update(1,1,n,i+1);

    if (!flip) {
        print1(res);
    } else {
        reverse(all(res));
        print1(res);
    }
}   

int32_t main(){
    // cout << fixed << setprecision(10);
    execute
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

