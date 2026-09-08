#include <bits/stdc++.h>
using namespace std;
#define int long long
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define FAST_IO
namespace fin{const int SIZE=1<<16;char buf[SIZE],*S,*T;inline char getchar(){if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return'\n';}return*S++;}}namespace fout{const int SIZE=1<<12;char buf[SIZE],*S=buf,*T=buf+SIZE;inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}inline void putchar(char c){*S++=c;if(S==T)flush();}struct Flusher{~Flusher(){flush();}}_;}
#define getchar fin::getchar
#define putchar fout::putchar
namespace fio{struct Reader{template<typename T>Reader&operator>>(T&x){char c=getchar();T f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}x*=f;return*this;}Reader&operator>>(char&c){c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();return*this;}Reader&operator>>(char*str){int len=0;char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str[len++]=c;c=getchar();}str[len]='\0';return*this;}Reader&operator>>(std::string&str){str.clear();char c=getchar();while(c==' '||c=='\n'||c=='\r')c=getchar();while(c!=' '&&c!='\n'&&c!='\r'){str.push_back(c);c=getchar();}return*this;}}cin;const char endl='\n';struct Writer{template<typename T>Writer&operator<<(T x){if(x==0){putchar('0');return*this;}if(x<0){putchar('-');x=-x;}static int sta[45];int top=0;while(x){sta[++top]=x%10;x/=10;}while(top){putchar(sta[top]|48);--top;}return*this;}Writer&operator<<(char c){putchar(c);return*this;}Writer&operator<<(char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const char*str){int cur=0;while(str[cur])putchar(str[cur++]);return*this;}Writer&operator<<(const std::string&str){for(char c:str)putchar(c);return*this;}}cout;}
#define cin fio::cin
#define cout fio::cout
#define endl fio::endl
struct SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * p, l, mid, arr);
        build(2 * p + 1, mid + 1, r, arr);
        tree[p] = tree[2 * p] + tree[2 * p + 1];
        lazy[p] = 0;
    }

    void pushdown(int p, int l, int r) {
        if (lazy[p] == 0) return;
        
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        tree[2 * p] += lazy[p];
        tree[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }

    void change(int p, int l, int r, int x, int y, int num) {
        if (x <= l && r <= y) {
            tree[p] += num;
            lazy[p] += num;
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid) change(2 * p, l, mid, x, y, num);
        if (y >= mid + 1) change(2 * p + 1, mid + 1, r, x, y, num);
        
        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }

    int calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        pushdown(p, l, r);
        
        int res = 0; 
        int mid = (l + r) >> 1;
        
        if (x <= mid) res += calc(2 * p, l, mid, x, y);
        if (y >= mid + 1) res += calc(2 * p + 1, mid + 1, r, x, y);
        return res;
    }

public:
    // 构造函数
    SegmentTree(int size) {
        tree.assign(4 * size + 7, 0);
        lazy.assign(4 * size + 7, 0);
    }

    // 初始化建树（1-indexed）
    void init(const vector<int>& arr, int size) {
        n = size;
        build(1, 1, n, arr);
    }

    // 区间加：将 [x, y] 区间内的所有值加上 num
    void update(int x, int y, int num) {
        if (x > y) return;
        change(1, 1, n, x, y, num);
    }

    // 区间和查询
    int query_sum(int x, int y) {
        if (x > y) return -LNF;
        return calc(1, 1, n, x, y);
    }
};


const int N=1e5+100;
SegmentTree F(N), B(N);
int len;
int tree[N];
int dp[N];
void up(int x,int d)
{
    while(x<=len)
    {
        tree[x]=max(d,tree[x]);
        x+=x&-x;
    }
}
int mx(int x)
{
    int ans=0;
    while(x>0)
    {
        ans=max(tree[x],ans);
        x-=x&-x;
    }
    return ans;
}
void solve(){
    int n, m;cin >> n >> m;
    len = n * m;
    vector<int> arr(len + 1);
    unordered_map<int, int> pos;
    for (int i = 1; i <= len; i++) {
        int x;cin >> x;
        pos[x] = i;
    }
    for (int i = 1; i <= len; i++) {
        int x;cin >> x;
        arr[i] = pos[x];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        
    }
    cout<<len
}

signed main() {
    int T = 1;cin >> T;
    while (T--) solve();
}