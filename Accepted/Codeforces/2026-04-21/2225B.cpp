#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = '#' + s;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'a') arr[i] = 1;
        else arr[i] = 0;
    }
    int fr = 0, ed = 0;
    for (int i = 2; i <= n; i++) {
        if (s[i] == s[i-1]) {
            if (fr == 0) {
                fr = i;
                ed = i;
            } else ed = i;
        }
    }
    ed--;
    // cout << fr << ' ' << ed << ' ';
    for (int i = fr; i < ed; i++) {
        if (s[i] == s[i+1]) {
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
