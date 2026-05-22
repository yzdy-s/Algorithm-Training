#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
/*
    找出两个数组的中位数
*/
void solve(){
    vector<int> a = {1, 3, 5, 7, 9};
    vector<int> b = {2, 4, 6, 8, 10};
    int n = 5;
    int l = 0, r = n;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        int x = a[mid];
        int ll = 1, rr = n;
        while (ll + 1 < rr) {
            int mmid = ll + rr >> 1;
            if (b[mmid] <= x) ll = mmid;
            else rr = mmid;
        }
        if (ll + mid < n) l = mid;
        else r = mid;
    }
    cout << a[l] << endl;
}

/*
    降序快排
*/
void s2(){
    vector<int> arr = {2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
    // 加上 greater<int> 就可以实现啦
    ranges::sort(arr, greater<int>());
    for (auto &i : arr) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}