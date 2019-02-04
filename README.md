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

## 1041 Be Unique （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805444361437184)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1041/main.cpp)

## 1042 Shuffling Machine （20 分）

[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805442671132672)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1042/main.cpp)

### 解题思路

简单模拟。使用 stringstream 将 int 转为 string。

## 1046 Shortest Distance （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1046/main.cpp)

### 解题思路

若直接遍历，最后一个测试点很容易就超时了。

使用 dis 数组记录从 1 到 i + 1 的路径长度。则 s 到 t 的顺时针长度为 `dis[t - 1] - dis[s - 1], s < t`。其反方向长度为 `total_dis - dis1`，取两个方向的长度较小值即为答案。

## 1048 Find Coins （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805432256675840)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1048/main.cpp)

### 解题思路

暴力求解会超时。

先对拥有的硬币进行排序，外循环从左向右，内循环从右向左检查。

使用散列记录某个面值是否被检查过，若是，则无需再次检查。

若不使用散列，也会超时。

## 1050 String Subtraction （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805429018673152)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1050/main.cpp)

### 解题思路
散列表

## 1055 The World's Richest （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1055/main.cpp)

## 1058 A+B in Hogwarts （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1058/main.cpp)

### 解题思路
任意进制转换

## 1061 Dating （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1061/main.cpp)

## 1062 Talent and Virtue （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1062/main.cpp)

### 解题思路

将各类人抽象成一个可以比较的数 `type` 方便排序。

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
	
## 1067 Sort with Swap(0, i) （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1067/main.cpp)

### 解题思路

~~测试点1、测试点2运行超时~~

使用 [记忆化搜索](https://github.com/Heliovic/PAT_Solutions/blob/master/1067/main.cpp#L16) 保存上次搜到的最小不在其位置上的数，下次搜索时从该处而不是起始处开始查找。
	
## 1070 Mooncake （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1070/main.cpp)

### 解题思路

贪心算法。

## 1073 Scientific Notation （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1073/main.cpp)

### 解题思路

分类讨论，模拟移位。

## 1075 PAT Judge （25 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032)

[C++ (25/25)](https://github.com/Heliovic/PAT_Solutions/blob/master/1075/main.cpp)

### 解题思路

数组排序。记得在结构体内部记录 id。

**以用户 id 为数组索引节省运行时间。**

## 1077 Kuchiguse （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1077/main.cpp)

### 解题思路

使用 `gets()` 编译失败。

## 1080 Graduate Admission （30 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1080/main.cpp)

### 解题思路

排序、模拟。

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

## 1092 To Buy or Not to Buy （20 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805374509498368)

[C++ (20/20)](https://github.com/Heliovic/PAT_Solutions/blob/master/1092/main.cpp)

## 1095 Cars on Campus （30 分）
[Problem description](https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696)

[C++ (30/30)](https://github.com/Heliovic/PAT_Solutions/blob/master/1095/main.cpp)

### 解题思路

对于无序记录，先按照ID排序，筛选出有效记录。之后对筛选出的有效记录按照时间排序，根据记录进出情况调整当前车辆数目。
