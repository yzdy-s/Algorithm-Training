#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int cnt(int n) {
    int res = 0;
    for (int bit = 0; bit <= 63; ++bit) {
        if (bit > 0 && (1LL << bit) > n) break; 
        int p = 1LL << (bit + 1);
        int h = 1LL << bit;
        res += (n / p) * h;
        int re = n % p;
        if (re > h) {
            res += re - h;
        }
    }
    return res;
}

void solve(){
    int n;cin >> n;
    cout << (1 + n) * n / 2 - cnt(n+1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    // for (int i = 1; i <= 10; i++) cout << cnt(i) << endl;
    while (T--) solve();
}
