#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    map<int, int, greater<int>> mp;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        mp[x]++;
    }
    vector<int> ans;

    while (ans.size() != n) {
        for(auto it = mp.begin(); it != mp.end(); ){
            ans.push_back(it->first);
            it->second--;
            if (it -> second == 0) it = mp.erase(it);
            else ++it;
        }
    }
    for (auto &i : ans) cout << i << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
