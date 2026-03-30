#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b, c;
        cin >> a >> b >> c;

        string aa = bitset<64>(a).to_string();
        string bb = bitset<64>(b).to_string();
        string cc = bitset<64>(c).to_string();

        while (aa.size() && aa[0] == '0') aa.erase(aa.begin());
        while (bb.size() && bb[0] == '0') bb.erase(bb.begin());
        while (cc.size() && cc[0] == '0') cc.erase(cc.begin());

        reverse(aa.begin(), aa.end());
        reverse(bb.begin(), bb.end());
        reverse(cc.begin(), cc.end());

        bool pos = true;
        int n = min({(int)aa.size(), (int)bb.size(), (int)cc.size()});
        for (int i = 0; i < n; i++) {
            vector<char> nee = {aa[i], bb[i], cc[i]};
            int cnt = 0;
            for (char x : nee) if (x == '1') cnt++;
            if (cnt == 2) {
                cout << "NO\n";
                pos = false;
                break;
            }
        }
        if (pos) cout << "YES\n";
    }
}
