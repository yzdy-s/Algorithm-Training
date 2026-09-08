#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;
void solve(){
    int n, x;cin >> n >> x;
    __int128 sum = 0;
    vector<__int128> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int _;cin >> _;
        arr[i] = _;
        sum = (sum + arr[i]) % MOD;
    }
    if (x == 1) {
        cout << (int)(sum % MOD) << endl;
        return;
    }

    __int128 ans = 0;
    __int128 cnt = 0;
    priority_queue<__int128> pq;
    for (int i = 1; i <= n; i++) {
        pq.push(arr[i] % x);
        cnt += arr[i] / x;
    }
    // cout << ans << endl;

    while (pq.size()) {
        __int128 num = pq.top(); pq.pop();
        __int128 need = x - 1 - num;
        if (need <= cnt) {
            cnt -= need;
        } else {
            ans = (ans + num) % MOD;
        }
    }
    ans += cnt % (x - 1);

    cout << (int)(ans % MOD) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
