#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
        int i = n + 1;
 
        set<int> nee;
 
        while (n != 0) {
            n = n & i;
            nee.insert(n);
            i++;
        }
 
        cout << nee.size() << endl;
        for (auto it = nee.begin(); it != nee.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
 
    return 0;
}