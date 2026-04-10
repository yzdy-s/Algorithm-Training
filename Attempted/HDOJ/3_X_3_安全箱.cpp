#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct P {
    int val[4][4] = {0};
};
vector<P> pre(30);

void init() {
    pre[1].val[3][3] = 1;

    pre[2].val[2][3] = 1;
    pre[2].val[1][3] = 1;

    pre[3].val[2][3] = 1;
    pre[3].val[1][2] = 1;
    pre[3].val[1][1] = 1;

    pre[4].val[2][3] = 1;
    pre[4].val[1][1] = 3;

    pre[5].val[2][2] = 1;
    pre[5].val[1][3] = 1;
    pre[5].val[1][2] = 1;

    pre[6].val[2][2] = 1;
    pre[6].val[1][2] = 2;
    pre[6].val[1][1] = 1;

    pre[7].val[2][2] = 1;
    pre[7].val[1][2] = 1;
    pre[7].val[1][1] = 3;

    pre[8].val[1][3] = 3;

    pre[9].val[1][3] = 2;
    pre[9].val[1][2] = 1;
    pre[9].val[1][1] = 1;

    pre[10].val[1][3] = 2;
    pre[10].val[1][1] = 3;

    pre[11].val[1][3] = 1;
    pre[11].val[1][2] = 3;

    pre[12].val[1][3] = 1;
    pre[12].val[1][2] = 2;
    pre[12].val[1][1] = 2;

    pre[13].val[1][3] = 1;
    pre[13].val[1][2] = 1;
    pre[13].val[1][1] = 4;

    pre[14].val[1][3] = 1;
    pre[14].val[1][1] = 6;

    pre[15].val[1][2] = 4;
    pre[15].val[1][1] = 1;

    pre[16].val[1][2] = 3;
    pre[16].val[1][1] = 3;

    pre[17].val[1][2] = 2;
    pre[17].val[1][1] = 5;

    pre[18].val[1][2] = 1;
    pre[18].val[1][1] = 7;

    pre[19].val[1][1] = 9;

    pre[20].val[2][2] = 1;
    pre[20].val[1][3] = 1;
    pre[20].val[1][1] = 2;

    pre[21].val[2][2] = 1;
    pre[21].val[1][1] = 5;
}

void solve(){
    int n;cin >> n;
    map<PII, vector<int>> mp; // ab - {val}

    for (int i = 1; i <= n; i++) {
        int a, b;cin >> a >> b;
        int val;cin >> val;
        mp[{min(a, b), max(a, b)}].push_back(val);
    }

    for (auto &[_, vec] : mp) {
        sort(vec.begin(), vec.end(), greater<int>());
    }

    int res = 0;
    for (int i = 1; i <= 21; i++) {
        int t = 0;
        for (int a = 1; a <= 3; a++) {
            for (int b = a; b <= 3; b++) {
                int cnt = min((int)mp[{a, b}].size(), pre[i].val[a][b]);
                for (int j = 0; j < cnt; j++) {
                    t += mp[{a, b}][j];
                }
            }
        }
        res = max(res, t);
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}