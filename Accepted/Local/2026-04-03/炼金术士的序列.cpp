#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;cin >> n;
    vector<int> arr(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0;
    for (int i = 2; i <= n; i++) {
        int c = 0;
        if (arr[i] < arr[i - 1]) {
            int t = arr[i];
            while (t < arr[i - 1]) {
                t *= 2;
                c++;
            }
            dp[i] += dp[i - 1] + c;
        } else {
            int t = arr[i - 1];
            while (t <= arr[i]) {
                t *= 2;
                c++;
            }
            c--;
            dp[i] = max(0LL, dp[i-1] - c);
        }
        // cout << dp[i] << ' ' << c << endl;
        res += dp[i];
    }
    cout << res << endl;
}
