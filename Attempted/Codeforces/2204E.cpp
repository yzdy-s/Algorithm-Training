#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

string ss;
vector<int> t;

bool dele(string sss) {
    for (auto &c : sss) {
        t[c - '0']--;
        if (t[c - '0'] < 0) return false;
    }
    return 1;
}

void calc(int x) {
    ss += to_string(x);
    int nx = 0;
    int t = x;
    while (x) {
        nx += x % 10;
        x /= 10;
    }
    if (t == nx) return;
    calc(nx);
}

void solve(){
    string s;cin >> s;
    vector<int> cnt(10, 0);
    for (auto &c : s) {
        cnt[c - '0']++;
    }
    for (int i = 1; i <= 1e6; i++) {
        ss.clear();
        t = cnt;
        calc(i);
        if (dele(ss)) {
            int sum = 0;
            for (int n = 0; n <= 9; n++) {
                sum += t[n] * n;
            }
            if (sum == i) {
                for (int n = 0; n <= 9; n++) {
                    for (int cnt = 0; cnt <= t[n]; cnt++) cout << n;
                }
            }
            cout << ss << endl;
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}