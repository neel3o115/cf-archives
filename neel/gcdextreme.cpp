#include<bits/stdc++.h>
#define int         int64_t
#define pb          push_back
#define endl        '\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
using namespace std;
int phi[1000006], ans[1000006];
const int N = 1000000;

void process() {
    for(int i = 0 ; i <= N ; i++) {
        phi[i] = i;
    }
    for(int i = 2; i <= N ; i++) {
        if(phi[i] == i) {
                for(int j = i ; j <= N ; j+=i) {
                        phi[j] -= phi[j]/i;
                }
        }
    } 
    memset(ans, 0, sizeof ans);
    for(int i = 1; i <= N; i++) {
        for(int j = i + i; j <= N; j+=i) {
                ans[j] += i * phi[j/i] ;
        }
        ans[i] += ans[i-1];
    }
    
}
void solve(){
    process();
    while(true) {
        int n;
        cin >> n;
        if(!n) return;
        cout<<ans[n]<<endl;
    }
}

signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
        
    int test=1;
    //cin>>test;
    while(test--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";     
    return 0;
}