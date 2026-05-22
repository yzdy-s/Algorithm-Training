#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<int> arr(maxN);
int n, k;
int lca(int a, int b) {
    if (a & 1) a++;
    if (b & 1) b++;

    while (a != b) {
        if (a > b) {
            a /= 2;
            if (a & 1) a++;
        } else {
            b /= 2;
            if (b & 1) b++;
        }
    }
    return a;
}

int cnt(int aid) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int x = arr[i];
        int c = 0;
        while (x != aid) {
            if (c == 100) return LNF;
            if (x & 1) x++;
            else x /= 2;
            res++;
            c++;
        }
    }
    return res;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    int k = lca(arr[1], arr[2]);

    for (int i = 3; i <= n; i++) {
        k = lca(k, arr[i]);
    }

    int k1 = k;
    int k2, k3;
    if (k & 1) k2 = k + 1;
    else k2 = k / 2;
    if (k & 1) k3 = k * 2;
    else k3 = k - 1;
    int ans = min({cnt(k1), cnt(k2), cnt(k3)});
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
