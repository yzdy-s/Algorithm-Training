#include <bits/stdc++.h>
using namespace std;
#define int long long
/*
1 s1：对应查找操作，查找字符串 s 

​
  在当前字符串 T 中前 13 次出现的位置。
2 p s2：对应插入操作，将字符串 s 



​
  的第 1 个字符插入到当前字符串 T 中“下标为 p 的字符”之前。当 p=∣T∣ 时，表示插入到字符串末尾。

  3 l r：对应翻转操作，将当前字符串 T 中下标从 l 到 r 的连续子串翻转。
*/
signed main() {
    int n; string s;cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        int op;cin >> op;
        if (op == 1) {
            vector<int> res;
            string aid;cin >> aid;
            for (int ii = 0; ii < s.size(); ii++) {
                int f = 1;
                for (int j = 0; j < aid.size(); j++) {
                    if (aid[j] != s[j + ii]) f = 0;
                }
                if (f) res.push_back(ii);
                if (res.size() == 3) break;
            }
            if (res.size() == 0) cout << -1 << endl;
            for (int i = 0; i < res.size(); i++) cout << res[i] << " \n"[i == res.size() - 1];
        } else if (op == 2) {
            int p; string aid;cin >> p >> aid;
            s.replace(p, 0, aid);
            cout << s << endl;
        } else {
            int l, r;cin >> l >> r;
            // cout << l << ' ' << r << ' ';
            // cout << s << ' ';
            string t;
            for (int i = l; i <= r; i++) t += s[i];
            reverse(t.begin(), t.end());
            for (int i = l; i <= r; i++) s[i] = t[i - l];
            cout << s << endl;
        }
    }
}