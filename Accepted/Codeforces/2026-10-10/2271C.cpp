#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    
    if (n == 1) {
        cout << 3 << endl;
        cout << "1 1 1" << endl;
        return;
    }
    
    int t = 1;
    while (t * 2 <= n) {
        t *= 2;
    }
    
    vector<int> ans;
    ans.push_back(0);
    ans.push_back(t);
    ans.push_back(0);
    for (int i = 1; i < t; i++) {
        if (i & 1) {
            ans.push_back(i);
            ans.push_back(i);
            ans.push_back(i + t);
            ans.push_back(i + t);
        } else {
            ans.push_back(i + t);
            ans.push_back(i + t);
            ans.push_back(i);
            ans.push_back(i);
        }
    }
    ans.push_back(t);
    
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++) {
        cout << (ans[i] ^ ans[i - 1]) << ' ';
    }
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
