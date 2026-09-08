#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=1e6+100;
struct node{
    int son[26];
    int deep;
    int fa;
    int val;
};
node tree[N];
int n,m;
string s[N];
int top=1,ans=0;
queue<int>q[N];

void solve()
{
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        int x=1;
        for(int j=0;j<s[i].size();j++)
        {
            s[i][j]-='a';
            int y=x;
            if(tree[x].son[s[i][j]]==0)
            {
                tree[x].son[s[i][j]]=++top;
                x=top;
            }
            else
            {
                x=tree[x].son[s[i][j]];
            }
            tree[x].deep=tree[y].deep+1;
            tree[x].fa=y;
            q[x].push(i);
        }
    }
    // priority_queue<pair<int,int>>pq;
    set<pair<int, int>> st;
    for(int i=1;i<=n;i++)
    {
        int x=1;
        for(int j=0;j<s[i].size();j++)
        {
            x=tree[x].son[s[i][j]];
            if(tree[x].val==0)
            {
                tree[x].val=1;
                ans++;
                
            }
            while(q[x].size()&&q[x].front()<=i)
            {
                q[x].pop();
            }
            if(q[x].size())
            {   
                st.insert({q[x].front(),x});
                // pq.push({q[x].front(),x});
            }
        }
        // cout<<"--------\n"<<i<<'\n';
        while (st.size()) {
            if (st.begin()->first <= i) {
                // int a=st.begin()->first;
                // while(q[a].size()&&q[a].front()<=i)
                // {
                //     q[a].pop();
                // }
                // if(q[a].size())
                // {
                //     st.insert({q[a].front(),st.begin()->second});
                // }
                st.erase(st.begin());
            }
            else break;
        }
        while(st.size()>m)
        {
            int l =st.rbegin()->first;
            int r = st.rbegin()->second;
            st.erase({l, r});

            if(l<=i)
            {
                continue;
            }
            // cout<<l<<' '<<char(r+'a'-2)<<'\n';
            tree[r].val=0;
        }

    }
    cout<<ans<<'\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}
