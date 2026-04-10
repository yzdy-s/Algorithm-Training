#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> ans(n + 1);
    for (int num = 1; num <= n; num++) {
        for (int j = 2; j * num <= n; j++) {
            ans[num]++;
            ans[num * j]++;
        }
    }
    // for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
    sort(ans.begin()+1, ans.end(), greater<int>());
    cout << ans[k] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
