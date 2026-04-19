#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;cin >> n;
    map<int, vector<int>> mp;
    vector<int> arr(n);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mp[arr[i]].push_back(i + 1);
        mx = max(mx, arr[i]);
    }
    sort(arr.begin(), arr.end());
    int m;cin >> m;
    for (int i = 0; i < mp[mx].size(); i++) {
        cout << mp[mx][i] << " \n"[i == mp[mx].size() - 1];
    }
    while (m--) {
        int x;cin >> x;
        auto it = upper_bound(arr.begin(), arr.end(), x);
        if (it == arr.end()) cout << 0 << endl;
        else {
            cout << mp[*it][0] << endl;
        }
    }
}