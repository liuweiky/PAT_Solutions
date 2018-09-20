#include <iostream>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

string org_string;
int min_d = INT_MAX;
int opt_n;

int main()
{
    cin >> org_string;

    int n = 1;
    for (; n <= org_string.length() / 2; n++)
    {
        int n2 = org_string.length() + 2 - 2 * n;
        if (n2 < n) continue;
        int d = abs(n2 - n);
        if (d <= min_d)
        {
            min_d = d;
            opt_n = n;
        }
    }

    int n2 = org_string.length() + 2 - 2 * opt_n;

    for (int i = 0; i < opt_n - 1; i++)
    {
        cout << org_string[i];
        for (int j = 0; j < n2 - 2; j++)
            cout << ' ';
        cout << org_string[org_string.length() - 1 - i] << endl;
    }
    cout << org_string.substr(opt_n - 1, n2);
    return 0;
}
