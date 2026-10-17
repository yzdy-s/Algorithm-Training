#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    char c;cin >> c;
    string s;cin >> s;
    int i = 0, j = n - 1;
    int res = 0;
    while (i < j) {
        if (s[i] != s[j]) {
            if (s[i] == c || s[j] == c) res++;
            else res += 2;
        }
        i ++;
        j --;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
