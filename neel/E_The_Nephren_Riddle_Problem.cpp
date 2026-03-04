#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

long long lnn(long long n) {
    const long long LIM = (long long)1e18;
    if (n >= 60) return LIM;
    return 143LL * (1LL << n) - 68;
}

string foo = "What are you doing at the end of the world? Are you busy? Will you save us?";
string one = "What are you doing while sending \"";
string two = "\"? Are you busy? Will you send \"";
string tre = "\"?";

char rec(int64 n, int64 k){
    if(n == 0){
        if(k > 75) return '.';
        return foo[k-1];
    }

    int64 lo = lnn(n-1);

    if(k > 34 + lo + 32 + lo + 2) return '.';
    if(k > 34 + lo + 32 + lo) return tre[k - (34 + lo + 32 + lo) - 1];
    if(k > 34 + lo + 32) return rec(n-1, k - (34 + lo + 32));
    if(k > 34 + lo) return two[k - (34 + lo) - 1];
    if(k > 34) return rec(n-1, k - 34);
    return one[k-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--){
        int64 n, k;
        cin >> n >> k;
        cout << rec(n, k);
    }
    return 0;
}
