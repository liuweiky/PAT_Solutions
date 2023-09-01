#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int result = a + b;
    if (result < 0)
    {
        printf("-");
        result = -result;
    }
    stringstream ss;
    ss << result;
    string s = ss.str();

    if (s.size() < 4)
    {
        printf("%d", result);
    }
    else
    {
        int beginning = s.size() % 3;
        for (int i = 0; i < s.size(); i++)
        {
            if ((i - beginning) % 3 == 0 && i != 0)
            {
                printf(",");
            }
            printf("%c", s[i]);
        }
    }

    return 0;
}
