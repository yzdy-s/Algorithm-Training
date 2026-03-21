#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, c, k;cin >> n >> c >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin()+1, arr.end());

    for (int i = 1; i <= n; i++) {
        if (c >= arr[i]) {
            int use = min(c - arr[i], k);
            k -= use;
            c += arr[i] + use;
        } else break;
    }

    cout << c << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
