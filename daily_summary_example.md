# 📝 2026-04-30

> 共 AC **2** 题 · 贪心 1 · 树链剖分 1

---

## P1484 种树

| 平台 | 题型 | 难度 |
| :--- | :--- | :--- |
| Luogu | 贪心、反悔堆 | ★★☆☆☆ |

**思路**：在 $n$ 个位置中选 $k$ 个种树，最大化收益。采用反悔贪心策略：每次选最大收益点后，创建一个"反悔选项"（收益 = 左 + 右 - 当前），允许后续选择时撤销之前的决定。

**复杂度**：$O(k \log n)$

**关键代码**：
```cpp
int l = pos[i].l, r = pos[i].r;
pos[l].r = r; pos[r].l = l;
q.push({val[l] + val[r] - val[i], l});
```

[题目链接](https://www.luogu.com.cn/problem/P1484) · [源码](../Accepted/Luogu/2026-04-30/P1484.cpp)

---

## P2619 树的统计

| 平台 | 题型 | 难度 |
| :--- | :--- | :--- |
| Luogu | 树链剖分 | ★★★☆☆ |

**思路**：支持单点修改、路径查询最大值/和。通过树链剖分将树上路径转化为区间问题，配合线段树维护。

**复杂度**：$O(n \log^2 n)$

**关键代码**：
```cpp
while(top[u] != top[v]) {
    if(dep[top[u]] < dep[top[v]]) swap(u, v);
    update(1, id[top[u]], id[u], k);
    u = fa[top[u]];
}
```

[题目链接](https://www.luogu.com.cn/problem/P2619) · [源码](../Accepted/Luogu/2026-04-30/P2619.cpp)
