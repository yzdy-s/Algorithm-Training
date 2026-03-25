#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 1e9 + 7;

void solve(){
    int n, m;cin >> n >> m;
    vector<vector<char>> arr(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}