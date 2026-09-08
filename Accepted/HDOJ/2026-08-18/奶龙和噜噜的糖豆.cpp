#include<bits/stdc++.h>
using namespace std;
#define inv(x) (ksm(x, MOD - 2))
#define int long long
const int MOD = 998244353;
int ksm(int x, int n) {
    int ans = 1;
    x  %= MOD;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}

const int MN=5207;
int fa[MN],vis[MN];
vector<int> v[MN];
vector<int> ask[MN];
map<int, map<int, int>> LCA;

int find(int x){
    if(fa[x]!=x) fa[x]=find(fa[x]);
    return fa[x];
}

void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[x]=y;
}

void tarjan(int x){
    vis[x]=true;

    for(auto y : v[x]){
        if(vis[y]) continue;

        tarjan(y);
        merge(y,x);
    }

    for(auto y : ask[x]){
        if(vis[y]) {
            LCA[x][y] = find(y);
            LCA[y][x] = find(y);
        }
    }
}

vector<int> deep(MN);
void dfs(int x, int fa, int h) {
    deep[x] = h;
    for (auto &son : v[x]) {
        if (son == fa) continue;
        dfs(son, x, h + 1);
    }
}
void solve() {
    int n;cin >> n;
    LCA.clear();
    for (int i = 0; i <= n; i++) {
        fa[i] = i;
        v[i].clear();
        ask[i].clear();
        vis[i] = 0;
    }
    vector<int> cnt(n + 1);
    for (int i = 1; i < n; i++) {
        int x,y;cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
        cnt[y]++;
        cnt[x]++;
    }

    vector<int> lf;
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 1) lf.push_back(i);
    }
    for (int i = 0; i < lf.size(); i++) {
        for (int j = 0; j < lf.size(); j++) {
            ask[lf[i]].push_back(lf[j]);
        }
    }
    tarjan(1);
    dfs(1, 0, 1);
    int ans[2]={0,1};
    for (int i = 0; i < lf.size(); i++) {
        int a[2]={1,1};
        for (int j = 0; j < lf.size(); j++) {
            if (i == j) continue;
            int x = lf[i], y = lf[j];
            int fa = LCA[x][y];
            int len1 = deep[x] - deep[fa];
            int len2 = deep[y] - deep[fa];
            // cout << x << ' ' << y << ' ';
            // cout << len1 << ' ' << len2 << endl;
            if(len2*a[1]<a[0]*(len1+len2))
            {
                a[0]=len2;
                a[1]=len1+len2;
            }
        }
        if(ans[0]*a[1]<a[0]*ans[1])
        {
            ans[0]=a[0];
            ans[1]=a[1];
        }
    }

    cout<< ans[0]*inv(ans[1]) % MOD << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;cin >> T;
    while (T--) solve();
    return 0;
}
