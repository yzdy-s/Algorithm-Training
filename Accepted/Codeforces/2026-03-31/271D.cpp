#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
typedef unsigned long long ull;
void solve(){
    string s;cin >> s;
    int n = s.size();
    s = '#' + s;
    set<string> st;
    vector<int> mp(26);
    string _;cin >> _;
    for (int i = 0; i < 26; i++) {
        mp[i] = 1 - (_[i] - '0');
    }
    vector<int> sum(n + 1);
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = mp[s[i] - 'a'];
    }
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
    int k;cin >> k;
    vector<ull> hash;
    ull p = 13331;
    for (int l = 1; l <= n; l++) {
        ull h = 0;
        for (int r = l; r <= n; r++) {
            if (sum[r] - sum[l - 1] <= k) {
                // cout << l << ' ' << r << ' ' << s.substr(l, r) << endl;
                // st.insert(s.substr(l, r - l + 1));
                h = h * p + (s[r] - 'a' + 1);
                hash.push_back(h);
            }
            else break;
        }
    }
    sort(hash.begin(), hash.end());
    hash.erase(unique(hash.begin(), hash.end()), hash.end());
    cout << hash.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
