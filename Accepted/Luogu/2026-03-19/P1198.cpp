#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
int pos = 0;
vector<int> tree(4 * maxN);
vector<int> arr(maxN);

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = l + r >> 1;
    build(2*p, l, mid);
    build(2*p+1, mid+1, r);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}

void change(int p, int l, int r, int pos) {
    if (l == r && l == pos) {
        tree[p] = arr[pos];
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid) change(2*p, l, mid, pos);
    else change(2*p+1, mid+1, r, pos);
    tree[p] = max(tree[2*p], tree[2*p + 1]);
}

int calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p];
    int mid = l + r >> 1;
    int res = -LNF;
    if (x <= mid) res = max(res, calc(2*p, l, mid, x, y));
    if (y >= mid+1) res = max(res, calc(2*p+1, mid+1, r, x, y));
    return res;
}

void solve(){
    int q, D;cin >> q >> D;
    int t = 0;
    while (q--) {
        char op;cin >> op;
        if (op == 'A') {
            int n;cin >> n;
            n = (n + t) % D;
            arr[++pos] = n;
            change(1, 1, 2e5, pos);
        } else {
            int l;cin >> l;
            int r = pos;
            l = max(1LL, pos - l + 1);
            t = calc(1, 1, 2e5, l, r);
            cout << t << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
