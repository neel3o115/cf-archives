#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll lcm_ll(ll a, ll b){
    return a / __gcd(a,b) * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        ll a,b,c,m;
        cin >> a >> b >> c >> m;

        ll ab = lcm_ll(a,b);
        ll ac = lcm_ll(a,c);
        ll bc = lcm_ll(b,c);
        ll abc = lcm_ll(ab,c);

        ll A = m/a;
        ll B = m/b;
        ll C = m/c;

        ll AB = m/ab;
        ll AC = m/ac;
        ll BC = m/bc;
        ll ABC = m/abc;

        ll a_only = A - AB - AC + ABC;
        ll b_only = B - AB - BC + ABC;
        ll c_only = C - AC - BC + ABC;

        ll ab_only = AB - ABC;
        ll ac_only = AC - ABC;
        ll bc_only = BC - ABC;

        ll alice = 6*a_only + 3*ab_only + 3*ac_only + 2*ABC;
        ll bob   = 6*b_only + 3*ab_only + 3*bc_only + 2*ABC;
        ll carol = 6*c_only + 3*ac_only + 3*bc_only + 2*ABC;

        cout << alice << " " << bob << " " << carol << "\n";
    }
}