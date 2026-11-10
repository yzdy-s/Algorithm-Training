#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int l = 0, r = n + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        cout << "? " << mid << endl;cout.flush();
        char res;cin >> res;
        if (res == '=') {
            cout << "! " << mid << endl;
            return;
        } else if (res == '>') l = mid;
        else r = mid;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
