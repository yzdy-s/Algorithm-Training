#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
vector<int> cnt(70);

void calc(int x, int k) {
    if (k == 1) {
        cout << 1 << ' ';
        calc(x - 1, k);
    }
}


void solve(){
    int x, k;cin >> x >> k;
    int cnt = 4;
    while (x) {
        if (k == 1) {
            cout << 1 << ' ';
            x--;
        }
        if (x > 62) {
            cout << 1 << ' ';
            x--;
            continue;
        }
        int cur = 0;
        int c = 0;
        for (int bit = x-1; bit >= 0; bit--) {
            cur += (1LL << (bit - 1));
            if (cur < k) {
                c += (1LL << (bit - 1));
                continue;
            }
            cout << (x - bit) << ' ';
            x = bit;
            k -= c;
            // cout << x << ' ' << k << ' ' << c << endl;
            // return;
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}