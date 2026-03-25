#include <bits/stdc++.h>
using namespace std;
#define ll long long
int dp[22][22] = {0};
int vis[22] = {0};
int n, k, m;
ll ans = 0;
int calc(int z)
{
    int mn = 1e9, id = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            int x = 0;
            for (int l = 1; l <= i; l++)
            {
                for (int r = max(l, i); r <= n; r++)
                {
                    x += dp[l][r];
                }
            }
            if (x < mn)
            {
                mn = x;
                id = i;
            }
        }
    }
    ans += mn * z;
    vis[id] = 1;
    return id;
}
void del(int i)
{
    for (int l = 1; l <= i; l++)
    {
        for (int r = max(l, i); r <= n; r++)
        {
            dp[l][r] = 0;
        }
    }
}
void solve()
{

    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        dp[l][r]++;
    }

    for (int i = k; i > 0; i--)
    {
        del(calc(i));
    }
    cout << ans << '\n';
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