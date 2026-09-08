#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 2e5 + 7;
struct node {
    int res[3] = {0};
    int lChar, rChar;
};
vector<node> tree(4 * MAXN);
vector<int> lazy(4 * MAXN, 0);

string s;

void pushup(int p, int l, int r) {
    for (int i = 0; i < 3; i++) {
        tree[p].res[i] = tree[2 * p].res[i] + tree[2 * p + 1].res[i];
    }
    if (tree[2 * p].rChar == tree[2 * p + 1].lChar) tree[p].res[tree[2 * p].rChar]--;
    tree[p].lChar = tree[2 * p].lChar;
    tree[p].rChar = tree[2 * p + 1].rChar;
}

void build(int p, int l, int r) {
    if (l == r) {
        tree[p].res[s[l] - 'A']++;
        tree[p].lChar = (s[l] - 'A');
        tree[p].rChar = (s[l] - 'A');
        return;
    }
    int mid = l + r >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    pushup(p, l, r);
}

void pushdown(int p, int l, int r) {
    if (lazy[p] == 0) return;
    lazy[2 * p] += lazy[p];
    lazy[2 * p + 1] += lazy[p];

    int k = lazy[p]; lazy[p] = 0;

    // 左儿子
    vector<int> temp(3, 0);
    for (int i = 0; i < 3; i++) {
        temp[(i + k) % 3] += tree[2 * p].res[i];
    }
    for (int i = 0; i < 3; i++) {
        tree[2 * p].res[i] = temp[i];
    }
    for (int i = 0; i < 3; i++) temp[i] = 0;
    tree[2 * p].lChar = (tree[2 * p].lChar + k) % 3;
    tree[2 * p].rChar = (tree[2 * p].rChar + k) % 3;

    // 右儿子
    for (int i = 0; i < 3; i++) {
        temp[(i + k) % 3] += tree[2 * p + 1].res[i];
    }
    for (int i = 0; i < 3; i++) {
        tree[2 * p + 1].res[i] = temp[i];
    }
    tree[2 * p + 1].lChar = (tree[2 * p + 1].lChar + k) % 3;
    tree[2 * p + 1].rChar = (tree[2 * p + 1].rChar + k) % 3;

    pushup(p, l, r);
}

void change(int p, int l, int r, int x, int y, int k) {
    if (x <= l && r <= y) {
        vector<int> temp(3, 0);
        lazy[p] += k;
        for (int i = 0; i < 3; i++) {
            temp[(i + k) % 3] = tree[p].res[i];
        }
        for (int i = 0; i < 3; i++) {
            tree[p].res[i] = temp[i];
        }
        tree[p].lChar = (tree[p].lChar + k) % 3;
        tree[p].rChar = (tree[p].rChar + k) % 3;
        return;
    }
    pushdown(p, l, r);
    int mid = l + r >> 1;
    if (x <= mid) change(2 * p, l, mid, x, y, k);
    if (y >= mid + 1) change(2 * p + 1, mid + 1, r, x, y, k);
    pushup(p, l, r);
}

// A: 0
void solve(){
    int n, q;cin >> n >> q;
    cin >> s;
    s = "#" + s;
    build(1, 1, n);
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int l, r;cin >> l >> r;
            change(1, 1, n, l, r, 1);
        } else {
            cout << tree[1].res[0] << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
