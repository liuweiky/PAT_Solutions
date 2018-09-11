# 1001 A+B Format（20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1001/Main.java)

Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

## Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where -10^6≤a,b≤10^6. The numbers are separated by a space.

## Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

## Sample Input:
```
-1000000 9
```
## Sample Output:
```
-999,991
```

# 1002 A+B for Polynomials（25 分）
[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1002/Main.java)

This time, you are supposed to find A+B where A and B are two polynomials.

## Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N1 a1 N2 a2 ... Nk ak

where K is the number of nonzero terms in the polynomial, Ni and ai(i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤Nk<⋯<N2<N1≤1000.

## Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

## Sample Input:
```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```
## Sample Output:
```
3 2 1.5 1 2.9 0 3.2
```

# 1003 Emergency（25 分）
[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1003/Main.java)

As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

## Input Specification:
Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (≤500) - the number of cities (and the cities are numbered from 0 to N−1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

## Output Specification:
For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather. All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

## Sample Input:
```
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
```
## Sample Output:
```
2 4
```

# 1004 Counting Leaves（30 分）
[Java (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1004/Main.java)

A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

## Input Specification:
Each input file contains one test case. Each case starts with a line containing 0<N<100, the number of nodes in a tree, and M (<N), the number of non-leaf nodes. Then M lines follow, each in the format:
```
ID K ID[1] ID[2] ... ID[K]
```
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

The input ends with N being 0. That case must NOT be processed.

## Output Specification:
For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output 0 1 in a line.

## Sample Input:
```
2 1
01 1 02
```
## Sample Output:
```
0 1
```

# 1005 Spell It Right（20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1005/Main.java)

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

## Input Specification:
Each input file contains one test case. Each case occupies one line which contains an N (≤10^100).

## Output Specification:
For each test case, output in one line the digits of the sum in English words. There must be one space between two consecutive words, but no extra space at the end of a line.

## Sample Input:
```
12345
```
## Sample Output:
```
one five
```

# 1006 Sign In and Sign Out（25 分）
[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1006/Main.java)

At the beginning of every day, the first person who signs in the computer room will unlock the door, and the last one who signs out will lock the door. Given the records of signing in's and out's, you are supposed to find the ones who have unlocked and locked the door on that day.

## Input Specification:
Each input file contains one test case. Each case contains the records for one day. The case starts with a positive integer M, which is the total number of records, followed by M lines, each in the format:

ID_number Sign_in_time Sign_out_time
where times are given in the format HH:MM:SS, and ID_number is a string with no more than 15 characters.

## Output Specification:
For each test case, output in one line the ID numbers of the persons who have unlocked and locked the door on that day. The two ID numbers must be separated by one space.

Note: It is guaranteed that the records are consistent. That is, the sign in time must be earlier than the sign out time for each person, and there are no two persons sign in or out at the same moment.

## Sample Input:
```
3
CS301111 15:30:28 17:00:10
SC3021234 08:00:00 11:25:25
CS301133 21:45:00 21:58:40
```
## Sample Output:
```
SC3021234 CS301133
```

# 1007 Maximum Subsequence Sum（25 分）
Given a sequence of K integers { N1, N2, ..., NK}. A continuous subsequence is defined to be { Ni, Ni+1, ..., Nj} where 1≤i≤j≤K. The Maximum Subsequence is the continuous subsequence which has the largest sum of its elements. For example, given sequence { -2, 11, -4, 13, -5, -2 }, its maximum subsequence is { 11, -4, 13 } with the largest sum being 20.

Now you are supposed to find the largest sum, together with the first and the last numbers of the maximum subsequence.

## Input Specification:
Each input file contains one test case. Each case occupies two lines. The first line contains a positive integer K (≤10000). The second line contains K numbers, separated by a space.

## Output Specification:
For each test case, output in one line the largest sum, together with the first and the last numbers of the maximum subsequence. The numbers must be separated by one space, but there must be no extra space at the end of a line. In case that the maximum subsequence is not unique, output the one with the smallest indices i and j (as shown by the sample case). If all the K numbers are negative, then its maximum sum is defined to be 0, and you are supposed to output the first and the last numbers of the whole sequence.

## Sample Input:
```
10
-10 1 2 3 4 -5 -23 3 7 -21
```
## Sample Output:
```
10 1 4
```	
