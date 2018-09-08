# My PAT Answers
记录我在刷 PAT 甲级时遇到的一些问题以及总结的经验。做法可能不是最优的，如有更好的解法，欢迎 PR！

## 1001 A+B Format（20 分）
[Java (20/20)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1001/Main.java)

Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where -10^6≤a,b≤10^6. The numbers are separated by a space.

### Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

### Sample Input:
```
-1000000 9
```
### Sample Output:
```
-999,991
```

## 1002 A+B for Polynomials（25 分）
[Java (25/25)](https://github.com/Heliovic/My_PAT_Answer/blob/master/1002/Main.java)

This time, you are supposed to find A+B where A and B are two polynomials.

### Input Specification:
Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial:

K N1 a1 N2 a2 ... Nk ak

where K is the number of nonzero terms in the polynomial, Ni and ai(i=1,2,⋯,K) are the exponents and coefficients, respectively. It is given that 1≤K≤10，0≤Nk<⋯<N2<N1≤1000.

### Output Specification:
For each test case you should output the sum of A and B in one line, with the same format as the input. Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

### Sample Input:
```
2 1 2.4 0 3.2
2 2 1.5 1 0.5
```
### Sample Output:
```
3 2 1.5 1 2.9 0 3.2
```
