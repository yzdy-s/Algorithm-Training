#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    priority_queue<int> red, blue;
    for (int i = 1; i <= n; i++) {
        int num;cin >> num;
        if (num & 1) red.push(num);
        else blue.push(num);
    }
    int a  = 0, b = 0;
    if (red.size()) a = red.top();
    if (blue.size()) b = blue.top();
    cout << max(a, b) << ' ';
    int x = n - 1;
    while (x--) {
        if (blue.size()) {
            a += blue.top();
            blue.pop();
        } else a = 0;
        if (red.size()) {
            b += red.top();
            red.pop();
        } else b = 0;
        cout << max(a, b) << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}