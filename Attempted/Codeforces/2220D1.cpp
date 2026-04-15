#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
vector<vector<int>> ans(5000, vector<int>(5000));
int query(int l, int r) {
    if (ans[l][r] != -1) return ans[l][r];
    cout << "? ";
    cout << r - l + 1 << ' ';
    for (int i = l; i <= r; i++) cout << i << ' ';
    cout << endl;
    cout.flush();
    int x;cin >> x;
    ans[l][r] = x;
    return x;
}

void solve(){
    int n;cin >> n;
    int L, R, mid;
    int l = 1, r = 2*n+1;
    for (int i = 1; i <= 2*n+1; i++) {
        for (int j = 1; j <= 2*n+1; j++) {
            if (i == j) ans[i][j] = 1;
            else ans[i][j] = -1;
        }
    }
    // 右端点
    while (l < r) {
        int mid = l + r + 1 >> 1;
        int x1 = query(l, mid-1);
        int x2 = query(mid, r);
        if (x1 == x2) {
            if (((mid - l) & 1) == (x1 & 1)) r = mid - 1;
            else l = mid;
        } else l = mid;
    }
    R = l;
    

    l = 1, r = 2*n - 1;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        int x1 = query(l, mid-1);
        int x2 = query(mid, r);
        if (x1 == x2) {
            if (((mid - l) & 1) == (x1 & 1)) r = mid - 1;
            else l = mid;
        } else r = mid - 1;
    }
    L = l;

    l = L, r = R;
    while (l < r) {
        int mid = l + r +1 >> 1;
        int x1 = query(L, mid-1);
        int x2 = query(mid, R);
        if (x1 > x2) l = mid;
        else r = mid - 1;
    }
    mid = l;

    cout << "! " << L << ' ' << mid << ' ' << R << endl;
    cout.flush();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}