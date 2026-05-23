#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int maxN = 1e5 + 7;
vector<int> a(maxN), b(maxN);

bool check(int x) {
    int fr = 0, ba = 0;
    vector<int> t;
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x && b[i] >= x) t.push_back(1);
        else if (a[i] < x && b[i] < x) t.push_back(0);
    }
    vector<int> res;
    int m = t.size();
    int A = 0, B = 0;
    for (int i = 0; i < m; i++) {
        if (t[i] == 1) {
            A++;
            continue;
        }
        int j = i;
        while (j < m && t[j] == 0) j++;
        B++;
        i = j - 1;
    }

    return A > B;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int l = -7, r = 2 * n + 7;
    int res = 0;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            l = mid;
            res = max(res, mid);
        } else {
            r = mid;
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
