#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

string org;

int main()
{
    cin >> org;

    int epos = org.find('E');

    string n = org.substr(0, epos);

    int exp;

    stringstream ss;

    ss << org.substr(epos + 1, org.length() - epos);
    ss >> exp;

    int dotpos = n.find('.');


    if (exp < 0)
    {
        n.erase(dotpos, 1);
        for (int i = 0; i < abs(exp); i++)
        {
            n.insert(1, "0");
        }
        n.insert(dotpos, ".");
        if (n[0] == '+')
            n = n.substr(1, n.length() - 1);
        cout << n;
    } else if (exp > 0)
    {

        int l = n.length();

        if (l - 1 - dotpos > exp)
            n.insert(dotpos + exp + 1, ".");
        else if (l - 1 - dotpos == exp)
        {

        }
        else
        {
            for (int i = 0; i < abs(exp) - (l - 1 - dotpos); i++)
            {
                n.insert(n.length(), "0");
            }
        }
        n.erase(dotpos, 1);

        if (n[0] == '+')
            n = n.substr(1, n.length() - 1);
        cout << n;
    } else
    {
        cout << n;
    }




    return 0;
}
