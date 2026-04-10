#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += arr[i];
    int K = k * n;
    if ((K & 1) == 0) {
        cout << "YES" << endl;
        return;
    }
    if (sum & 1) {
        cout << "YES" << endl;
    } else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
