#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

char sentence[128][512];
int N;

int min_len = INT_MAX;

int main()
{
    scanf("%d", &N);

    getchar();

    for (int i = 1; i <= N; i++)
    {
        cin.getline(sentence[i], 512);
        min_len = min_len > strlen(sentence[i]) ? strlen(sentence[i]) : min_len;
    }
    int len = 0;
    for (; len < min_len;)
    {
        int l = len + 1;
        char c = sentence[1][strlen(sentence[1]) - l];

        int flag = 1;

        for (int i = 2; i <= N; i++)
        {
            if (c != sentence[i][strlen(sentence[i]) - l])
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            len++;
        } else
        {
            break;
        }
    }

    if (len == 0)
        printf("nai");
    else
        printf("%s", &sentence[1][strlen(sentence[1]) - len]);

    return 0;
}
