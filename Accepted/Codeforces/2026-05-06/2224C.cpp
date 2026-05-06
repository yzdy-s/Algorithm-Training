#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string a, b;cin >> a >> b;
    a = '#' + a;
    b = '#' + b;
    vector<int> A(n + 1, 0), B(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int t1 = (a[i] == '(') ? 1 : -1;
        int t2 = (b[i] == '(') ? 1 : -1;
        int mx = max(t1, t2);
        int mn = min(t1, t2);
        if (A[i - 1] > B[i - 1]) {
            A[i] = A[i - 1] + mn;
            B[i] = B[i - 1] + mx;
        } else {
            A[i] = A[i - 1] + mx;
            B[i] = B[i - 1] + mn;
        }
        if (A[i] < 0 || B[i] < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    if (A[n] != 0 || B[n] != 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
