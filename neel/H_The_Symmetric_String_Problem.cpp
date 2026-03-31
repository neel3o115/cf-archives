#include <bits/stdc++.h>
using namespace std;

bool rec(const string &a,const string &b,int l1,int r1,int l2,int r2) {

    int n = r1-l1;

    bool pos = true;
    for (int i=0;i<n;i++) {
        if (a[l1+i] != b[l2+i]) {
            pos = false;
            break;
        }
    }

    if (pos) return true;

    if (n % 2 == 0) {
        int m1=l1+n/2;
        int m2=l2+n/2;

        if ((rec(a,b,l1,m1,l2,m2) &&
             rec(a,b,m1,r1,m2,r2)) ||
            (rec(a,b,l1,m1,m2,r2) &&
             rec(a,b,m1,r1,l2,m2))) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a,b; cin>>a>>b;

    if (rec(a,b,0,a.size(),0,b.size()))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
