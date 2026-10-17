#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int calc(int x) {
    int res = 0;
    while (x) {
        res += (x % 10) * (x % 10);
        x /= 10;
    }

    return res;
}
void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int t = 10000; t >= 0; t--) {
            arr[i] = calc(arr[i]);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (arr[i] == arr[j]) res++;
        }
    }

    // for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
