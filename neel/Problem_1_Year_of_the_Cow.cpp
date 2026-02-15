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
    int n; cin>>n;

    vector<string> nee = {"neel","Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

    map<string, int> year;
    map<string, int> born;
    map<string, string> zod;
    map<string, int> prv;
    map<string, int> nxt;

    year["Ox"] = 1;
    year["Tiger"] = 2;
    year["Rabbit"] = 3;
    year["Dragon"] = 4;
    year["Snake"] = 5;
    year["Horse"] = 6;
    year["Goat"] = 7;
    year["Monkey"] = 8;
    year["Rooster"] = 9;
    year["Dog"] = 10;
    year["Pig"] = 11;
    year["Rat"] = 12;

    born["Bessie"] = 0;

    zod["Bessie"] = "Ox";

    for (int i=1; i<13; i++) 
    for (int j=1; j<13; j++) {
        string s = nee[i]+nee[j];
        int x = 12;

        if (i<j) x = j-i;
        if (i>j) x = 12-(i-j);

        nxt[s] = x;
    }

    for (int i=1; i<13; i++) 
    for (int j=1; j<13; j++) {
        string s = nee[i]+nee[j];
        int x = 12;

        if (i<j) x = 12-(j-i);
        if (i>j) x = i-j;

        prv[s] = x;
    }

    for (int i=0; i<n; i++) {
        vector<string> sen(8);
        for (int j=0; j<8; j++) cin>>sen[j];

        string known = sen[7];
        string unknown = sen[0];
        string op = sen[3];
        string zod_unknown = sen[4];

        zod[unknown] = zod_unknown;

        if (op == "next") {
            born[unknown] = born[known] + nxt[zod[known]+zod[unknown]];
        } else {
            born[unknown] = born[known] - prv[zod[known]+zod[unknown]];
        }
    }  

    cout << abs(born["Elsie"]);
}

int32_t main(){
    // cout << fixed << setprecision(10);

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