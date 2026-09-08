#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 2e5 + 7;
struct node {
    int res = 0;
    int cnt[2] = {0};
    int ln, rn;
};
vector<node> tree(4 * MAXN);
vector<int> lazy1(4 * MAXN, -1); // -1 代表空
vector<int> lazy2(4 * MAXN);     // 0  代表空

void pushup(int p, int l, int r) {
    for (int i = 0; i <= 1; i++) tree[p].cnt[i] = tree[2 * p].cnt[i] + tree[2 * p + 1].cnt[i];
    tree[p].res = tree[2 * p].res + tree[2 * p + 1].res;
    if (tree[2*p].rn != tree[2 * p + 1].ln) tree[p].res++;
    tree[p].ln = tree[2 * p].ln;
    tree[p].rn = tree[2 * p + 1].rn;
}

void pushdown(int p, int l, int r) {
    int mid = l + r >> 1;
    if (lazy1[p] != -1) {
        int x = lazy1[p];
        lazy1[p] = -1;

        lazy1[2 * p] = x;
        lazy1[2 * p + 1] = x;
        lazy2[2 * p] = 0;
        lazy2[2 * p + 1] = 0;

        tree[2 * p].cnt[x] = (mid - l + 1);
        tree[2 * p].cnt[x ^ 1] = 0;
        tree[2 * p].ln = tree[2 * p].rn = x;
        tree[2 * p].res = 0;

        tree[2 * p + 1].cnt[x] = (r - mid);
        tree[2 * p + 1].cnt[x ^ 1] = 0;
        tree[2 * p + 1].ln = tree[2 * p + 1].rn = x;
        tree[2 * p + 1].res = 0;
    } else if (lazy2[p] == 1) {
        lazy2[p] = 0;
        if (lazy1[2 * p] != -1) {
            lazy1[2 * p] ^= 1;
        } else {
            lazy2[2 * p] ^= 1;
        }
        if (lazy1[2 * p + 1] != -1) {
            lazy1[2 * p + 1] ^= 1;
        } else {
            lazy2[2 * p + 1] ^= 1;
        }

        swap(tree[2 * p].cnt[0], tree[2 * p].cnt[1]);
        tree[2 * p].ln ^= 1;
        tree[2 * p].rn ^= 1;

        swap(tree[2 * p + 1].cnt[0], tree[2 * p + 1].cnt[1]);
        tree[2 * p + 1].ln ^= 1;
        tree[2 * p + 1].rn ^= 1;
    }
}

void change1(int p, int l, int r, int x, int y, int num) {
    if (x <= l && r <= y) {
        tree[p].cnt[num] = (r - l + 1);
        tree[p].cnt[num ^ 1] = 0;
        lazy2[p] = 0;
        lazy1[p] = num;
        tree[p].ln = num;
        tree[p].rn = num;
        tree[p].res = 0;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) change1(2 * p, l, mid, x, y, num);
    if (y > mid) change1(2 * p + 1, mid + 1, r, x, y, num);
    pushup(p, l, r);
}

void change2(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        swap(tree[p].cnt[0], tree[p].cnt[1]);
        if (lazy1[p] != -1) lazy1[p] ^= 1;
        else lazy2[p] ^= 1;
        tree[p].ln ^= 1;
        tree[p].rn ^= 1;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) change2(2 * p, l, mid, x, y);
    if (y > mid) change2(2 * p + 1, mid + 1, r, x, y);
    pushup(p, l, r);
}

vector<int> arr(MAXN);
void build(int p, int l, int r) {
    if (l == r) {
        int x = arr[l];
        tree[p].cnt[x] = 1;
        tree[p].cnt[x ^ 1] = 0;
        tree[p].ln = x;
        tree[p].rn = x;
        tree[p].res = 0;
        return;
    }
    int mid = l + r >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p, l, r);
}

int calc(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p].res;
    pushdown(p, l, r);
    int mid = l + r >> 1;
    int a = 0, b = 0, res = 0;
    if (x <= mid) {
        res += calc(2 * p, l, mid, x, y);
        a = 1;
    }
    if (y > mid) {
        res += calc(2 * p + 1, mid + 1, r, x, y);
        b = 1;
    }
    if (a && b && tree[2 * p].rn != tree[2 * p + 1].ln) {
        res++;
    }
    return res;
}

int cccc(int p, int l, int r, int pos) {
    if (l == r && l == pos) return tree[p].rn;
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (pos <= mid) {
        return cccc(2 * p, l, mid, pos);
    } else {
        return cccc(2 * p + 1, mid + 1, r, pos);
    }
}
void solve(){
    int n, q;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    for (int i = 1; i <= 4 * n; i++) {
        lazy1[i] = -1;
        lazy2[i] = 0;
    }
    while (q--) {
        int op, l, r;cin >> op >> l >> r;
        if (op == 1) {
            int x;cin >> x;
            change1(1, 1, n, l, r, x);
        } else if (op == 2) {
            change2(1, 1, n, l, r);
        } else {
            cout << calc(1, 1, n, l, r) << endl;
        }
    }
    
    // for (int i = 1; i <= n; i++) cout << cccc(1, 1, n, i) << ' ';
    // cout << endl;
    // cout << calc(1, 1, n, 5, 6) << endl;
    // cout << calc(1, 1, n, 6, 7) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}