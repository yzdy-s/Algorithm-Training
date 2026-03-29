#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    for (int i = 1; i <= n - k; i++) {
        if (b[i] == -1) {
            b[i] = a[i];
            continue;
        }

        if (b[i] != a[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = n; i > k; i--) {
        if (b[i] == -1) {
            b[i] = a[i];
            continue;
        }

        if (b[i] != a[i]) {
            cout << "NO" << endl;
            return;
        }
    }
    map<int, int> A, B;
    for (int i = n-k+1; i <= n; i++) {
        if (b[i] != -1) B[b[i]]++;
        A[a[i]]++;
    }
    for (auto &[num, cnt] : B) {
        if (cnt > A[num]) {
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
