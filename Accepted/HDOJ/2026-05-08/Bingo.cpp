#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    vector<vector<int>> a(n * n + 1, vector<int>(n + 1));
    vector<vector<int>> b(n * n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[arr[i][j]][j] = 1;
        }
    }
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            b[arr[i][j]][i] = 1;
        }
    }

    vector<int> ans;
    for (int num = 1; num <= n * n; num++) {
        int f = 1;
        for (int i = 1; i <= n; i++) {
            if (a[num][i] == 0 || b[num][i] == 0) {
                f = 0;
                break;
            }
        }
        if (f) ans.push_back(num);
    }

    cout << ans.size() << endl;
    for (auto &i : ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
