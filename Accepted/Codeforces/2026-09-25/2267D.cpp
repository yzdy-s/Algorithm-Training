#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<PII> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first;
        arr[i].second = (i & 1);
    }
    sort(arr.begin() + 1, arr.end(), greater<PII>());
    for (int i = 2; i <= n; i += 2) {
        if (arr[i].second == arr[i - 1].second) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
