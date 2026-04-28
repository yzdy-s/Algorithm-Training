#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 676767677;

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0;
    int cnt1 = 0;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 1) cnt1++;
        else {
            f = 1;
            res = (res + arr[i]) % MOD;
        }
    }

    if (cnt1 == n) res = 1;
    else if (arr[n] == 1) res = (res + 1) % MOD;

    cout << res % MOD << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
