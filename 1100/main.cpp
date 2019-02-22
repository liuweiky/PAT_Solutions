#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>

using namespace std;

map<string, int> low_map;
map<string, int> high_map;

string low_s[16] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high_s[16] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int N;

int main()
{
    for (int i = 0; i < 13; i++)
    {
        low_map[low_s[i]] = i;
        high_map[high_s[i]] = i;
    }

    cin >> N;
    getchar();

    for (int i = 0; i < N; i++)
    {
        string number;
        getline(cin, number);
        if (isalpha(number[0]))
        {
            int low, high;
            int p = number.find(" ");
            if (p == string::npos)
            {
                if (high_map.find(number) != high_map.end())
                {
                    high = high_map[number];
                    low = 0;
                }
                else
                {
                    high = 0;
                    low = low_map[number];
                }
            }
            else
            {
                high = high_map[number.substr(0, p)];
                low = low_map[number.substr(p + 1, number.size() - p - 1)];
            }
            cout << 13 * high + low << endl;
        }
        else
        {
            if (number == "0")
            {
                cout << "tret" << endl;
                return 0;
            }
            int n;
            sscanf(number.c_str(), "%d", &n);
            int low = n % 13;
            int high = n / 13;
            if (high != 0)
                cout << high_s[high];
            if (low != 0)
            {
                if (high != 0)
                    cout << " ";
                cout << low_s[low];
            }
            cout << endl;
        }
        //getchar();
    }

    return 0;
}
