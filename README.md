# My PAT Answers
记录我在刷 PAT 甲级时遇到的一些问题以及总结的经验。做法可能不是最优的，如有更好的解法，欢迎 PR！

## 1001 A+B Format（20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1001-ab-format20-%E5%88%86)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1001/Main.java)

## 1002 A+B for Polynomials（25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1002-ab-for-polynomials25-%E5%88%86)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1002/Main.java)

## 1003 Emergency（25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1003-emergency25-%E5%88%86)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1003/Main.java)

### 解题思路

先通过 dijkstra 算法求出最短的路径长度，之后从终点回溯 dfs，记录满足：dis[u] + cost(u, v) = dis[v] 的点，生成路径。递归出口：u 是起点。

## 1004 Counting Leaves（30 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1004-counting-leaves30-%E5%88%86)

[Java (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1004/Main.java)

### 解题思路

此题较难构建左右子树的指针结构。利用数组保存标号对应结点的子节点。如：对于 id 号结点，其子节点为 nodes[id].childs 的 arraylist。构建完毕后简单地 dfs 或 bfs 搜索并记录即可。
