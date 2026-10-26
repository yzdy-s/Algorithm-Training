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
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        odd += (arr[i] & 1);
    }

    if ((n == 3 && odd == 3) || (n == 2 && odd == 1)) cout << "Larpity" << endl;
    else cout << "Moggity" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
