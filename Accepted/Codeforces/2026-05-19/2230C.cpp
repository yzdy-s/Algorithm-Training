#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    int two = 0;
    int one = 0;

    int res = 0;
    int block = 0;
    int C = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = arr[i];
        if (cnt == 1) {
            one++;
            continue;
        }
        C++;
        res += cnt;
        block += cnt / 2 - 1;
    }

    // cout << block << endl;
    //cout << k << endl;
    //cout << remain << endl;
    

    if (C == 1) {
        block++;
    }
    int add = min(block, one);
    res += add;
    if (res >= 3) cout << res << endl;
    else cout << 0 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
