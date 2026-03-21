#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

class Manacher {
private:
    string s;           // 原始字符串
    string t;           // 预处理后的字符串
    vector<int> p;      // 回文半径数组（p[i] 就是原回文串的实际长度）

    // 预处理字符串并计算 p 数组
    void build() {
        if (s.empty()) return;
        t = "^";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.length();
        p.assign(n, 0);
        int c = 0, r = 0;

        // 2. 马拉车核心算法
        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * c - i;
            if (i < r) {
                p[i] = min(r - i, p[mirror]);
            }
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
        }
    }

public:
    Manacher(const string& str) : s(str) {
        build();
    }

    // 最长回文子串
    string getMaxPal() {
        if (s.empty()) return "";
        int maxLen = 0, centerIdx = 0;
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIdx = i;
            }
        }
        int start = (centerIdx - 1 - maxLen) / 2;
        return s.substr(start, maxLen);
    }

    // O(1) 时间复杂度判断 s[L...R] 是否为回文串
    // L 和 R 是原字符串 s 的下标 (0-based)
    bool isPal(int L, int R) {
        if (L < 0 || R >= s.length() || L > R) return false;
        int len = R - L + 1;
        int center = L + R + 2;
        return p[center] >= len;
    }

    // 计算原字符串中回文子串的总数量
    long long getPalCnt() {
        long long total = 0;
        for (int val : p) {
            total += (val + 1) / 2;
        }
        return total;
    }

    // 判断 s 的某个前缀或后缀是否为回文（返回最长长度）
    // 常用于解决字符串拼接、LeetCode 214 等问题
    int getMaxPrePal() {
        int maxLen = 0;
        for (int i = 1; i < p.size() - 1; ++i) {
            if (i - p[i] == 1) { 
                maxLen = max(maxLen, p[i]);
            }
        }
        return maxLen;
    }

    int getMaxBacPal() {
        int maxLen = 0;
        int lastHashIndex = t.length() - 2;
        for (int i = 1; i < p.size() - 1; ++i) {
            if (i + p[i] == lastHashIndex) { 
                maxLen = max(maxLen, p[i]);
            }
        }
        return maxLen;
    }
};

void solve(){
    string s;cin >> s;
    Manacher m(s);
    int res = m.getMaxPal().size();
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
