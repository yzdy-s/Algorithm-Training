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
    vector<int> sum(n + 1);
    int mn = LNF;
    int res = 1;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + arr[i];
        if (sum[i] + arr[i]  * (n - i) < mn) {
            res = i;
            mn = sum[i] + arr[i]  * (n - i);
        }
    }
    
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
