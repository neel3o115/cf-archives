#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    unordered_set<long long> kuku;
    const long long LIMIT = 1000000000000000000LL;

    for (long long i = 2; i <= 1000005; ++i) {
        long long k = 4;
        __int128 val = 0; // prevent overflow during power computation

        while (true) {
            // (i^k - 1) / (i - 1)
            __int128 num = 1;
            for (int p = 0; p < k; ++p) num *= i;
            num -= 1;
            num /= (i - 1);

            if (num > LIMIT) break;

            kuku.insert((long long)num);
            ++k;
        }
    }

    while (t--) {
        long long n;
        cin >> n;

        if (kuku.count(n)) {
            cout << "YES\n";
        } else {
            string ans = "NO";

            __int128 D = 4 * (__int128)n - 3;
            if (D >= 0) {
                long long root = sqrt((long double)D);
                if ((root + 1) * (root + 1) == D) {
                    // check if (D - 1) % 2 == 0 and (D - 1) > 0 and != 2
                    long long diff = root - 1;
                    if (diff > 0 && diff != 2 && diff % 2 == 0) {
                        ans = "YES";
                    }
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}
