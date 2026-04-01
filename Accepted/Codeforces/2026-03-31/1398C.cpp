#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define all(x) x.begin(), x.end()

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> arr(n+1);
    for (int i = 0; i < n; i++) {
        arr[i+1] = arr[i] + s[i] - '0';
    }

    for (int i = 1; i <= n; i++) arr[i] -= i;

    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i <= n; i++) {
        res += mp[arr[i]]++;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
