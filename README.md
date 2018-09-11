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

## 1005 Spell It Right（20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1005-spell-it-right20-%E5%88%86)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1005/Main.java)

## 1006 Sign In and Sign Out（25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1006-sign-in-and-sign-out25-%E5%88%86)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1006/Main.java)

## 1007 Maximum Subsequence Sum（25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1007-maximum-subsequence-sum25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1007/main.cpp)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1007/Main.java)

### 解题思路

动态规划，向前先后均可，注意记录子串开始和结束位置的方法。对于向后递推，设置一个 from 数组记录以 i 结尾的最大和子串的 i 的前一个数。

## 1008 Elevator（20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1008-elevator20-%E5%88%86)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1008/Main.java)

## 1009 Product of Polynomials（25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1009-product-of-polynomials25-%E5%88%86)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1009/Main.java)

