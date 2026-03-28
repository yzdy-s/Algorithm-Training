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
    vector<int> cnt(n + 1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        int c = mp[num];
        if (c & 1) cnt[i] -= 1;
        else cnt[i] += 1;
        mp[num]++;
    }
    
    for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
    vector<int> bac(n + 2); // 后缀偶数项
    for (int i = n; i >= 1; i++) {
        bac[i] = bac[i + 1];
        if ((cnt[i] & 1) == 0) bac[i]++;
    }
    cout << 0 << endl;
    return;
    int res = 0; // 后手胜利数量
    for (int i = 1; i <= n; i++) {
        if (arr[i] & 1) {
            res += bac[i];
        } else {
            res += (n - i) - bac[i];
        }
    }
    cout << n*n << ' ' << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}