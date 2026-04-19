#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<vector<char>> arr(n+1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    int res = 0;
    vector<pair<PII, PII>> k = {{{1, 0}, {0, 1}}, {{1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, {{-1, 0}, {0, -1}}};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (auto e : k) {
                int ax = i + e.first.first;
                int ay = j + e.first.second;
                int bx = i + e.second.first;
                int by = j + e.second.second;
                if (ax >= 1 && ax <= n && ay >= 1 && ay <= m && bx >= 1 && bx <= n && by >= 1 && by <= m) {
                    set<char> st;
                    st.insert(arr[ax][ay]);
                    st.insert(arr[bx][by]);
                    st.insert(arr[i][j]);
                    if (st.size() == 3) res++;
                }
            }
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
