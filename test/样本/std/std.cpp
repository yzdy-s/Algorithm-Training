/* 
数据规范：
- 行末不得有多余空格
- 输入/输出的文件末尾均有一个换行

为了方便未来加数据，测试点不要加太多。
*/

#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=110;
ll a[N][N]={0},sum[N][N]={0},ans=0;
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                a[i][j]=-1e12;
            }
            sum[i][j]=a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[i][j]+=sum[i][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sum[j][i]+=sum[j-1][i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=i;k++)
            {
                for(int r=1;r<=j;r++)
                {
                    ans=max(ans,sum[i][j]-sum[k-1][j]-sum[i][r-1]+sum[k-1][r-1]);
                }
            }
        }
    }
    cout<<ans;
}

void test_solve() {
    int T_ = 1;
    //cin >> T_;
    while (T_--) solve();
}


// [ BEGIN, TEST_CASE )
const int BEGIN = 3;
const int TEST_CASE = 6;
 #define ONLINE_JUDGE 1
int main() {
    #ifndef ONLINE_JUDGE
        for (int i = BEGIN; i < TEST_CASE; ++i) {
            string in = "../" + to_string(i) + ".in";
            string out = "../" + to_string(i) + ".out";
            // string in = "../in0";
            // string out = "../out0";
            freopen(in.c_str(), "r", stdin);
            freopen(out.c_str(), "w", stdout);
            test_solve();
            cout.flush();
            cin.clear();
            cin.sync();
        }
    #else
        test_solve();
    #endif

    return 0;
}