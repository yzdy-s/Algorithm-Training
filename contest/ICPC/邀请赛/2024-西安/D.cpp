#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 100;
ll n, ans = 1e18, sum = 0;
ll a[N] = {0};
ll b[N] = {0};
void cjp(int x)
{
    ll res = 0;
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        ll y = a[i] - (i - 1) * x;
        if (y >= 0)
        {
            mp[y] += b[i];
            res = max(res, mp[y]);
        }
    }
    ans = min(ans, sum - res);
}
void solve()
{
    cin >> n;
    map<int, int> mp;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        sum += b[i];
    }
    v.push_back({1, a[1]});
    mp[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        int f = v.size();
        for (auto [l, r] : v)
        {
            int x = i - l;
            int y = a[i] - r;
            if (y < 0 || y % x||mp[y/x])
            {
                f--;
            }
            else
            {
                mp[y / x] = 1;
            }
        }
        if (f)
        {
            v.push_back({i, a[i]});
        }
    }
    for (auto [l, r] : mp)
    {
        cjp(l);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1; // cin >> T;
    while (T--)
        solve();
}