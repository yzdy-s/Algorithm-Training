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
    int res = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (arr[1] != gcd(arr[1], arr[2])) res++;
    if (arr[n] != gcd(arr[n-1], arr[n])) res++;
    for (int i = 2; i < n; i++) {
        int g1 = gcd(arr[i-1], arr[i]);
        int g2 = gcd(arr[i], arr[i+1]);
        int aid = lcm(g1, g2);
        if (arr[i] > aid) res++;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
