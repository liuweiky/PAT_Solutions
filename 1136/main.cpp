#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

string A, B, R;

bool is_palindrome(string& s)
{
    int sz = s.size();
    for (int i = 0; i < sz; i++)
        if (s[i] != s[sz - i - 1])
            return false;
    return true;
}

string add()
{
    int carry = 0;
    int sz = A.size();
    string res = "";
    for (int i = 0; i < sz; i++)
    {
        int t = A[i] - '0' + B[i] - '0' + carry;
        res += (t % 10) + '0';
        carry = t / 10;
    }
    if (carry)
        res += carry + '0';
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> A;

    reverse(A.begin(), A.end());

    int step = 0;
    R = A;
    bool pali = is_palindrome(A);

    while (step < 10 && !pali)
    {
        B = A;
        reverse(B.begin(), B.end());
        R = add();
        pali = is_palindrome(R);
        string sR = R;
        reverse(sR.begin(), sR.end());
        cout << B << " + " << A << " = " << sR << endl;
        A = R;
        step++;
        //system("pause");
    }

    if (pali)
        cout << R << " is a palindromic number.";
    else
        cout << "Not found in 10 iterations.";

    return 0;
}
