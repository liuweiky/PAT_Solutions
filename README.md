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

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1012/main.cpp)

[Java (19/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1012/Main.java)

### 解题思路

排序。java 测试点3、测试点4 运行超时，尝试改用 C++ 重写。

20181011: C++ done

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

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1016/main.cpp)

[Java (15/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1016/Main.java)

## 1017 Queueing at Bank （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1017-queueing-at-bank-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/main.cpp)

[Java (23/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/Main.java)

### 解题思路

简单模拟。用 Java 最后一个测试点会超时。

## 1018 Public Bike Management （30 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1018-public-bike-management-30-%E5%88%86)

[C++ (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1018/main.cpp)

### 解题思路

先使用 Dijkstra 算法求出所有最短路。之后简单模拟按照路径行进，计算出需要带的自行车。

注意，只允许由前向后单向带车，路径中后继结点的车不可带到前驱结点！

## 1019 General Palindromic Number （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1019-general-palindromic-number-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1019/main.cpp)

## 1020 Tree Traversals （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1020-tree-traversals-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1020/main.cpp)

### 解题思路

由中根遍历和后根遍历递归构建二叉树。

后根遍历序列的最后一个结点是该序列对应下的根结点。而利用此根结点，可在中根遍历序列中划分左右子树。

由划分后的左右子树得到下一递归时的数组索引，递归构造左右子树。

## 1021 Deepest Root （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1021-deepest-root-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1021/main.cpp)

### 解题思路

DFS。**非递归的 DFS 次数为连通分量数。**

## 1022 Digital Library （30 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1022-digital-library-30-%E5%88%86)

[C++ (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1022/main.cpp)

### 解题思路

字符串处理。注意 `cin.ignore();` 和 `setfill(char)`、 `setw(int)` 的使用。

## 1023 Have Fun with Numbers （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1023-have-fun-with-numbers-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1023/main.cpp)

## 1024 Palindromic Number （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1024-palindromic-number-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1024/main.cpp)

## 1025 PAT Ranking （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1025-pat-ranking-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1025/main.cpp)

## 1026 Table Tennis （30 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1026-table-tennis-30-%E5%88%86)

[C++ (12/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1026/main.cpp)

## 1027 Colors in Mars （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1027-colors-in-mars-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1027/main.cpp)

[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1027/Main.java)

## 1028 List Sorting （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1028-list-sorting-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1028/main.cpp)

## 1031 Hello World for U （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1031-hello-world-for-u-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1031/main.cpp)

### 解题思路

应满足的条件：

* U 越接近 “square” 形状越好 -> n1 与 n2 之差的绝对值越小越好
* n2 ≤ n1 = n3

## 1035 Password （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1035-password-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1035/main.cpp)

## 1036 Boys vs Girls （25 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1036-boys-vs-girls-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1036/main.cpp)

## 1042 Shuffling Machine （20 分）

[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1042-shuffling-machine-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1042/main.cpp)

### 解题思路

简单模拟。使用 stringstream 将 int 转为 string。

## 1046 Shortest Distance （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1046-shortest-distance-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1046/main.cpp)

### 解题思路

若直接遍历，最后一个测试点很容易就超时了。

使用 dis 数组记录从 1 到 i + 1 的路径长度。则 s 到 t 的顺时针长度为 `dis[t - 1] - dis[s - 1], s < t`。其反方向长度为 `total_dis - dis1`，取两个方向的长度较小值即为答案。

## 1055 The World's Richest （25 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1055-the-worlds-richest-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1055/main.cpp)

## 1061 Dating （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1061-dating-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1061/main.cpp)

## 1062 Talent and Virtue （25 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1062-talent-and-virtue-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1062/main.cpp)

### 解题思路

将各类人抽象成一个可以比较的数 `type` 方便排序。

## 1065 A+B and C (64bit) （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1065-ab-and-c-64bit-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1065/main.cpp)

### 解题思路

* **方法一**
	* 若 a > 0 且 b > 0，但 a + b < 0，则说明 a + b >= 2^63。
	* 若 a < 0 且 b < 0，但 a + b >= 0，则说明 a + b < -2^63。
	* 注意，这是不严谨的，因为题目中说明，a, b, c 的范围可以达到 `LONG_LONG_MAX + 1`，但测试用例可以通过。
* **方法二**
	* 大数加减法

## 1073 Scientific Notation （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1073-scientific-notation-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1073/main.cpp)

### 解题思路

分类讨论，模拟移位。

## 1075 PAT Judge （25 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1075-pat-judge-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1075/main.cpp)

### 解题思路

数组排序。记得在结构体内部记录 id。

**以用户 id 为数组索引节省运行时间。**

## 1077 Kuchiguse （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1077-kuchiguse-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1077/main.cpp)

### 解题思路

使用 `gets()` 编译失败。

## 1082 Read Number in Chinese （25 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1082-read-number-in-chinese-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1082/main.cpp)

### 解题思路

1. 将数字去掉符号后转为 9 位的格式，不足前面填0

2. 从第一个非 0 位开始，每输出一位数，随即输出对应单位，个位用单位 `""` 处理，注意判断最后一位的个位，不要多输出空格

3. 输出某一位 `i` 后，检查下一个不是 0 的位 `n` 是否等于 `i + 1` ，若是，继续输出，若不是，多输出一个 `"ling"`。注意 0 一直连续到最后一位的情况

4. 对于千万位的处理，若 `i = 4` ，直接输出 `"Wan"` ，否则，若有 `n` 跨越 4，且不是从 0 开始跨越，也输出 `"Wan"`

## 1083 List Grades （25 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1083-list-grades-25-%E5%88%86)

[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1083/main.cpp)

## 1084 Broken Keyboard （20 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1084-broken-keyboard-20-%E5%88%86)

[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1084/main.cpp)

### 解题思路

打表（散列）

## 1095 Cars on Campus （30 分）
[Problem description](https://github.com/Heliovic/My_PAT_Answer/blob/master/PROBLEMS.md#1095-cars-on-campus-30-%E5%88%86)

[C++ (27/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1095/main.cpp)
