#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;cin >> n;
    map<int, set<int>> mp;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        int a, b;cin >> a >> b;
        mp[a].insert(b);
    }

    for (auto &[x, st] : mp) {
        if (st.size() == 1 && *st.begin() == 0) res.push_back(x);
    }
    if (res.size() == 0) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " \n"[i == res.size() - 1];
        }
    }
}