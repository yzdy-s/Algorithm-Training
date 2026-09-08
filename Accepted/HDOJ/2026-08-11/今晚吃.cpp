#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int c[2][2];
vector<string> res5 = {"01100", "00110", "10011", "11001"}, res6 =  {"110100", "001011"};
vector<string> ans[2][2];
void calc() {
    // 长度为 5
    int len = 5;
    for (auto s : res5) {
        int _01 = 0, _00 = 0, _10 = 0, _11 = 0;
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == '0') {
                if (s[j + 1] == '1') _01++;
                else _00++;
            } else {
                if (s[j + 1] == '1') _11++;
                else _10++;
            }
        }
        if (_01) ans[0][1].push_back(s);
        if (_00) ans[0][0].push_back(s);
        if (_10) ans[1][0].push_back(s);
        if (_11) ans[1][1].push_back(s);
    }

    // 长度为 6
    len = 6;
    for (auto s : res6) {
        int _01 = 0, _00 = 0, _10 = 0, _11 = 0;
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == '0') {
                if (s[j + 1] == '1') _01++;
                else _00++;
            } else {
                if (s[j + 1] == '1') _11++;
                else _10++;
            }
        }
        if (_01) ans[0][1].push_back(s);
        if (_00) ans[0][0].push_back(s);
        if (_10) ans[1][0].push_back(s);
        if (_11) ans[1][1].push_back(s);
    }


    // 长度为 4 
    len = 4;
    string s = "####";
    for (int st = 0; st < (1 << len); st++) {
        for (int bit = 0; bit < len; bit++) {
            if ((st >> bit) & 1) s[bit] = '1';
            else s[bit] = '0';
        }
        int _01 = 0, _00 = 0, _10 = 0, _11 = 0;
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == '0') {
                if (s[j + 1] == '1') _01++;
                else _00++;
            } else {
                if (s[j + 1] == '1') _11++;
                else _10++;
            }
        }
        if (_01) ans[0][1].push_back(s);
        if (_00) ans[0][0].push_back(s);
        if (_10) ans[1][0].push_back(s);
        if (_11) ans[1][1].push_back(s);
    }

    // 长度为 3
    len = 3;
    s = "###";
    for (int st = 0; st < (1 << len); st++) {
        for (int bit = 0; bit < len; bit++) {
            if ((st >> bit) & 1) s[bit] = '1';
            else s[bit] = '0';
        }
        int _01 = 0, _00 = 0, _10 = 0, _11 = 0;
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == '0') {
                if (s[j + 1] == '1') _01++;
                else _00++;
            } else {
                if (s[j + 1] == '1') _11++;
                else _10++;
            }
        }
        if (_01) ans[0][1].push_back(s);
        if (_00) ans[0][0].push_back(s);
        if (_10) ans[1][0].push_back(s);
        if (_11) ans[1][1].push_back(s);
    }

    // 长度为2
    len = 2;
    s = "##";
    for (int st = 0; st < (1 << len); st++) {
        for (int bit = 0; bit < len; bit++) {
            if ((st >> bit) & 1) s[bit] = '1';
            else s[bit] = '0';
        }
        int _01 = 0, _00 = 0, _10 = 0, _11 = 0;
        for (int j = 0; j < len - 1; j++) {
            if (s[j] == '0') {
                if (s[j + 1] == '1') _01++;
                else _00++;
            } else {
                if (s[j + 1] == '1') _11++;
                else _10++;
            }
        }
        if (_01) ans[0][1].push_back(s);
        if (_00) ans[0][0].push_back(s);
        if (_10) ans[1][0].push_back(s);
        if (_11) ans[1][1].push_back(s);
    }
}


void solve(){
    string s; cin >> s; int n = s.length();
    memset(c, 0, sizeof c);

    for (int i = 1; i < n; ++i) ++c[s[i-1]-'0'][s[i]-'0'];
    int t = (c[0][0] > 0) + (c[0][1] > 0) + (c[1][0] > 0) + (c[1][1] > 0);
    map<string, int> mp;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            if (c[i][j]) {
                for (auto &SSS : ans[i][j]) mp[SSS] += 1;
            } else {
                for (auto &SSS : ans[i][j]) mp[SSS] += LNF;
            } 
        }
    }

    int res = LNF;
    for (auto &[SSS, c] : mp) {
        if (c != t) continue;
        // cout << SSS << endl;
        int i = 0, j = 0;
        while (j < n && i < SSS.size()) {
            if (SSS[i] == s[j]) i++, j++;
            else j++;
        }
        if (i == SSS.size()) res = min(res, (int)SSS.size());
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    calc();
    int T = 1;cin >> T;
    while (T--) solve();
}
