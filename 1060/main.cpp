#include <iostream>
#include <string>

using namespace std;

int N;
string A, B;

void prints(string s, int exp)
{
    cout << "0." << s << "*10^" << exp;
}

string trims(string str, int& exp)
{
    int p = str.find("0.");
    if (p != string::npos)
        str.erase(str.begin(), str.begin() + p + 1);
    exp = str.find(".");
    if (exp == string::npos)
        exp = str.size();
    else
        str.erase(str.begin() + exp);
    while (str.size() > 0 && str[0] == '0')
    {
        exp--;
        str.erase(str.begin());
    }
    if (str.size() == 0)
        exp = 0;
    if (str.size() > N)
        str = str.substr(0, N);
    while (str.size() < N)
        str += "0";
    return str;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N >> A >> B;

    int aexp = 0, bexp = 0;

    A = trims(A, aexp);
    B = trims(B, bexp);

    if (A == B && aexp == bexp)
    {
        cout << "YES ";
        prints(A, aexp);
    }
    else
    {
        cout << "NO ";
        prints(A, aexp);
        cout << " ";
        prints(B, bexp);
    }
    return 0;
}
