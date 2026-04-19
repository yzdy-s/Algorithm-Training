#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;cin >> n;
    vector<int> arr(n + 1);
    int mx = 0, mn = 1e9, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    int av = sum / n;
    cout << mx << ' ' << mn << ' ' << av << endl;
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= av * 2) res.push_back(i);
    }
    if (res.size() == 0) cout << "Normal";
    else {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " \n"[i == res.size() - 1];
        }
    }
}