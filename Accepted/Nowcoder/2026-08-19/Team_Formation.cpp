#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int popcnt(int x) {
    int res = 0;
    while (x) {
        res++;
        x >>= 1;
    }
    return res;
}
void solve(){
    int n;cin >> n;
    int m = 3 * n;
    vector<vector<int>> val(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j ++) {
            cin >> val[i][j];
        }
    }

    int tot = (1 << m) - 1;
    vector<int> dp(tot + 1, -LNF);
    dp[0] = 0;

    for (int st = 0; st <= tot; st++) {
        if (dp[st] == -LNF) continue;
        
        vector<int> re;
        for (int i = 0; i < m; i++) {
            if (!(st >> i & 1)) re.push_back(i);
        }

        if (re.size() == 0) continue;
        int x = re[0];

        for (int j = 1; j < re.size(); j++) {
            for (int k = j + 1; k < re.size(); k++) {
                int y = re[j];
                int z = re[k];
                dp[st | (1 << x) | (1 << y) | (1 << z)] = max(dp[st | (1 << x) | (1 << y) | (1 << z)], dp[st] + val[x][y] + val[x][z] + val[y][z]);
            }
        }
    }

    cout << dp[tot] << endl;

    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
