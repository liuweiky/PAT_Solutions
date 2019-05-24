# My PAT Solutions
记录我在刷 PAT 甲级时遇到的一些问题以及总结的经验。做法可能不是最优的，如有更好的解法，欢迎 PR！

## 1001 A+B Format（20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1001/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1001/Main.java)

## 1002 A+B for Polynomials（25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1002/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1002/Main.java)

### 解题思路

对于 C++ 版本的算法，此题并未特别说明指数为整数，但测试用例均通过。

## 1003 Emergency（25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1003/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1003/Main.java)

### 解题思路

~~先通过 dijkstra 算法求出最短的路径长度，之后从终点回溯 dfs，记录满足：dis[u] + cost(u, v) = dis[v] 的点，生成路径。递归出口：u 是起点。~~

先用 dijkstra 算法求出最短路，使用 **```vector<int> path[MAX_N]```** 保存结点所有可能最短路径上的前驱结点。之后从终点backtrack回溯路径，并累加保存一路上的team数。当达到起点时，更新路径数和最大team数。

## 1004 Counting Leaves（30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1004/main.cpp)

[Java (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1004/Main.java)

### 解题思路

C++: 使用 **```vector<int> tree[MAX_N]```** 的形式保存各个 ID 结点拥有的子结点 ID。使用 DFS 递归传递层数，统计各层叶节点数。

Java: 此题较难构建左右子树的指针结构。利用数组保存标号对应结点的子节点。如：对于 id 号结点，其子节点为 nodes[id].childs 的 arraylist。构建完毕后简单地 dfs 或 bfs 搜索并记录即可。

## 1005 Spell It Right（20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1005/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1005/Main.java)

### 解题思路

此题中 N 可以取到 10^100，使用 unsigned long long 也会溢出，因此应当作字符串处理该数。

## 1006 Sign In and Sign Out（25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1006/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1006/Main.java)

## 1007 Maximum Subsequence Sum（25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1007/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1007/Main.java)

### 解题思路

动态规划，向前先后均可，注意记录子串开始和结束位置的方法。对于向后递推，设置一个 from 数组记录以 i 结尾的最大和子串的 i 的前一个数。

## 1008 Elevator（20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1008/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1008/Main.java)

## 1009 Product of Polynomials（25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805509540921344)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1009/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1009/Main.java)

## 1010 Radix （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1010/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1010/Main.java)

### 解题思路

进制转换。此题要注意的细节非常多。

* 最小进制：在要转化的数出现的数中最大数 + 1。最大进制： k + 1，k 为目标数。

* 从 min_radix 到 max_radix 遍历会超时，要使用[二分查找](https://github.com/Heliovic/AlgorithmSet/blob/master/BinarySearch/main.cpp)。

* 要使用 unsigned long long，注意输出时的格式说明符： *"%llu"*。

~~【测试点 19】仍然过不了， 求大神指教。~~
原来是因为最小进制大于小于号写反了🤣

## 1011 World Cup Betting （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805504927186944)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1011/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1011/Main.java)

## 1012 The Best Rank （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805502658068480)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1012/main.cpp)

[Java (19/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1012/Main.java)

### 解题思路

排序。java 测试点3、测试点4 运行超时，尝试改用 C++ 重写。

20181011: C++ done

## 1013 Battle Over Cities （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1013/main.cpp)

[Java (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1013/Main.java)

### 解题思路
去掉指定的 city 后，多次在主程序中 DFS，使得 visit 均为 1。主程序中 DFS 的次数即为图的连通分量数。若连通分量数为 n，则需要再加 n-1 条边使得所有连通分量连通。

## 1014 Waiting in Line （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1014/main.cpp)

[Java (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1014/Main.java)

### 解题思路

复杂模拟。置当前时间为8:00。开始时先将服务窗口填满（K > M * N）或将所有人置入服务窗口内（K <= M * N）。置每个窗口的每个客户初始剩余服务时间为每个客户的总服务时间。之后只要窗口内还有未服务的客户，就从每个窗口的队首中选择一个具有最短剩余服务时间的客户，将他从窗口队首移除，并更新当前时间和其他用户的剩余服务时间 **（当前时间加上该最短剩余服务时间，其他用户的剩余服务时间减去最短剩余服务时间）**，并记录被移除的用户服务完成时间为当前时间。再从线外等待客户中按序取出客户，放入前一个被移除的客户的窗口中排队等待。

## 1015 Reversible Primes （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805495863296000)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1015/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1015/Main.java)

### 解题思路

Reversible primes 定义：在十进制下是质数，转为相应进制反转后再转回十进制后还是质数。

使用 C++ 时注意 [memcpy](https://github.com/Heliovic/PAT_Solutions/blob/master/1015/main.cpp#L32) 的使用。

使用 Java 时要善于使用 Integer 和 String 的进制转换函数。

## 1016 Phone Bills （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1016/main.cpp)

[Java (15/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1016/Main.java)

## 1017 Queueing at Bank （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805491530579968)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1017/main.cpp)

[Java (23/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1017/Main.java)

### 解题思路

简单模拟。用 Java 最后一个测试点会超时。

## 1018 Public Bike Management （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805489282433024)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1018/main.cpp)

### 解题思路

先使用 Dijkstra 算法求出所有最短路。之后简单模拟按照路径行进，计算出需要带的自行车。

注意，只允许由前向后单向带车，路径中后继结点的车不可带到前驱结点！

## 1019 General Palindromic Number （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805487143337984)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1019/main.cpp)

## 1020 Tree Traversals （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805485033603072)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1020/main.cpp)

### 解题思路

由中根遍历和后根遍历递归构建二叉树。

后根遍历序列的最后一个结点是该序列对应下的根结点。而利用此根结点，可在中根遍历序列中划分左右子树。

由划分后的左右子树得到下一递归时的数组索引，递归构造左右子树。

## 1021 Deepest Root （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805482919673856)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1021/main.cpp)

### 解题思路

DFS。**非递归的 DFS 次数为连通分量数。**

## 1022 Digital Library （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1022/main.cpp)

### 解题思路

字符串处理。注意 `cin.ignore();` 和 `setfill(char)`、 `setw(int)` 的使用。

## 1023 Have Fun with Numbers （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1023/main.cpp)

## 1024 Palindromic Number （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805476473028608)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1024/main.cpp)

## 1025 PAT Ranking （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805474338127872)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1025/main.cpp)

## 1026 Table Tennis （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805472333250560)

[C++ (12/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1026/main.cpp)

## 1027 Colors in Mars （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1027/main.cpp)

[Java (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1027/Main.java)

## 1028 List Sorting （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805468327690240)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1028/main.cpp)

## 1029 Median （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805466364755968)

[C++ (22/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1030/main.cpp)

### 解题思路

Two Pointers。最后一个测试点内存超限。

## 1030 Travel Plan （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1030/main.cpp)

### 解题思路

使用 Dijkstra 算法，注意在 dis 相等时，比较路径的 cost，取 cost 小的那条路径。

## 1031 Hello World for U （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805462535356416)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1031/main.cpp)

### 解题思路

应满足的条件：

* U 越接近 “square” 形状越好 -> n1 与 n2 之差的绝对值越小越好
* n2 ≤ n1 = n3

## 1032 Sharing （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805460652113920)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1032/main.cpp)

### 解题思路

链表操作。使用[地址标志](https://github.com/Heliovic/PAT_Solutions/blob/master/1032/main.cpp#L37)记录是否出现过该地址，一旦两者都第一次出现过，说明这是公共后缀的起点。

## 1033 To Fill or Not to Fill （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805458722734080)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1033/main.cpp)

### 解题思路

贪心 + 模拟：

* 对每个 station 按 dis 排序。若排序后 sts[0] 的 dis 不为 0（即在 0 处没有加油站），则直接输出返回。否则：
0. 走到某一个加油站，并遍历其后**能满油箱达到的加油站**：
1. 若当前加油站之后不再有加油站的 price 比当前低，且终点就在能达到距离范围内，则加油到刚好可以到达终点，输出总价格，返回。否则：
2. 若能找到一个加油站，这个加油站的 price 比当前低，则在当前加油站加到刚好能到达这个加油站的油，更新当前加油站为这个加油站，转到0。否则：
3. 若找不到加油站的 price 比当前低，但能找到**能达到的加油站**中 price 最小的加油站，在当前加油站加满油后，更新当前加油站为这个加油站，转到0。否则：
4. 若找不到**能达到的加油站**中 price 最小的加油站，说明在车能达到的范围内已无加油站，输出最大能达到的距离，返回。

## 1034 Head of a Gang （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1034/main.cpp)

### 解题思路

图论的题目中节点 id 为**字符或字符串**时用 [正反map](https://github.com/Heliovic/PAT_Solutions/blob/master/1034/main.cpp#L73) 处理。

通过 DFS 求出各个连通分量及其对应的信息。只需求边权时，将有向图转化为无向图简化（边权为两个有向边（若有）权重之和）。

当 DFS 求连通分量可能出现环时，使用 [visit_edge](https://github.com/Heliovic/PAT_Solutions/blob/master/1034/main.cpp#L48) 保证能够遍历到各个边。

使用 map 保存答案， 并保证答案按[字典序](https://github.com/Heliovic/PAT_Solutions/blob/master/1034/main.cpp#L106)输出。

## 1035 Password （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1035/main.cpp)

## 1036 Boys vs Girls （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805453203030016)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1036/main.cpp)

## 1037 Magic Coupon （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1037/main.cpp)

### 解题思路

贪心。总是选绝对值大的相乘。证明过段时间给出。

## 1038 Recover the Smallest Number （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805449625288704)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1038/main.cpp)

### 解题思路

贪心。将每个子字符串按照以下方法排序：

对于子串集合中的任意两个元素Sa, Sb，若组合形成的数字 ```SaSb < SbSa```，则将 Sa 放在 Sb 的前面。反之，将 Sb 放在 Sa 的前面。

之后将排好序的所有子串拼接，并去掉前导0即为所求答案。

## 1039 Course List for Student （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805447855292416)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1039/main.cpp)

### 解题思路

STL 的 vector、map 的使用。

注意通过 ```ios::sync_with_stdio(false)``` 来提速 cin。**但这样 cin、cout 便不能再与 scanf、printf 混用。**

## 1040 Longest Symmetric String （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1040/main.cpp)

### 解题思路

动态规划，求最长回文子串。

状态转移方程：
```cpp
if (dp[s + 1][t - 1] && str[s] == str[t])
    dp[s][t] = true;
else
    dp[s][t] = false;
```

## 1041 Be Unique （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1041/main.cpp)

## 1042 Shuffling Machine （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1042/main.cpp)

### 解题思路

简单模拟。使用 stringstream 将 int 转为 string。

## 1043 Is It a Binary Search Tree （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805440976633856)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1043/main.cpp)

### 解题思路

二叉查找树（BST）的创建、插入、遍历。

## 1044 Shopping in Mars （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1044/main.cpp)

### 解题思路

二分查找。使用 ```chain_sum[i]``` 保存从第一个元素累加到第 i 个元素的值。```chain_sum[j] - chain_sum[i - 1]``` 即表示从第 i 个元素累加到第 j 个元素的值。这节省了重复累加的时间。

## 1045 Favorite Color Stripe （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1045/main.cpp)

### 解题思路

动态规划，求最长非降子序列。

状态转移方程：```dp[i] = max(dp[i], dp[j] + 1), j = 0, 1,... ,i - 1 且 a[i] >= a[j]```。

## 1046 Shortest Distance （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1046/main.cpp)

### 解题思路

若直接遍历，最后一个测试点很容易就超时了。

使用 dis 数组记录从 1 到 i + 1 的路径长度。则 s 到 t 的顺时针长度为 `dis[t - 1] - dis[s - 1], s < t`。其反方向长度为 `total_dis - dis1`，取两个方向的长度较小值即为答案。

## 1047 Student List for Course （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1047/main.cpp)

### 解题思路

STL 的 vector 使用。

本题若使用 cin、cout 和 ```ios::sync_with_stdio(false)``` 仍然超时。大量数据还是使用 printf、scanf。输入的 char[] 可以直接赋值给 string。string 可以通过 string.c_str() 转换为 char[]。

注意，string.c_str() 返回 const char*。需要使用 const char* 接收，也可以使用 strcpy 拷贝到字符数组。

```cpp
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	string s = "123";
	const char* ccp = s.c_str();
	char cp[16];	// 不可使用 char* cp
	strcpy(cp, s.c_str());
	printf("%s\n", s.c_str());
	printf("%s\n", ccp);
	printf("%s\n", cp);
	return 0;
}
```

## 1048 Find Coins （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1048/main.cpp)

### 解题思路

暴力求解会超时。

先对拥有的硬币进行排序，外循环从左向右，内循环从右向左检查。

使用散列记录某个面值是否被检查过，若是，则无需再次检查。

若不使用散列，也会超时。

## 1049 Counting Ones （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1049/main.cpp)

### 解题思路

从个位开始，逐位分析从 1 到 N 所有数该位贡献出来的 1 的个数。

对于 N = 123456，以分析百位的 4 为例。其前面有 123 个 0~999（从 0 数到 999） 形成了 12300（这里直接忽略了 0）。这些数中，百位上总共贡献的 1 有 **123（123 次） * 100（从 0 数到 999 的数中，百位为 1 的共有 100 个，即 100, 101, ... 199）** 个，此外，在剩下的 456 个数中，也有这样的 100, 101, ... 199 贡献了 100 个 1 。特别地，若此处 4 是 0，则没有这 100 个 1 了（000, 001, ..., 0xx）；若此处 4 是 1，则要从 100 数到 1xx 看看有多少个数，事实上，共有 （1xx - (100 - 1)）个。

其他位的分析同理，最终对每位的分析结果求和即为答案。

## 1050 String Subtraction （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1050/main.cpp)

### 解题思路

散列表

## 1051 Pop Sequence （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1051/main.cpp)

### 解题思路

STL 中 stack 的使用。模拟堆栈入栈出栈过程。

## 1052 Linked List Sorting （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805425780670464)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1052/main.cpp)

### 解题思路

链表操作，简单问题简单做。

## 1053 Path of Equal Weight （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805424153280512)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1053/main.cpp)

### 解题思路

树的遍历，DFS。

## 1054 The Dominant Color （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1054/main.cpp)

### 解题思路

STL 中 map 的使用。

## 1055 The World's Richest （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1055/main.cpp)

## 1056 Mice and Rice （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1056/main.cpp)

### 解题思路

STL 中 queue 的使用。

## 1057 Stack （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1057/main.cpp)

### 解题思路

二分法，使用 vector 构建二分查找树。

## 1058 A+B in Hogwarts （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1058/main.cpp)

### 解题思路

任意进制转换

## 1059 Prime Factors （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1059/main.cpp)

### 解题思路

[质因子分解](https://github.com/Heliovic/AlgorithmSet/blob/master/PrimeFactors/main.cpp)，注意该算法输入出现质数的情况 https://github.com/Heliovic/AlgorithmSet/blob/master/PrimeFactors/main.cpp#L48 。

## 1060 Are They Equal （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805413520719872)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1060/main.cpp)

### 解题思路

字符串处理。

## 1061 Dating （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1061/main.cpp)

## 1062 Talent and Virtue （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1062/main.cpp)

### 解题思路

将各类人抽象成一个可以比较的数 `type` 方便排序。

## 1063 Set Similarity （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1063/main.cpp)

### 解题思路

使用 STL 中的 set 去除重复，使用其成员函数进行查找是否有某个元素存在。

不需要生成新 set 计算总数目 https://github.com/Heliovic/PAT_Solutions/blob/master/1063/main.cpp#L46

在 printf 中使用 "%%" 输出 '%' 的符号 https://github.com/Heliovic/PAT_Solutions/blob/master/1063/main.cpp#L51

## 1064 Complete Binary Search Tree （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1064/main.cpp)

### 解题思路

根据中根遍历序列填入二叉查找树。

## 1065 A+B and C (64bit) （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805406352654336)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1065/main.cpp)

### 解题思路

* **方法一**
	* 若 a > 0 且 b > 0，但 a + b < 0，则说明 a + b >= 2^63。
	* 若 a < 0 且 b < 0，但 a + b >= 0，则说明 a + b < -2^63。
	* 注意，这是不严谨的，因为题目中说明，a, b, c 的范围可以达到 `LONG_LONG_MAX + 1`，但测试用例可以通过。
* **方法二**
	* 大数加减法

## 1066 Root of AVL Tree （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1066/main.cpp)

### 解题思路

[AVL树](https://github.com/Heliovic/AlgorithmSet/blob/master/AVLTree/main.cpp)

## 1067 Sort with Swap(0, i) （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1067/main.cpp)

### 解题思路

~~测试点1、测试点2运行超时~~

使用 [记忆化搜索](https://github.com/Heliovic/PAT_Solutions/blob/master/1067/main.cpp#L16) 保存上次搜到的最小不在其位置上的数，下次搜索时从该处而不是起始处开始查找。

## 1068 Find More Coins （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1068/main.cpp)

[C++ (30/30) 一维 dp 数组](https://github.com/Heliovic/PAT_Solutions/blob/master/1068/main-1dim.cpp)

### 解题思路

0-1背包。

## 1069 The Black Hole of Numbers （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1069/main.cpp)

## 1070 Mooncake （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1070/main.cpp)

### 解题思路

贪心算法。

## 1071 Speech Patterns （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1071/main.cpp)

### 解题思路

STL 中 map、string 的使用。

> 注意 ```tolower()、isalpha()、isdigit()``` 函数都来自头文件 ```cctype```。

## 1072 Gas Station （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1072/main.cpp)

### 解题思路

Dijkstra。

## 1073 Scientific Notation （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1073/main.cpp)

### 解题思路

分类讨论，模拟移位。

## 1074 Reversing Linked List （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805394512134144)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1074/main.cpp)

### 解题思路

链表操作。

## 1075 PAT Judge （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1075/main.cpp)

### 解题思路

数组排序。记得在结构体内部记录 id。

**以用户 id 为数组索引节省运行时间。**

## 1076 Forwards on Weibo （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1076/main.cpp)

### 解题思路

BFS，不可用 DFS。

在将 u 入队时即标记 u 被访问可以节省很多运行时间。若[此处代码](https://github.com/Heliovic/PAT_Solutions/blob/master/1076/main.cpp#L21)按以下方式编写，最后一个测试点超时。

```cpp
while (!q.empty())
{
    pair<int, int> p = q.front();
    q.pop();
    int v = p.first;
    int level = p.second;
    if (level >= L + 1)
        return;
    if (!visit[v])
    {
        if (level >= 1 && level <= L)
            forward_cnt++;
        visit[v] = true;
        for (int i = 1; i <= N; i++)
        {
            if (!visit[i] && graph[v][i])
                q.push(pair<int, int>(i, level + 1));
        }
    }
}
```

## 1077 Kuchiguse （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1077/main.cpp)

### 解题思路

使用 `gets()` 编译失败。

## 1078 Hashing （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1078/main.cpp)

### 解题思路

质数判断，平方探查。p = hash(i) + d * d。其中 d = 1, 2, ..., M - 1。M 是哈希表容量。

## 1079 Total Sales of Supply Chain （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805388447170560)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1079/main.cpp)

### 解题思路

树的遍历，DFS。

## 1080 Graduate Admission （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1080/main.cpp)

### 解题思路

排序、模拟。

## 1081 Rational Sum （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1081/main.cpp)

### 解题思路

分数四则运算。

## 1082 Read Number in Chinese （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805385053978624)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1082/main.cpp)

### 解题思路

1. 将数字去掉符号后转为 9 位的格式，不足前面填0

2. 从第一个非 0 位开始，每输出一位数，随即输出对应单位，个位用单位 `""` 处理，注意判断最后一位的个位，不要多输出空格

3. 输出某一位 `i` 后，检查下一个不是 0 的位 `n` 是否等于 `i + 1` ，若是，继续输出，若不是，多输出一个 `"ling"`。注意 0 一直连续到最后一位的情况

4. 对于千万位的处理，若 `i = 4` ，直接输出 `"Wan"` ，否则，若有 `n` 跨越 4，且不是从 0 开始跨越，也输出 `"Wan"`

## 1083 List Grades （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805383929905152)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1083/main.cpp)

## 1084 Broken Keyboard （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1084/main.cpp)

### 解题思路

打表（散列）

## 1085 Perfect Sequence （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1085/main.cpp)

### 解题思路

二分查找。先对原数列非降序排序。外层循环遍历所有从第 i 个元素开始的子串，内层循环使用二分查找找到满足 M(mid) ≤ m(i) × p 的最大 mid，mid 在 [i, N - 1]范围内。[二分指针调整逻辑](https://github.com/Heliovic/PAT_Solutions/blob/master/1085/main.cpp#L30)

> 也可以使用 **Two Pointers** 方法。

## 1086 Tree Traversals Again （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1086/main.cpp)

### 解题思路

根据堆栈进出序列递归构建二叉树。

## 1087 All Roads Lead to Rome （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805379664297984)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1087/main.cpp)

### 解题思路

Dijkstra + DFS 回溯所有最小等距路径。

## 1088 Rational Arithmetic （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1088/main.cpp)

### 解题思路

分数的化简、四则运算。

## 1089 Insert or Merge （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805377432928256)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1089/main.cpp)

### 解题思路

模拟每次排序迭代时数组的情况。

归并排序通过[自底向上](https://github.com/Heliovic/PAT_Solutions/blob/master/1089/main.cpp#L36)按照步长迭代，而非递归实现。

[Trick](https://github.com/Heliovic/PAT_Solutions/blob/master/1089/main.cpp#L38): 借助STL，在归并排序中并不需要手动实现具体的排序过程。

## 1090 Highest Price in Supply Chain （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805376476626944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1090/main.cpp)

### 解题思路

树的遍历，DFS。

## 1091 Acute Stroke （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1091/main.cpp)

### 解题思路

BFS。数据量过大使用 DFS 可能会爆栈。

## 1092 To Buy or Not to Buy （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1092/main.cpp)

## 1093 Count PAT's （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1093/main.cpp)

### 解题思路

确定出所有的 'A' 所在位置中，左侧的 'P' 数目 pcnt 和右侧的 'T' 数目 tcnt 。以该 'A' 为中心形成的 "PAT" 数目即为 pcnt * tcnt。总的 "PAT" 数目为所有的 'A' 形成的 "PAT" 数目之和。

## 1094 The Largest Generation （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805372601090048)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1094/main.cpp)

### 解题思路

树的遍历，DFS。

## 1095 Cars on Campus （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1095/main.cpp)

### 解题思路

对于无序记录，先按照ID排序，筛选出有效记录。之后对筛选出的有效记录按照时间排序，根据记录进出情况调整当前车辆数目。

## 1096 Consecutive Factors （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1096/main.cpp)

### 解题思路

若 N 是质数，则显然只有 N 本身。

否则，对每个 i <= sqrt (N)，检查从 i 开始的连续的数之积是否能整除 N。记录下最长的连续数起止位置并取最长。

## 1097 Deduplication on a Linked List （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805369774129152)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1097/main.cpp)

### 解题思路

链表去重，散列打表。

## 1098 Insertion or Heap Sort （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805368847187968)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1098/main.cpp)

### 解题思路

堆排序过程。

## 1099 Build A Binary Search Tree （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805367987355648)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1099/main.cpp)

### 解题思路

根据树形和中根遍历序列确定每个节点上的 key。

## 1100 Mars Numbers （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805367156883456)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1100/main.cpp)

### 解题思路

STL 的 map 和 string 的使用。

## 1101 Quick Sort （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805366343188480)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1101/main.cpp)

### 解题思路

使用两个数组 ```int left_max[MAX_N]; int right_min[MAX_N];``` 分别记录第 i 个元素左边最大的数和右边最小的数。若满足 ```left_max[i] <= numbers[i] && right_min[i] >= numbers[i]```，则第 i 个数属于 *pivot candidates*

此题若不加入最后一行以打印换行，【测试点 2】会格式错误。

## 1102 Invert a Binary Tree （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805365537882112)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1102/main.cpp)

### 解题思路

二叉树的遍历。

对于只要求输出反转后的二叉树遍历序列，只需对原树在正常的遍历下，调换遍历左右子树的顺序，不必真正进行树结构修改。

注意 ```scanf("%c %c")``` 读入字符时，最后的换行 ```\n``` 不会被读取，需要用 getchar() 读入消除。 https://github.com/Heliovic/PAT_Solutions/blob/master/1102/main.cpp#L77 

## 1103 Integer Factorization （30 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805364711604224)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1103/main.cpp)

### 解题思路

DFS，回溯。注意，由于加法的可交换性，设本次 DFS 选择的 factor 为 f，则下一次 DFS 的 factor 上界就是 f，即，相邻轮的 factor 上界是[单调不增](https://github.com/Heliovic/PAT_Solutions/blob/master/1103/main.cpp#L40)的。

## 1104 Sum of Number Segments （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805363914686464)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1104/main.cpp)

### 解题思路

推导出 numbers[s] 在 sum 中出现的次数（s 从 0 开始）。

numbers[s] 前面有 s 个数字，对于这 s 个数字中的特定一个 numbers[k]，以 numbers[k] 为首形成的片段会累加 numbers[s] **N - s** （程序中为 t ）次，这是因为，numbers[s]及其之后有 N - s 个数，numbers[k] 为首形成的片段会使这 N - s 个数各作为结尾 1 次。其次，以numbers[s] 为首的片段也会累加 numbers[s] **N - s**。所以最后 numbers[s] 共被累加了 *s * t + t = (s + 1) * t* 次。

## 1105 Spiral Matrix （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805363117768704)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1105/main.cpp)

### 解题思路

模拟。

## 1106 Lowest Price in Supply Chain （25 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805362341822464)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1106/main.cpp)

### 解题思路

树的遍历，DFS。

## 1107 Social Clusters （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805361586847744)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1107/main.cpp)

### 解题思路

并查集，注意，若要保存集合内元素个数，[此处](https://github.com/Heliovic/PAT_Solutions/blob/master/1107/main.cpp#L20)必须这么写，否则会出错。

## 1108 Finding Average （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805360777347072)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1108/main.cpp)

### 解题思路

字符串处理，注意利用 `scanf` 的返回值进行匹配。

## 1109 Group Photo （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805360043343872)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1109/main.cpp)

### 解题思路

排序，模拟。

## 1110 Complete Binary Tree （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805359372255232)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1110/main.cpp)

### 解题思路

打表判断是否是完全二叉树。

## 1111 Online Map （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805358663417856)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1111/main.cpp)

### 解题思路

dijkstra + DFS。

## 1112 Stucked Keyboard （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805357933608960)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1112/main.cpp)

### 解题思路

打表，[注意审题](https://github.com/Heliovic/PAT_Solutions/blob/master/1112/main.cpp#L33)，必须出现 k 的倍数次才算是 stucked。

## 1113 Integer Set Partition （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805357258326016)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1113/main.cpp)

## 1114 Family Property （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805356599820288)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1114/main.cpp)

### 解题思路

DFS。

## 1115 Counting Nodes in a BST （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805355987451904)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1115/main.cpp)

### 解题思路

BST 的构建，DFS。

## 1116 Come on! Let's C （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805355358306304)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1116/main.cpp)

## 1117 Eddington Number （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805354762715136)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1117/main.cpp)

## 1118 Birds in Forest （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805354108403712)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1118/main.cpp)

### 解题思路

并查集。

## 1119 Pre- and Post-order Traversals （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1119/main.cpp)

### 解题思路

根据先根遍历序列和后根遍历序列重建二叉树。注意，两个遍历序列首尾必定是一样的。

先通过先根遍历序列确定根节点。则先根遍历序列左数第二个元素是子树的根（左右无法确定）。之后到后根遍历序列中找这个子树的根。在后根遍历序列中，这个被找到的子树的根及其之前的都是新左子树的节点，子树的根之后的都是新右子树的节点。若这个根无法将剩余的序列划分成两个，说明左右子树无法确定。

注意：此题若不在答案末尾加`'\n'`[换行](https://github.com/Heliovic/PAT_Solutions/blob/master/1119/main.cpp#L82)，则格式错误。

## 1120 Friend Numbers （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805352925609984)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1120/main.cpp)

## 1121 Damn Single （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805352359378944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1121/main.cpp)

### 解题思路

打表。

## 1122 Hamiltonian Cycle （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1122/main.cpp)

### 解题思路

哈密顿环的判断。

## 1123 Is It a Complete AVL Tree （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805351302414336)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1123/main.cpp)

### 解题思路

AVL 树 + BFS 判断是否是完全二叉树。

## 1124 Raffle for Weibo Followers （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805350803292160)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1124/main.cpp)

## 1125 Chain the Ropes （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805350316752896)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1125/main.cpp)

### 解题思路

贪心，越到后面加入到绳子中减半次数越少。

## 1126 Eulerian Path （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805349851185152)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1126/main.cpp)

### 解题思路

注意使用 DFS 先判断是否是连通图。

## 1127 ZigZagging on a Tree （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805349394006016)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1127/main.cpp)

### 解题思路

二叉树重建，BFS。

## 1128 N Queens Puzzle （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805348915855360)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1128/main.cpp)

### 解题思路

N-Queens 可行解判断。

## 1129 Recommendation System （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805348471259136)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1129/main.cpp)

### 解题思路

map + set。注意利用 set 内部的有序性。需要重载 < 运算符：

```cpp
bool operator < (const item& rhs) const
{
    if (freq != rhs.freq)
        return freq > rhs.freq;
    return id < rhs.id;
}
```

## 1130 Infix Expression （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805347921805312)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1130/main.cpp)

### 解题思路

树的遍历，中缀表达式的生成。若子节点为运算符，则在中根遍历子节点前与中根遍历子节点后要分别加上 '(' 和 ')'。

判断是否是运算符：

```cpp
if (tree[lc].data.size() == 1 && !isalnum(tree[lc].data[0]))
    //...
```

## 1131 Subway Map （30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1131/main.cpp)

### 解题思路

堆优化的 dijkstra。

使用 [hash + map](https://github.com/Heliovic/PAT_Solutions/blob/master/1131/main.cpp#L15) 存储某条边所属线路。

这种题编码时一定要高度集中注意力，稍有不慎就是一个 bug。

## 1132 Cut Integer （20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805347145859072)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1132/main.cpp)

### 解题思路

字符串处理。

## 1133 Splitting A Linked List （25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805346776760320)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1133/main.cpp)

### 解题思路

链表操作，简单问题简单做，不必真的改变指针进行排序。

注意，这种题里的 N 是不可靠的，因为可能有节点不属于链表内。

## 1134 Vertex Cover (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805346428633088)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1134/main.cpp)

### 解题思路

STL map、set、vector、pair。

## 1135 Is It A Red-Black Tree (30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805346063728640)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1135/main.cpp)

### 解题思路

二叉查找树的建立。

红黑树的第五条判断基于这样一个事实：对树上每个节点出发的两条简单路 BLACK 节点数相等，则从其兄弟节点出发的简单路径上的 BLACK 节点数也必与从该节点出发的简单路上 BLACK 节点数相等。

## 1136 A Delayed Palindrome (20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805345732378624)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1136/main.cpp)

### 解题思路

大数加法。

## 1137 Final Grading (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805345401028608)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1137/main.cpp)

### 解题思路

结构体排序，STL map 的使用。

## 1138 Postorder Traversal (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805345078067200)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1138/main.cpp)

### 解题思路

重建二叉树。

## 1139 First Contact (30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805344776077312)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1139/main.cpp)

### 解题思路

BFS。注意 +0000 和 -0000。

## 1140 Look-and-say Sequence (20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805344490864640)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1140/main.cpp)

### 解题思路

模拟。

## 1141 PAT Ranking of Institutions (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805344222429184)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1141/main.cpp)

### 解题思路

结构体排序。

将 string 转为小写/大写：

```cpp
#include <algorithm>
#include <string>

string s1, s2;

transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
```

## 1142 Maximal Clique (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805343979159552)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1142/main.cpp)

### 解题思路

根据定义判断即可。

## 1143 Lowest Common Ancestor (30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805343727501312)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1143/main.cpp)

### 解题思路

原以为需要建立二叉树，遍历求解，后来发现由于这是一颗二叉查找树，对于 s 和 t，易证得若在某个节点 r 上有 min(s, t) < r->key && max(s, t) > r->key，则说明 r 就是 s 和 t 的 LCA；若 s == r->key，则说明 s 是 t 的祖先；对 t 而言同理。

后来发现这么做还超时。其实不必建立二叉树，因为原输入序列便是二叉查找树的遍历序列。

## 1144 Lowest Common Ancestor (20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1144/main.cpp)

### 解题思路

STL set 的使用。

## 1145 Hashing - Average Search Time (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805343236767744)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1145/main.cpp)

### 解题思路

二次探查法。注意，在搜索时，若 table[k] == -1，则应直接停止继续探查。

## 1146 Topological Order (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805343043829760)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1146/main.cpp)

### 解题思路

根据入度判断是否是拓扑序列。

## 1147 Heaps (30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1147/main.cpp)

### 解题思路

堆的性质、判断。

## 1148 Werewolf - Simple Version (20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1148/main.cpp)

### 解题思路

假设某两个是 Werewolf，判断是否满足条件即可。

## 1149 Dangerous Goods Packaging (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1038429908921778176)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1149/main.cpp)

### 解题思路

STL set 的使用，若用 map 索引会超时。

## 1150 Travelling Salesman Problem (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1038430013544464384)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1150/main.cpp)

### 解题思路

根据条件判断即可。

## 1151 LCA in a Binary Tree (30 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1038430130011897856)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1151/main.cpp)

### 解题思路

LCA 算法。

## 1152 Google Recruitment (20 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1152/main.cpp)

### 解题思路

质数判断 + 大数处理。

## 1153 Decode Registration Card of PAT (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1071785190929788928)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1153/main.cpp)

### 解题思路

使用 unordered_map，无序，但效率高于 map。使用 map 会超时。

## 1154 Vertex Coloring (25 分)

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/1071785301894295552)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1154/main.cpp)

### 解题思路

使用 **unordered_map**，无序，但效率高于 map。使用 map 会超时。
