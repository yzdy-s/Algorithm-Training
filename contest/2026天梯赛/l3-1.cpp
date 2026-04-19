#include <bits/stdc++.h>
using namespace std;
#define int long long

// 就诊时间段 预约时间段 患者ID 患者年龄
struct p {
    string name;
    int jz;
    int yy;
    int age;
    bool operator < (p &a) {
        if (age > 80 && a.age > 80) {
            return yy < a.yy;
        } else if (age > 80) return 1;
        else if (a.age > 80) return 0;
        else return yy < a.yy;
    }
};

class cmp {
    bool operator () (p &b, p &a) {
        if (b.age > 80 && a.age > 80) {
            return b.yy < a.yy;
        } else if (b.age > 80) return 1;
        else if (a.age > 80) return 0;
        else return b.yy < a.yy;
    }
};

signed main() {
    int n;cin >> n;
    map<string, p> mp; // name - p;
    vector<string> tr(n + 1); // 优先级最高的，当前时间段原本该就诊的人
    set<int, cmp> st;
    vector<pair<int, string>> res;
    vector<p> arr(n + 1); // 就诊顺序
    
    for (int i = 1; i <= n; i++) {
        int jz, yy, age;string name;cin >> jz >> yy >> name >> age;
        p t;
        t.jz = jz; t.yy = yy; t.name = name; t.age = age;
        tr[yy] = name;
        mp[name] = t;
        arr[i] = t;
    }


    set<string> cur; // 当前在医院的人
    set<p> CUR;
    set<string> vis; // 就诊过的人
    int idx = 1; // 当前不在医院的最早的下标
    for (int i = 1; i <= n; i++) {
        string benren = tr[i];
        while (idx <= n && arr[idx].jz <= i) {
            cur.insert(arr[idx].name);
            CUR.insert(mp[arr[idx].name]);
            idx++;
        }
        for (auto &j : CUR) cout << j.name << endl;
        cout << endl << endl;
        if (cur.size() == 0) continue;
        if (vis.count(benren)) { // 就诊过了，顺位下去
            p t = *CUR.begin();
            res.push_back({i, t.name});
            cur.erase(t.name);
            CUR.erase(t);
        } else {
            if (cur.count(benren) == 0) { // 当前就诊的人不在
                p t = *CUR.begin();
                res.push_back({i, t.name});
                cur.erase(*cur.begin());
                CUR.erase(t);
            } else {
                res.push_back({i, benren});
                vis.insert(benren);
                cur.erase(benren);
                CUR.erase(mp[benren]);
            }
        }
    }

    for (auto &i : res) cout << i.second << endl;
}