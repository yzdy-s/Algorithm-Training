#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int calc(int mn, int mx) {
    for (int bit = 0; bit <= 32; bit++) {
        if ((mn | (1 << bit)) > mx) break;
        mn |= (1 << bit);
    }
    return (mn | mx);
}
void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans |= arr[i];
    }
    for (int i = 1; i < n; i++) {
        int a = arr[i], b = arr[i + 1];
        ans |= calc(min(a, b), max(a, b));
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
