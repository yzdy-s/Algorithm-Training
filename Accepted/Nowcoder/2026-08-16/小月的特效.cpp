#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    map<int, int> fr, ba;
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int x = arr[i];
        if (fr.count(x)) continue;
        fr[x] = i;
    }
    for (int i = n; i >= 1; i--) {
        int x = arr[i];
        if (ba.count(x)) continue;
        ba[x] = i;
    }
    int res = 0;
    for (auto &[x, pos1] : fr) {
        if (!ba.count(x)) continue;
        int pos2 = ba[x];
        int d = pos2 - pos1;
        if (d != 0 && (d & 1) == 0) res++;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
