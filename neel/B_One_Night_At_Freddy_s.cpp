#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    long long l;
    cin >> n >> m >> l;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> S(m + 1, 0);
    vector<long long> B(m + 1, 0);
    vector<long long> pB(m + 1, 0);

    long long lt = 0;
    for (int i = 0; i <= n; ++i) {
        long long ct = (i < n) ? a[i] : l;
        long long E = ct - lt;
        lt = ct;

        for (int k = 1; k <= m; ++k) {
            B[k] += E;
            S[k] += E;
        }

        pB[0] = 0;
        for (int k = 1; k <= m; ++k) {
            pB[k] = pB[k - 1] + B[k];
            S[k] = min(S[k], pB[k]);
        }

        if (i < n) {
            vector<long long> nS(m + 1, 0);
            for (int k = 1; k < m; ++k) {
                long long tgt = S[k + 1];
                long long low = 0, high = B[1];
                long long ansX = tgt;

                while (low <= high) {
                    long long mid = low + (high - low) / 2;
                    int pL = 1, pH = k + 1;
                    int p = 0;
                    
                    while (pL <= pH) {
                        int pM = pL + (pH - pL) / 2;
                        if (B[pM] >= mid) {
                            p = pM;
                            pL = pM + 1;
                        } else {
                            pH = pM - 1;
                        }
                    }

                    long long cSum = 1LL * p * mid + (pB[k + 1] - pB[p]);
                    if (cSum >= tgt) {
                        ansX = mid;
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                nS[k] = tgt - ansX;
            }
            
            if (m > 1) {
                nS[m] = nS[m - 1];
            } else {
                nS[1] = 0;
            }

            for (int k = 1; k < m; ++k) {
                B[k] = B[k + 1];
            }
            B[m] = 0;

            pB[0] = 0;
            for (int k = 1; k <= m; ++k) {
                pB[k] = pB[k - 1] + B[k];
            }

            for (int k = 1; k <= m; ++k) {
                S[k] = nS[k];
                S[k] = min(S[k], pB[k]);
            }
        }
    }

    cout << S[1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}