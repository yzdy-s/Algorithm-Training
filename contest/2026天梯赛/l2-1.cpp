#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, t;cin >> n >> t;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> res;
    int c = 1;
    int T = 2;
    while (1) {
        int f = 1;
        int sum = 0;
        int cnt = 0;
        if (c) {
            for (int i = 1; i <= n; i++) {
                if (arr[i] == -1) continue;
                if (arr[i] <= t) {
                    res.push_back(i);
                    arr[i] = -1;
                } else {
                    sum += arr[i];
                    f = 0;
                    cnt++;
                }
            }
        } else {
            for (int i = n; i >= 1; i--) {
                if (arr[i] == -1) continue;
                if (arr[i] <= t) {
                    res.push_back(i);
                    arr[i] = -1;
                } else {
                    sum += arr[i];
                    f = 0;
                    cnt++;
                }
            }
        }
        if (f == 1) break;
        c ^= 1;
        t = sum / cnt;
    }
    for (int i = 0; i < n; i++) cout << res[i] << " \n"[i == n - 1];
}