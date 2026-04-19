#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

void solve() {
    int n;cin >> n;
    vector<PII> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i].second >> arr[i].first;
    int res = n * 2;
    int ans = 0;
    vector<int> t;
    sort(arr.begin() + 1, arr.end());
    // for (int i = 1; i <= n; i++) cout << arr[i].first << ' ';
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n && arr[j].first == arr[i].first) j++;
        ans += j - i - 1;
        // cout << j - i << ' ';
        if (j - i == 1) {
            t.push_back(arr[i].second);
        }
        i = j - 1;
    }
    // cout << endl;
    sort(t.begin(), t.end());

    for (int i = 0; i < t.size(); i++) {
        int j = i;
        while (j < t.size() && t[j] == t[i]) j++;
        ans += j - i - 1;
        i = j - 1;
    }

    cout << res - ans << endl;
}

signed main() {
    int T;cin >> T;
    while (T--) solve();
}