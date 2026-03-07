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

int cal(vector<int>& v) {
    int n = v.size();
    int c = 0;
    map<int,int> mp;
    map<int,int> tmp;
    int j = 0;
    int en = n;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == 0) {
            // mp[0]++;
            if (en == n){
                mp[0]++;
            }
            if (en == n && mp[1] == 1 && mp[2] == 1){
                en = i;
            }
            // if (mp[1] == 1 && mp[2] == 1) {
            //     en = min(en,i);
            //     tmp[0]++;
            // }else{
            //     en = n;
                
            // }
        } else if (v[i] == 1) {
            if (mp[1] == 0) {
                mp[1]++;
                if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                    en = i;
                }
            } else {
                while (j < v.size() && v[j] != 1) {
                    if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                        c += i - en;
                    }else{
                        int r = en + 1;
                        while (r < i && mp[1] == 1 && mp[2] == 1 && mp[0] == 0){
                            mp[v[r]]++;
                            r++;
                        }

                        if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0){
                            en = r - 1;
                            c += i - en;
                        }else{
                            r = n;
                        }
                    }
                    mp[v[j]]--;
                    j++;
                }

                if (j != v.size()) {

                    if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                        // debug("fiijf");
                        c += i - en;
                        en = i;
                        mp[0] = 0;
                        mp[1] = 0;
                        mp[2] = 0;
                        for(int k = j;k <= en;k++){
                            mp[v[k]]++;
                        }
                        j++;
                    }else{
                        // debug(mp,j);
                        int r = en + 1;
                        while (r < i && mp[1] == 1 && mp[2] == 1 && mp[0] == 0){
                            mp[v[r]]++;
                            r++;
                        }

                        if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0){
                            en = r - 1;
                            
                            // while (en < r-1){
                            //     mp[v[en]]
                            // }
                            c += i - en;
                        }else{
                            r = n;
                        }
                        j++;
                    }
                    // debug("kkk",j,c,en,mp);
                }

            }

        } else {
            if (mp[2] == 0) {
                mp[2]++;
                if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                    en = i;
                }
            } else {
                while (j < v.size() && v[j] != 2) {
                    if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                        c += i - en;
                    }else{
                        int r = en + 1;
                        while (r < i && mp[1] == 1 && mp[2] == 1 && mp[0] == 0){
                            mp[v[r]]++;
                            r++;
                        }

                        if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0){
                            en = r - 1;
                            c += i - en;
                        }else{
                            r = n;
                        }
                    }
                    mp[v[j]]--;
                    // debug(j,c);
                    j++;

                }

                if (j != v.size()) {

                    if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
                        c += i - en;
                        en = i;
                        mp[0] = 0;
                        mp[1] = 0;
                        mp[2] = 0;
                        for(int k = j;k <= en;k++){
                            mp[v[k]]++;
                        }
                        j++;
                    }else{
                        int r = en + 1;
                        while (r < i && mp[1] == 1 && mp[2] == 1 && mp[0] == 0){
                            mp[v[r]]++;
                            r++;
                        }

                        if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0){
                            en = r - 1;
                            c += i - en;
                        }else{
                            r = n;
                        }
                        j++;
                    }
                }

            }
        }
        // debug(i,c);
    }


    while (j < v.size()){
        // c += en;
        // mp[v[j]]--;
        // debug(j,c);
        // j++;


        if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0) {
            c += n - en;
        }else{
            int r = en + 1;
            while (r < n && mp[1] == 1 && mp[2] == 1 && mp[0] == 0){
                mp[v[r]]++;
                r++;
            }

            if (mp[1] == 1 && mp[2] == 1 && mp[0] != 0){
                en = r - 1;
                c += n - en;
            }else{
                r = n;
            }
        }
        mp[v[j]]--;
        debug(j,c);

        j++;

    }
    return c;
}

void solve() {
    int n; cin >> n;
    set<int> st;
    vector<int> v(n); for (auto &e : v) {cin >> e;}
    vector<vector<int>> a;

    vector<int> cur;

    for (int i = 0; i < n; ++i) {
        if (v[i] < 3) {
            cur.push_back(v[i]);
        } else {
            if (cur.size() >= 3) {
                a.push_back(cur);
            }
            cur.clear();
        }
    }


    if (cur.size() >= 3) {
        a.push_back(cur);
    }



    int res = 0;

    for (auto &e : a) {
        // debug(e);

        res += cal(e);
    }

    cout << res << endl;
    
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