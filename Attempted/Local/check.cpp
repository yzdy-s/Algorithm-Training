#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, q;cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    while (q--) {
        int op, l, r;cin >> op >> l >> r;
        if (op == 1) {
            int x;cin >> x;
            for (int i = l; i <= r; i++) arr[i] = x;
        } else if (op == 2) {
            for (int i = l; i <= r; i++) arr[i] ^= 1;
        } else {
            cout << "+" << endl;
        }
        for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}