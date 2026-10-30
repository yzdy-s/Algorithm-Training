#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
int n;
const int MAXN = 1e5 + 7;
const int LNF = 1e17;
vector<int> a(MAXN), L(MAXN);

vector<PII> jiao(PII a, PII b) {
    PII res;
    res.first = max(a.first, b.first);
    res.second = min(a.second, b.second);
    if (res.first > res.second) return {};
    return {res};
}

bool check(int x) {
    vector<PII> cur;
    cur.push_back({a[1] - x, a[1] + x});
    for (int i = 2; i <= n; i++) {
        vector<PII> nxt;
        PII k = {a[i] - x, a[i] + x}; // 当前区间
        for (auto pii : cur) {
            PII a = {pii.first + L[i], LNF}; // 向上移动 l
            PII b = {-LNF, pii.second - L[i]}; // 向下移动
            vector<PII> t = jiao(a, k);
            if (t.size()) nxt.push_back(t[0]);
            t = jiao(b, k);
            if (t.size()) nxt.push_back(t[0]);
        }
        cur.clear();
        int mmx = -LNF, mmn = LNF;
        for (auto &pii : nxt) {
            if (pii.second == a[i] + x) mmn = min(mmn, pii.first);
            if (pii.first == a[i] - x) mmx = max(mmx, pii.second);
        }
        if (mmx != -LNF) cur.push_back({a[i] - x, mmx});
        if (mmn != LNF) cur.push_back({mmn, a[i] + x});
    }
    return cur.size() != 0;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) cin >> L[i];

    int l = -1, r = 1e9 + 7;
    int ans = 1e9 + 7;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            r = mid;
            ans = mid;
        } else l = mid;
    }

    cout << ans << endl;
}

signed main() {
    int T = 1;
    cin >> T;
    while (T--) solve();
}