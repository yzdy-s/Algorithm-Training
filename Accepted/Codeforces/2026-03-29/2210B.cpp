#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define lowbit(x) (x & -x)

const int maxN = 2e5 + 7;
vector<int> tree(maxN);
int n;
void update(int pos, int num) {
    while (pos <= n) {
        tree[pos] += num;
        pos += lowbit(pos);
    }
}

int sum(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= lowbit(i);
    }
    return res;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) tree[i] = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> ans(n + 1);
    ans[n] = 1;
    int mx = 1;
    int res = 1;
    vector<PII> aid;
    for (int i = n-1; i >= 1; i--) {
        if (arr[i] <= i) {
            ans[i] = 1;
            res++;
            update(i, 1);
        } else aid.push_back({arr[i], i});
    }
    ranges::sort(aid, greater<PII>());
    // cout << res << ' ';
    for (auto &[_, idx] : aid) {
        // cout << _ << ' ' << idx << endl;
        update(idx, 1);
        int t = sum(arr[idx] - 1);
        res = max(res, t);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
