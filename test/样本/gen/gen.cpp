/* 
数据规范：
- 行末不得有多余空格
- 输入/输出的文件末尾均有一个换行

为了方便未来加数据，测试点不要加太多。
*/

#include <iostream>
#include <chrono>
#include <random>
using namespace std;

static mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int rnd_int(int a, int b) {
    uniform_int_distribution<int> dist(a, b);
    return dist(rnd);
}

void solve() {
    int n=rnd_int(1,20);
    cout<<n<<'\n';
    for(int i=1;i<=n;i++)
    {
        int x=rnd_int(80000,100000);
        cout<<x<<' ';
    }
    cout<<'\n';
}


void test_solve() {
    int T_ = 10;
    cout << T_<<'\n';
    while (T_--) solve();
}

/* [BEGIN, TEST_CASE ) */
const int BEGIN = 3;
const int TEST_CASE = 6;
int main() {
    for (int i = BEGIN; i < TEST_CASE; ++i) {
        string out = "../" + to_string(i) + ".in";
        freopen(out.c_str(), "w", stdout);
        test_solve();
        cout.flush();    
    }

    return 0;
}