#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<string> s(3);
    cin >> s[1]; s[1] = "#" + s[1];
    cin >> s[2]; s[2] = "#" + s[2];
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (s[1][i] == 'f') a++;
    }
    for (int i = 1; i <= n; i++) {
        if (s[2][i] == 'f') b++;
    }
    if (a == b) cout << 0 << endl;
    else if (a > b) {
        for (int i = 1; i < n; i++) {
            if (s[1][i] == 'f' && s[1][i + 1] == 'f') {
                a -= 2;
                if (a <= b) break;
            }
        }
        cout << abs(a - b) << endl;
    } else {
        for (int i = 1; i < n; i++) {
            if (s[2][i] == 'f' && s[2][i + 1] == 'f') {
                b -= 2;
                if (b <= a) break;
            }
        }
        cout << abs(a - b) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}
