#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    vector<int> arr(6);
    int sum = 0;
    for (int i = 1; i <= 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    priority_queue<int> pq;
    for (int i = 1; i <= 5; i++) pq.push(arr[i]);
    int cnt2 = 0;
    int z = 0;
    while (1) {
        z++;
        if (z >= 1000) {
            cout << -1 << endl;
            return;
        }
        int mx = pq.top(); pq.pop();
        int avg = (sum + 2) / 3;
        if (sum % 3 == 0 && mx <= avg) {
            cout << avg + cnt2 << endl;
            return;
        }

        if (mx <= avg) {
            mx -= 2;
            if (mx < 0) {
                cout << -1 << endl;
                return;
            }
            sum -= 2;
            cnt2 += 1;
            pq.push(mx);
        } else {
            int a = (3 * mx - sum + 3) / 4;
            cnt2 += a;
            mx -= 2 * a;
            if (mx < 0) {
                cout << -1 << endl;
                return;
            }
            sum -= 2 * a;
            pq.push(mx);
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
