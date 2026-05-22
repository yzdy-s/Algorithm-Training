#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    vector<int> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 2; i <= n; i++) {
        if (c[i] < c[i - 1]) {
            cout << "No" << endl;
            return;
        }
    }
    if (s[1] == '1' && a[1] != c[1]) {
        cout << "No" << endl;
        return;
    }
    vector<int> b(n + 1, -LNF);
    a[1] = b[1] = c[1];

    for (int i = 2; i <= n; i++) {
        if (c[i] > c[i - 1]) b[i] = c[i];
    }

    for (int i = n; i >= 1; i--) {
        if (b[i] != -LNF && b[i] > c[i]) {
            cout << "No" << endl;
            return;
        }
        if (b[i] != -LNF && s[i] == '1') {
            b[i - 1] = b[i] - a[i]; 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != -LNF && b[i] > c[i]) {
            cout << "No" << endl;
            return;
        }
        if (b[i - 1] != -LNF && s[i] == '1') {
            b[i] = b[i - 1] + a[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] > c[i]) {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != -LNF) continue;
        int fr = b[i - 1];
        int j = i;
        while (b[j] == -LNF) {
            b[j] = fr;
            j++;
        }
        i = j - 1;
    }
    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << b[i] << ' ';
        else cout << b[i] - b[i - 1] << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}