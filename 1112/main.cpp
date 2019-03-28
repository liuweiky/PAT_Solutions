#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

#define MAX_LEN 1024

using namespace std;

bool is_stucked[256];
bool not_stucked[256];
vector<char> pos_stk_char;
int k, len;
char str[MAX_LEN];

int main()
{
    fill_n(is_stucked, 256, false);
    fill_n(not_stucked, 256, false);
    scanf("%d", &k);
    scanf("%s", str);

    int len = strlen(str);

    int cnt = 1;

    for (int i = 1; i < len; i++)
    {
        if (str[i] == str[i - 1])
            cnt++;
        else
        {
            if (cnt % k != 0)
            {
                not_stucked[str[i - 1]] = true;
                is_stucked[str[i - 1]] = false;
            }
            cnt = 1;

        }
        if (cnt >= k && !not_stucked[str[i]] && !is_stucked[str[i]])
        {
            is_stucked[str[i]] = true;
            pos_stk_char.push_back(str[i]);
        }
    }

    vector<char> stk_char;
    for (int i = 0; i < pos_stk_char.size(); i++)
        if (is_stucked[pos_stk_char[i]])
            stk_char.push_back(pos_stk_char[i]);

    for (int i = 0; i < stk_char.size(); i++)
        putchar(stk_char[i]);

    putchar('\n');

    for (int i = 0; i < len; i++)
    {
        putchar(str[i]);
        if (is_stucked[str[i]])
            i += k - 1;
    }

    return 0;
}
