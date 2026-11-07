#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin() + 1, arr.end());
    int ans = LNF;
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = i; j <= n; j++) {
            if (arr[j] % arr[i] != 0) t++;
        }
        ans = min(ans, i - 1 + t);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
