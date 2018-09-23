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
[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1007/main.cpp)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1007/Main.java)

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

# 1008 Elevator（20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1008/Main.java)

The highest building in our city has only one elevator. A request list is made up with N positive numbers. The numbers denote at which floors the elevator will stop, in specified order. It costs 6 seconds to move the elevator up one floor, and 4 seconds to move down one floor. The elevator will stay for 5 seconds at each stop.

For a given request list, you are to compute the total time spent to fulfill the requests on the list. The elevator is on the 0th floor at the beginning and does not have to return to the ground floor when the requests are fulfilled.

## Input Specification:
Each input file contains one test case. Each case contains a positive integer N, followed by N positive numbers. All the numbers in the input are less than 100.

## Output Specification:
For each test case, print the total time on a single line.

## Sample Input:
```
3 2 3 1
```
## Sample Output:
```
41
```

# 1009 Product of Polynomials（25 分）
[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1009/Main.java)

This time, you are supposed to find A×B where A and B are two polynomials.

## Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N1 aN1 N2 aN2 ... NK a​N​K

where K is the number of nonzero terms in the polynomial, N​i and a​Ni(i=1,2,...,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10, 0≤N​K<...<N2<N1≤1000.

## Output Specification:
For each test case you should output the product of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate up to 1 decimal place.

## Sample Input:
```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```
## Sample Output:
```
3 3 3.6 2 6.0 1 1.6
```

# 1010 Radix （25 分）
[C++ (24/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1010/main.cpp)

[Java (23/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1010/Main.java)

Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true? The answer is yes, if 6 is a decimal number and 110 is a binary number.

Now for any pair of positive integers N1 and N​2, your task is to find the radix of one number while that of the other is given.

## Input Specification:
Each input file contains one test case. Each case occupies a line which contains 4 positive integers:

```
N1 N2 tag radix
```

Here N1 and N2 each has no more than 10 digits. A digit is less than its radix and is chosen from the set { 0-9, a-z } where 0-9 represent the decimal numbers 0-9, and a-z represent the decimal numbers 10-35. The last number radix is the radix of N1 if tag is 1, or of N2 if tag is 2.

## Output Specification:
For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true. If the equation is impossible, print Impossible. If the solution is not unique, output the smallest possible radix.

## Sample Input 1:
```
6 110 1 10
```
## Sample Output 1:
```
2
```
## Sample Input 2:
```
1 ab 1 2
```
## Sample Output 2:
```
Impossible
```

# 1011 World Cup Betting （20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1011/Main.java)

With the 2010 FIFA World Cup running, football fans the world over were becoming increasingly excited as the best players from the best teams doing battles for the World Cup trophy in South Africa. Similarly, football betting fans were putting their money where their mouths were, by laying all manner of World Cup bets.

Chinese Football Lottery provided a "Triple Winning" game. The rule of winning was simple: first select any three of the games. Then for each selected game, bet on one of the three possible results -- namely W for win, T for tie, and L for lose. There was an odd assigned to each result. The winner's odd would be the product of the three odds times 65%.

For example, 3 games' odds are given as the following:
```
 W    T    L
1.1  2.5  1.7
1.2  3.1  1.6
4.1  1.2  1.1
```
To obtain the maximum profit, one must buy W for the 3rd game, T for the 2nd game, and T for the 1st game. If each bet takes 2 yuans, then the maximum profit would be (4.1×3.1×2.5×65%−1)×2=39.31 yuans (accurate up to 2 decimal places).

## Input Specification:
Each input file contains one test case. Each case contains the betting information of 3 games. Each game occupies a line with three distinct odds corresponding to W, T and L.

## Output Specification:
For each test case, print in one line the best bet of each game, and the maximum profit accurate up to 2 decimal places. The characters and the number must be separated by one space.

## Sample Input:
```
1.1 2.5 1.7
1.2 3.1 1.6
4.1 1.2 1.1
```
## Sample Output:
```
T T W 39.31
```

# 1012 The Best Rank （25 分）
[Java (19/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1012/Main.java)

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only: C - C Programming Language, M - Mathematics (Calculus or Linear Algrbra), and E - English. At the mean time, we encourage students by emphasizing on their best ranks -- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:
```
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
```
Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

## Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N and M (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. Then there are M lines, each containing a student ID.

## Output Specification:
For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

## Sample Input:
```
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
```
## Sample Output:
```
1 C
1 M
1 E
1 A
3 A
N/A
```

# 1013 Battle Over Cities （25 分）
[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1013/main.cpp)

[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1013/Main.java)

It is vitally important to have all the cities connected by highways in a war. If a city is occupied by the enemy, all the highways from/toward that city are closed. We must know immediately if we need to repair any other highways to keep the rest of the cities connected. Given the map of cities which have all the remaining highways marked, you are supposed to tell the number of highways need to be repaired, quickly.

For example, if we have 3 cities and 2 highways connecting city1-city2 and city1-city3. Then if city1 is occupied by the enemy, we must have 1 highway repaired, that is the highway city2-city3.

## Input Specification:
Each input file contains one test case. Each case starts with a line containing 3 numbers N (<1000), M and K, which are the total number of cities, the number of remaining highways, and the number of cities to be checked, respectively. Then M lines follow, each describes a highway by 2 integers, which are the numbers of the cities the highway connects. The cities are numbered from 1 to N. Finally there is a line containing K numbers, which represent the cities we concern.

## Output Specification:
For each of the K cities, output in a line the number of highways need to be repaired if that city is lost.

## Sample Input:
```
3 2 3
1 2
1 3
1 2 3
```
## Sample Output:
```
1
0
0
```

# 1014 Waiting in Line （30 分）
[Java (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1014/Main.java)

Suppose a bank has N windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. The rules for the customers to wait in line are:

* The space inside the yellow line in front of each window is enough to contain a line with M customers. Hence when all the N lines are full, all the customers after (and including) the (NM+1)st one will have to wait in a line behind the yellow line.
* Each customer will choose the shortest line to wait in when crossing the yellow line. If there are two or more lines with the same length, the customer will always choose the window with the smallest number.
* Customer​i will take Ti minutes to have his/her transaction processed.
* The first N customers are assumed to be served at 8:00am.

Now given the processing time of each customer, you are supposed to tell the exact time at which a customer has his/her business done.

For example, suppose that a bank has 2 windows and each window may have 2 custmers waiting inside the yellow line. There are 5 customers waiting with transactions taking 1, 2, 6, 4 and 3 minutes, respectively. At 08:00 in the morning, customer1 is served at window​1 while customer2 is served at window2. Customer3 will wait in front of window​1 and customer4 will wait in front of window2. Customer5 will wait behind the yellow line.

At 08:01, customer1 is done and customer5 enters the line in front of window1 since that line seems shorter now. Customer2 will leave at 08:02, customer​4 at 08:06, customer3 at 08:07, and finally customer​5 at 08:10.

## Input Specification:
Each input file contains one test case. Each case starts with a line containing 4 positive integers: N (≤20, number of windows), M (≤10, the maximum capacity of each line inside the yellow line), K (≤1000, number of customers), and Q (≤1000, number of customer queries).

The next line contains K positive integers, which are the processing time of the K customers.

The last line contains Q positive integers, which represent the customers who are asking about the time they can have their transactions done. The customers are numbered from 1 to K.

## Output Specification:
For each of the Q customers, print in one line the time at which his/her transaction is finished, in the format HH:MM where HH is in [08, 17] and MM is in [00, 59]. Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.

## Sample Input:
```
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7
```
## Sample Output:
```
08:07
08:06
08:10
17:00
Sorry
```

# 1015 Reversible Primes （20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1015/Main.java)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10^5) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

## Input Specification:
The input file consists of several test cases. Each case occupies a line which contains two integers N and D. The input is finished by a negative N.

## Output Specification:
For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

## Sample Input:
```
73 10
23 2
23 10
-2
```
## Sample Output:
```
Yes
Yes
No
```

# 1016 Phone Bills （25 分）
[Java (15/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1016/Main.java)

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

## Input Specification:
Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.

## Output Specification:
For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

## Sample Input:
```
10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line
```
## Sample Output:
```
CYJJ 01
01:05:59 01:07:00 61 $12.10
Total amount: $12.10
CYLL 01
01:06:01 01:08:03 122 $24.40
28:15:41 28:16:05 24 $3.85
Total amount: $28.25
aaa 01
02:00:01 04:23:59 4318 $638.80
Total amount: $638.80
```

# 1017 Queueing at Bank （25 分）
[C++ (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/main.cpp)

[Java (23/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1017/Main.java)

Suppose a bank has K windows open for service. There is a yellow line in front of the windows which devides the waiting area into two parts. All the customers have to wait in line behind the yellow line, until it is his/her turn to be served and there is a window available. It is assumed that no window can be occupied by a single customer for more than 1 hour.

Now given the arriving time T and the processing time P of each customer, you are supposed to tell the average waiting time of all the customers.

## Input Specification:
Each input file contains one test case. For each case, the first line contains 2 numbers: N (≤10^4) - the total number of customers, and K (≤100) - the number of windows. Then N lines follow, each contains 2 times: HH:MM:SS - the arriving time, and P - the processing time in minutes of a customer. Here HH is in the range [00, 23], MM and SS are both in [00, 59]. It is assumed that no two customers arrives at the same time.

Notice that the bank opens from 08:00 to 17:00. Anyone arrives early will have to wait in line till 08:00, and anyone comes too late (at or after 17:00:01) will not be served nor counted into the average.

## Output Specification:
For each test case, print in one line the average waiting time of all the customers, in minutes and accurate up to 1 decimal place.

## Sample Input:
```
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
```
## Sample Output:
```
8.2
```

# 1018 Public Bike Management （30 分）
[C++ (30/30)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1018/main.cpp)

There is a public bike service in Hangzhou City which provides great convenience to the tourists from all over the world. One may rent a bike at any station and return it to any other stations in the city.

The Public Bike Management Center (PBMC) keeps monitoring the real-time capacity of all the stations. A station is said to be in perfect condition if it is exactly half-full. If a station is full or empty, PBMC will collect or send bikes to adjust the condition of that station to perfect. And more, all the stations on the way will be adjusted as well.

When a problem station is reported, PBMC will always choose the shortest path to reach that station. If there are more than one shortest path, the one that requires the least number of bikes sent from PBMC will be chosen.

<img src="./1018/figure1.jpg"/>

The above figure illustrates an example. The stations are represented by vertices and the roads correspond to the edges. The number on an edge is the time taken to reach one end station from another. 
The number written inside a vertex S is the current number of bikes stored at S. Given that the maximum capacity of each station is 10. To solve the problem at S3, we have 2 different shortest paths:

1. PBMC -> S1-> S3. In this case, 4 bikes must be sent from PBMC, because we can collect 1 bike from S​1 and then take 5 bikes to S3, so that both stations will be in perfect conditions.

2. PBMC -> S2-> S3. This path requires the same time as path 1, but only 3 bikes sent from PBMC and hence is the one that will be chosen.

## Input Specification:
Each input file contains one test case. For each case, the first line contains 4 numbers: Cmax(≤100), always an even number, 
is the maximum capacity of each station; N (≤500), the total number of stations; 
S​p, the index of the problem station (the stations are numbered from 1 to N, and PBMC is represented by the vertex 0); 
and M, the number of roads. The second line contains N non-negative numbers Ci(i=1,...,N) where each Ci is the current number of bikes at Si respectively. 
Then M lines follow, each contains 3 numbers: Si, Sj, and Tij which describe the time T​ij taken to move betwen stations Si and S​j. All the numbers in a line are separated by a space.

## Output Specification:
For each test case, print your results in one line. First output the number of bikes that PBMC must send. 
Then after one space, output the path in the format: 0−>S1−>⋯−>Sp. 
Finally after another space, output the number of bikes that we must take back to PBMC after the condition of Sp is adjusted to perfect.

Note that if such a path is not unique, output the one that requires minimum number of bikes that we must take back to PBMC. The judge's data guarantee that such a path is unique.

## Sample Input:
```
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
```
## Sample Output:
```
3 0->2->3 0
```

# 1031 Hello World for U （20 分）
[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1031/main.cpp)

Given any string of N (≥5) characters, you are asked to form the characters into the shape of U. For example, helloworld can be printed as:
```
h  d
e  l
l  r
lowo
```
That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n​1=n3=max { k | k≤n2 for all 3≤n2≤N } with n1+n2+n3−2=N.

## Input Specification:
Each input file contains one test case. Each case contains one string with no less than 5 and no more than 80 characters in a line. The string contains no white space.

## Output Specification:
For each test case, print the input string in the shape of U as specified in the description.

## Sample Input:
```
helloworld!
```
## Sample Output:
```
h   !
e   d
l   l
lowor
```

# 1042 Shuffling Machine （20 分）
[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1042/main.cpp)

Shuffling is a procedure used to randomize a deck of playing cards. Because standard shuffling techniques are seen as weak, and in order to avoid "inside jobs" where employees collaborate with gamblers by performing inadequate shuffles, many casinos employ automatic shuffling machines. Your task is to simulate a shuffling machine.

The machine shuffles a deck of 54 cards according to a given random order and repeats for a given number of times. It is assumed that the initial status of a card deck is in the following order:
```
S1, S2, ..., S13, 
H1, H2, ..., H13, 
C1, C2, ..., C13, 
D1, D2, ..., D13, 
J1, J2
```
where "S" stands for "Spade", "H" for "Heart", "C" for "Club", "D" for "Diamond", and "J" for "Joker". A given order is a permutation of distinct integers in [1, 54]. If the number at the i-th position is j, it means to move the card from position i to position j. For example, suppose we only have 5 cards: S3, H5, C1, D13 and J2. Given a shuffling order {4, 2, 5, 3, 1}, the result will be: J2, H5, D13, S3, C1. If we are to repeat the shuffling again, the result will be: C1, H5, S3, J2, D13.

## Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer K (≤20) which is the number of repeat times. Then the next line contains the given order. All the numbers in a line are separated by a space.

## Output Specification:
For each test case, print the shuffling results in one line. All the cards are separated by a space, and there must be no extra space at the end of the line.

## Sample Input:
```
2
36 52 37 38 3 39 40 53 54 41 11 12 13 42 43 44 2 4 23 24 25 26 27 6 7 8 48 49 50 51 9 10 14 15 16 5 17 18 19 1 20 21 22 28 29 30 31 32 33 34 35 45 46 47
```
## Sample Output:
```
S7 C11 C10 C12 S1 H7 H8 H9 D8 D9 S11 S12 S13 D10 D11 D12 S3 S4 S6 S10 H1 H2 C13 D2 D3 D4 H6 H3 D13 J1 J2 C1 C2 C3 C4 D1 S5 H5 H11 H12 C6 C7 C8 C9 S2 S8 S9 H10 D5 D6 D7 H4 H13 C5
```

# 1046 Shortest Distance （20 分）
[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1046/main.cpp)

The task is really simple: given N exits on a highway which forms a simple cycle, you are supposed to tell the shortest distance between any pair of exits.

## Input Specification:
Each input file contains one test case. For each case, the first line contains an integer N (in [3,10^5]), followed by N integer distances D1 D2...DN, where Di is the distance between the i-th and the (i+1)-st exits, and DN is between the N-th and the 1st exits. All the numbers in a line are separated by a space. The second line gives a positive integer M (≤10^4), with M lines follow, each contains a pair of exit numbers, provided that the exits are numbered from 1 to N. It is guaranteed that the total round trip distance is no more than 10^7.

## Output Specification:
For each test case, print your results in M lines, each contains the shortest distance between the corresponding given pair of exits.

## Sample Input:
```
5 1 2 4 14 9
3
1 3
2 5
4 1
```
## Sample Output:
```
3
10
7
```

# 1065 A+B and C (64bit) （20 分）
[C++ (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1065/main.cpp)

Given three integers A, B and C in [−2^63,2^63], you are supposed to tell whether A+B>C.

## Input Specification:
The first line of the input gives the positive number of test cases, T (≤10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.

## Output Specification:
For each test case, output in one line Case #X: true if A+B>C, or Case #X: false otherwise, where X is the case number (starting from 1).

## Sample Input:
```
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
```
## Sample Output:
```
Case #1: false
Case #2: true
Case #3: false
```
