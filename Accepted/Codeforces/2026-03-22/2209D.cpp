#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int TTT = 1;
void solve(){
    
    vector<int> cnt(3);
    cin >> cnt[0] >> cnt[1] >> cnt[2];
    // cout << cnt[0] << " " <<  cnt[1] << ' ' << cnt[2] << endl;
    string res;
    vector<char> k(3);
    k[0] = 'R';
    k[1] = 'G';
    k[2] = 'B';

    while (1) {
        int choose = -1;
        int n = res.size();
        int mx = -1;
        for (int i = 0; i < 3; i++) {
            if (!cnt[i]) continue;
            if (n >= 1 && res[n - 1] == k[i]) continue;
            if (n >= 3 && res[n - 3] == k[i]) continue;
            if (cnt[i] > mx) {
                mx = cnt[i];
                choose = i;
            } else if (cnt[i] == mx && (n >= 2 && res[n - 2] == k[i])) {
                mx = cnt[i];
                choose = i;
            }
        }


        if (choose == -1) break;
        res += k[choose];
        cnt[choose]--;
    }
    // cout << TTT++ << ' ';
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
