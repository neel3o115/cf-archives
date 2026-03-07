#include <bits/stdc++.h>
using namespace std;

// ---------- debug utilities ----------
template<typename... Args>

// ---------- shortcut macros ----------
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define len(x) (int)(x).size()
#define pb push_back
#define print1(zzz) for(auto zzzz: zzz) cout << zzzz << ' ';cout<<endl;
#define print2(zzz) for (auto &zzzzz : zzz) {print1(zzzzz)}
#define space cout << endl;
#define sum(v) (accumulate((v).begin(), (v).end(), 0LL))
#define JBR_CP_1000101 ios_base::sync_with_stdio(false);cin.tie(NULL);

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, n) for (int i = (n) - 1; i >= 0; --i)
#define per1(i, a, b) for (int i = (b); i >= (a); --i)
void print(Args&&... args) {((cout << args << " "), ...);cout << '\n';}

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
#define invi(v, n) vi v(n); rep(i, n) cin >> v[i]
#define invs(v, n) vs v(n); rep(i, n) cin >> v[i]
#define rdvi(v) for (auto &x : v) cin >> x
#define rdvs(v) for (auto &s : v) cin >> s
#define msb(x) (x == 0 ? -1 : 1ll<<(63 - __builtin_clzll(x)))      
#define lsb(x) (x == 0 ? -1 : 1ll<<(__builtin_ctzll(x)))   
#define pc(x) (__builtin_popcountll(x))
string d2b(long long num, ll pad = 0) { if (num == 0) return string(max(1LL, pad), '0');string res;while (num) {res += '0' + (num & 1);num >>= 1;}reverse(res.begin(), res.end());if (len(res) < pad) res = string(pad - res.size(), '0') + res;return res;}

int dp[1001][1001][2];
int vis[1001][1001];

int n,m;
vector<pii> Holstein;
vector<pii> Guernseys;


int calc(pii cow_1, pii cow_2) {
    auto [x1, y1] = cow_1;
    auto [x2, y2] = cow_2;

    int dx = x1 - x2;
    int dy = y1 - y2;

    return (dx * dx + dy * dy);
}


int recur(int h,int g,int w){

    if (!g && !w) return INF;
    if (h == 1 && w) return g ? INF : 0;


    if (dp[h][g][w] != -1) return dp[h][g][w];
    int opt_1,opt_2;
    if (w){
        opt_1 = recur(h-1,g,w) + calc(Holstein[h-1],Holstein[h]);
        opt_2 = recur(h-1,g,1-w) + calc(Guernseys[g],Holstein[h]);
    }else{
        opt_1 = recur(h,g-1,w) + calc(Guernseys[g-1],Guernseys[g]);
        opt_2 = recur(h,g-1,1-w) + calc(Holstein[h],Guernseys[g]);
    }

    return dp[h][g][w] = min(opt_1,opt_2);
}

void solve() {
    cin >> n >> m;

    Holstein.resize(n + 1);
    Guernseys.resize(m + 1);

    for(int i = 1;i < n+1; i++){
        int x,y;cin >> x >> y;
        Holstein[i] = {x,y};
    }
    for(int i = 1;i < m+1; i++){
        int x,y;cin >> x >> y;
        Guernseys[i] = {x,y};
    }

    // memset(dp,-1,sizeof dp);

    // cout << recur(n,m,1);

    for(int i = 1;i <= m;i++){
        dp[1][i][1] = INF;
        dp[0][i][1] = INF;
        dp[0][i][0] = INF;
    }
    dp[1][0][1] = 0;

    for(int j = 1;j <= n;j++){
        dp[j][0][0] = INF;
    }

    for(int h = 1;h <= n;h++){
        for (int g = 1;g <= m;g++){
            for(int w = 0;w < 2;w++){
                int opt_1,opt_2;
                if (w){
                    opt_1 = dp[h-1][g][w] + calc(Holstein[h-1],Holstein[h]);
                    opt_2 = dp[h-1][g][1-w] + calc(Guernseys[g],Holstein[h]);
                }else{
                    opt_1 = dp[h][g-1][w] + calc(Guernseys[g-1],Guernseys[g]);
                    opt_2 = dp[h][g-1][1-w] + calc(Holstein[h],Guernseys[g]);
                }
                dp[h][g][w] = min(opt_1,opt_2);
            }
        }
    }
    cout << dp[n][m][1];
    // cout << dp[0][2][0];

    // vis[0][1] = 1;
    // vis[1][0] = 0;


    // for(int i = 1;i <= n;i++){
    //     for (int j = 1;j <= m;j++){
            
    //         int uppar = dp[i-1][j] + calc(vis[i-1][j] ? Guernseys[j] : Holstein[i-1] , Holstein[i]);
    //         if (vis[i-1][j] == 2){
    //             uppar = min(uppar,dp[i-1][j] + calc(Holstein[i-1] , Holstein[i]));
    //         }

    //         int left  = dp[i][j-1] + calc(vis[i][j-1] ? Guernseys[j-1] : Holstein[i] , Guernseys[j]);
    //         if (vis[i][j-1] == 2){
    //             left = min(left,dp[i][j-1] + calc(Holstein[i] , Guernseys[j]));
    //         }

    //         vis[i][j] = (uppar == left) ? 2 : (uppar < left) ? 0 : 1;
    //         dp[i][j] = min(uppar,left);
    //     }
    // } 

    // cout << dp[n][m] << endl;

    // for(int i = 0;i <= n;i++){
    //     for(int j = 0;j <= m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

   



}

int32_t main(){
    // cout << fixed << setprecision(10);
    freopen("checklist.in", "r+", stdin);
    freopen("checklist.out", "w+", stdout);
    
    JBR_CP_1000101
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}