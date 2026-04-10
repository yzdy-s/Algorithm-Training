#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int pos;cin >> pos;
    int ans = LNF;
    int a = 0, b = 0;
    int t = arr[pos];
    for (int i = 1; i <= pos; i++) {
        if (t == arr[i]) continue;
        else {
            t ^= 1;
            a++;
        }
    }
    t = arr[pos];
    for (int j = n; j >= pos; j--) {
        if (t == arr[j]) continue;
        else {
            t ^= 1;
            b++;
        }
    }

    ans = max(a, b);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
