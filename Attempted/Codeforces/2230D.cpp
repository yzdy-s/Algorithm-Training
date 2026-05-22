#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 5e5 + 7;

vector<int> arr(maxN + 7);
vector<int> tree(4*maxN + 7);
vector<int> lazy(4*maxN + 7);

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = tree[2*p] + tree[2*p+1];
}

void pushdown(int p, int l, int r) {
    int mid = (l + r) / 2;
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];
    
    tree[2 * p] += (mid - l + 1) * lazy[p];
    tree[2 * p + 1] += (r - (mid + 1) + 1) * lazy[p];
    lazy[p] = 0;
}

void change(int p, int l, int r, int x, int y, int num) {
    if (x<=l && r<=y) {
        tree[p] += (r - l + 1) * num;
        lazy[p] += num;
        return;
    }

    if (lazy[p] != 0) {
        pushdown(p, l, r);
    }
    int mid = (l + r) / 2;
    if (x <= mid) {
        change(2*p, l, mid, x, y, num);
    }

    if (y >= (mid+1)) {
        change(2*p+1, mid+1, r, x, y, num);
    }
    tree[p] = tree[2*p] + tree[2*p + 1];
}


int calc(int p, int l, int r, int x, int y) {
    if (x<=l && r<=y) return tree[p];

    if (lazy[p] != 0) pushdown(p, l, r);

    int res = 0;
    int mid = (l + r) / 2;
    if (x <= mid) res += calc(2*p, l, mid, x, y);
    if (y >= mid+1) res += calc(2*p+1, mid+1, r, x, y);
    return res;
}



void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) arr[i] = 0;
    
    build(1, 1, n);

    vector<int> dp(n + 1);
    int un = 1;
    for (int i = 1; i <= n; i++) {
        int A = a[i], B = b[i];
        if (A == B) {
            dp[i] = calc(1, 1, n, 1, n) + un;
            change(1, 1, n, 1, n, 1); un++; // 所有数 +1
            if (A == 1) {
                change(1, 1, n, 1, 1, un - 1);
                un = 0;
            } else {
                int la = calc(1, 1, n, A - 1, A - 1);
                change(1, 1, n, A - 1, A - 1, -la);
                change(1, 1, n, A    , A    , la - 1);
            }
        } else {
            int t = 0;
            if (A == 1) {
                un = 0;
            } else {
                int la = calc(1, 1, n, A - 1, A - 1);
                change(1, 1, n, A - 1, A - 1, -la);
            }

            if (B == 1) {
                un = 0;
            } else {
                int la = calc(1, 1, n, B - 1, B - 1);
                change(1, 1, n, B - 1, B - 1, -la);
            }

            dp[i] = calc(1, 1, n, 1, n) + un;
            change(1, 1, n, 1, n, 1); un++;
            
            if (A == 1) {
                un = 0;
            } else {
                int la = calc(1, 1, n, A - 1, A - 1);
                change(1, 1, n, A - 1, A - 1, -la);
            }

            if (B == 1) {
                un = 0;
            } else {
                int la = calc(1, 1, n, B - 1, B - 1);
                change(1, 1, n, B - 1, B - 1, -la);
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) res += dp[i];
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}