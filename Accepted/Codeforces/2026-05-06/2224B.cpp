#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int ans = 0;
    ranges::sort(arr.begin() + 1, arr.end());
    int mx = arr[n];
    int mex = 0;
    arr[0] = arr[n];
    vector<int> vis(n + 7, 0);
    vector<int> aid;
    aid.push_back(arr[0]);
    set<int> st;
    for (int i = 1; i < n; i++) st.insert(arr[i]);
    for (auto &i : st) aid.push_back(i);
    for (int i = 0; i < n; i++) {
        if (i < aid.size()) {
            if (aid[i] <= n) vis[aid[i]] = 1;
            while (mex <= n && vis[mex]) mex++;
        }
        
        ans += mx + mex;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
