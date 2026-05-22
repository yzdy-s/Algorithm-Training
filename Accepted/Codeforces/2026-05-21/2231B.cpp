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
    vector<int> k(n + 1, 0);
    int mx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            k[i] = 1;
            mx = max(mx, arr[i] - arr[i + 1]);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (k[i] == 0 && arr[i] < arr[i - 1]) {
            arr[i] += mx;
        }
    }
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
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
