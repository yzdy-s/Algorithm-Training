#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> cnt1(n+1), cnt2(n+1);

    const int MAXV = 1e5 + 5;
    vector<int> tr(MAXV, 0);

    // 统计左边有多少比a[j]小的数
    auto add = [&](int x) {
        while(x < MAXV) {
            tr[x] += 1;
            x += x & -x;
        }
    };
    auto sum = [&](int x) {
        int res = 0;
        while(x > 0) {
            res += tr[x];
            x -= x & -x;
        }
        return res;
    };

    for(int i = 1; i <= n; ++i) {
        cnt1[i] = sum(a[i]-1);
        add(a[i]);
    }

    fill(tr.begin(), tr.end(), 0);

    // 统计右边有多少比a[j]大的数
    for(int i = n; i >= 1; --i) {
        cnt2[i] = sum(MAXV-1) - sum(a[i]);
        add(a[i]);
    }

    long long ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += 1LL * cnt1[i] * cnt2[i];
    }
    cout << ans << endl;
    return 0;
}