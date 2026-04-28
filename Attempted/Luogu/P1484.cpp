#include <iostream>
#include <vector>

using namespace std;
#define int long long
const int N = 500005;
long long a[N];
long long dp[N][2];
int cnt[N][2];
int n, k;

// 跑一遍带税收 mid 的 1D DP
// 返回在最高收益下，选了多少棵树
int check(long long mid, long long &max_val) {
    dp[1][0] = 0;           cnt[1][0] = 0;
    dp[1][1] = a[1] - mid;  cnt[1][1] = 1;

    for (int i = 2; i <= n; i++) {
        // 1. 第 i 棵不种
        // 取收益大的；如果收益相同，优先选种树数量多的（避免三点共线丢失切点）
        if (dp[i-1][0] > dp[i-1][1] || (dp[i-1][0] == dp[i-1][1] && cnt[i-1][0] > cnt[i-1][1])) {
            dp[i][0] = dp[i-1][0];
            cnt[i][0] = cnt[i-1][0];
        } else {
            dp[i][0] = dp[i-1][1];
            cnt[i][0] = cnt[i-1][1];
        }

        // 2. 第 i 棵必须种
        // 只能从上一次不种转移过来，并且扣除税收 mid
        dp[i][1] = dp[i-1][0] + a[i] - mid;
        cnt[i][1] = cnt[i-1][0] + 1;
    }

    // 确定全局最优解
    int final_cnt;
    if (dp[n][0] > dp[n][1] || (dp[n][0] == dp[n][1] && cnt[n][0] > cnt[n][1])) {
        max_val = dp[n][0];
        final_cnt = cnt[n][0];
    } else {
        max_val = dp[n][1];
        final_cnt = cnt[n][1];
    }
    
    return final_cnt;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    if (!(cin >> n >> k)) return 0;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 特判：如果不加任何税收，无限制选出的优质树数量本来就 <= k
    // 那原题"最多可以种 k 棵树"的最优解已经得到了，直接输出即可


    // 开始 WQS 二分找税收
    long long l = 0, r = 1e12; 
    long long ans = 0;

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long max_val = 0;
        int c = check(mid, max_val);
        
        if (c > k) {
            l = mid + 1;
            ans = max_val + k * mid;
        } else if (c == k) {
            l = mid + 1;
            ans = max_val + k * mid;
            cout << c << ' ' << mid << ' ' << ans << endl;
        } else {
            ans = max(ans, max_val + c * mid);
            cout << c << ' ' << mid << ' ' << ans << endl;
            r = mid - 1;
        }

        // if (c >= k) {
        //     // 种的树多了（或刚好等于 k），说明税收偏低，尝试提高税收 l = mid + 1
        //     // 并且因为此时是一个合法的右边界，记录答案并退税：真实价值 = DP价值 + 棵树 * 税收
        //     ans = max_val + k * mid; 
        //     l = mid + 1;
        //     cout << c << ' ' << mid << ' ' << ans << endl;
        // } else {
        //     ans = max(ans, max_val + c * mid);
        //     // 种的树少了（低于 k），说明税太重了，连肥肉都不愿吃，降低税收
        //     r = mid - 1;
        // }
    }

    cout << ans << "\n";
    return 0;
}