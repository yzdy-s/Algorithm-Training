#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    string s;cin >> s;
    
    s = "#" + s;
    s = s + s[1];
    int a = 0;
    int cnt = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        if (s[i] == '1' && s[i + 1] == '0') a++;
        if (s[i] == '1') cnt++;
    }
    // cout << a << endl;
    for (int i = 2; i <= 2 * n; i += 2) {
        if (s[i] == '1' && s[i + 1] == '1') a++;
        if (s[i] == '1') cnt++;
    }

    cout << a << ' ' <<  cnt - a << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
