#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

ll dp[102][100005];
int n;

int rec(vector<int>& arr, int idx, int left) {
    if (left<0) return 0;
    if (idx == n) {
        if (left==0) return 1;
        else return 0;
    }

    if (dp[idx][left] != -1) return dp[idx][left];
    
    int res = 0;
    if (rec(arr, idx+1, left-arr[idx])==1) res = 1;     // take
    if (rec(arr, idx+1, left)==1) res = 1;              // not take

    return dp[idx][left] = res;
}

vector<int> take;
void print(vector<int>& arr, int idx, int left) {
    if (left==0) return;

    if (rec(arr, idx+1, left-arr[idx])==1) {            // take
        take.push_back(idx);
        print(arr, idx+1, left-arr[idx]);
    } else if (rec(arr, idx+1, left)==1) {              // not take
        print(arr, idx+1, left);
    };
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    n = arr.size();
    int q = queries.size();
    memset(dp, -1, sizeof(dp));

    vector<vector<int>> ans;

    for (int i=0; i<q; i++) {
        if (rec(arr, 0, queries[i])) {
            take.clear();
            print(arr, 0, queries[i]);
            ans.push_back(take);
        } else {
            ans.push_back({-1});
        }
    }


    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
