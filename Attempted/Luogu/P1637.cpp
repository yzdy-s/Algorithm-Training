#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> arr(1e4 + 7);

class segmentTree{
    private: vector<int> tree;

    public:
    segmentTree(int n):tree(n+1){}
    void add(int p, int l, int r, int x) {
        if (l == r && l == x) {
            tree[x]++;
            return;
        }
        int mid = l + r >> 1;
        if (x <= mid) add(2*p, l, mid, x);
        else add(2*p+1, mid+1, r, x);
        tree[p] = tree[2*p] + tree[2*p+1];
    }

    int calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        int mid = l + r >> 1;
        int res = 0;
        if (x <= mid) res += calc(2*p, l, mid, x, y);
        if (y >= mid+1) res += calc(2*p+1, mid+1, r, x, y);
        return res;
    }
};


void solve(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    segmentTree tree1(1e5 + 7);
    segmentTree tree2(1e5 + 7);
    segmentTree tree3(1e5 + 7);

    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        tree1.add(1, 1, 1e5, num);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}