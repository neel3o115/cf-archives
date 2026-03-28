#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 200000);
    int q = rnd.next(1, 200000);

    cout << n << " " << q << "\n";

    for(int i = 1; i <= n; i++){
        cout << rnd.next(0, 1000000000);
        if(i < n) cout << " ";
    }
    cout << "\n";

    for(int i = 1; i <= q; i++){
        int t = rnd.next(0,2);

        int l = rnd.next(1,n);
        int r = rnd.next(l,n);

        cout << t << " " << l << " " << r << "\n";
    }
}