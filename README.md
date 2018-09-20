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

## 1010 Radix （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1010-radix-25-%E5%88%86)

[C++ (24/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1010/main.cpp)

[Java (23/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1010/Main.java)

### 解题思路

进制转换。此题要注意的细节非常多。

* 最小进制：在要转化的数出现的数中最大数 + 1。最大进制： k + 1，k 为目标数。

* 从 min_radix 到 max_radix 遍历会超时，要使用[二分查找](https://github.com/Heliovic/AlgorithmSet/blob/master/BinarySearch/main.cpp)。

* 要使用 unsigned long long，注意输出时的格式说明符： *"%llu"*。

【测试点 19】仍然过不了， 求大神指教。

## 1011 World Cup Betting （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1011-world-cup-betting-20-%E5%88%86)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1011/Main.java)

## 1012 The Best Rank （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1012-the-best-rank-25-%E5%88%86)

[Java (19/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1012/Main.java)

### 解题思路

排序。测试点3、测试点4 运行超时，尝试改用 C++ 重写。

## 1013 Battle Over Cities （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1013-battle-over-cities-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1013/main.cpp)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1013/Main.java)

### 解题思路
去掉指定的 city 后，多次在主程序中 DFS，使得 visit 均为 1。主程序中 DFS 的次数即为图的连通分量数。若连通分量数为 n，则需要再加 n-1 条边使得所有连通分量连通。

## 1014 Waiting in Line （30 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1014-waiting-in-line-30-%E5%88%86)

[Java (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1014/Main.java)

### 解题思路

复杂模拟。

## 1015 Reversible Primes （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1015-reversible-primes-20-%E5%88%86)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1015/Main.java)

### 解题思路

Reversible primes 定义：在十进制下是质数，转为相应进制反转后再转回十进制后还是质数。

使用 Java 时要善于使用 Integer 和 String 的进制转换函数。

## 1016 Phone Bills （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1016-phone-bills-25-%E5%88%86)

[Java (15/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1016/Main.java)

## 1017 Queueing at Bank （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1017-queueing-at-bank-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/main.cpp)

[Java (23/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/Main.java)

### 解题思路

简单模拟。用 Java 最后一个测试点会超时。
