#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin()+1, arr.end());
    map<int, int> mp;
    for (int i = 1; i <= n; i++) mp[arr[i]]++;
    
    vector<int> ans(n + 1);
    ans[1] = arr[1];
    

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}