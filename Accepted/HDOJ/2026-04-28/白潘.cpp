#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<map<int, int>> mp(k + 1);
    mp[0][0] = 1;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = k - 1; j >= 0; j--) {
            for (auto &[num, cnt] : mp[j]) {
                int nw = num ^ arr[i];
                mp[j + 1][nw] += cnt;
            }
        }
    }

    cout << mp[k][0] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
