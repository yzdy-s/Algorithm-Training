#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, x1, y1, x2, y2;cin >> n >> x1 >> y1 >> x2 >> y2;
    string s;cin >> s;
    vector<char> res;
    for (auto &c : s) {
        if (c == 'U') {
            if (y1 >= y2) {
                res.push_back('A');
                y1++;
            } else {
                res.push_back('B');
                y2++;
            }
        } else if (c == 'D') {
            if (y1 <= y2) {
                res.push_back('A');
                y1--;
            } else {
                res.push_back('B');
                y2--;
            }
        } else if (c == 'L') {
            if (x1 <= x2) {
                res.push_back('A');
                x1--;
            } else {
                res.push_back('B');
                x2--;
            }
        } else {
            if (x1 >= x2) {
                res.push_back('A');
                x1++;
            } else {
                res.push_back('B');
                x2++;
            }
        }
    }

    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
    for (auto &c : res) cout << c;
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
