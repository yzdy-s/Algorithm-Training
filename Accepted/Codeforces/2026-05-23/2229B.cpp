#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    
    int sum = 0; // b 数组之和
    int mmx = -LNF, ccx = -LNF;
    for (int i = 1; i <= n; i++) {
        int mx = max(a[i], b[i]);
        int mn = min(a[i], b[i]);
        b[i] = mx;
        a[i] = mn;
        sum += b[i];
        if (a[i] >= mmx) {
            ccx = mmx;
            mmx = a[i];
        } else if (a[i] > ccx) {
            ccx = a[i];
        }
    }
    
    int res = sum + mmx;
    for (int i = 1; i <= n; i++) {
        int A = a[i];
        int B = b[i];
        sum -= B;
        sum += A;
        int c = B;
        if (mmx == A) {
            c = max(c, ccx);
        } else {
            c = max(c, mmx);
        }
        res = max(res, sum + c);
        sum -= A;
        sum += B;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
