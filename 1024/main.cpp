#include <cstdio>
#include <climits>
#include <cstring>
#include <algorithm>

using namespace std;

int number[1024] = {0};
int rev_number[1024] = {0};
char char_number[1024] = {'0'};
int K;
int len;

void Add()
{
    int carry = 0;
    for (int i = 0; i < len; i++)
    {
        int t = number[i] + rev_number[i]  + carry;
        number[i] = (t % 10);
        carry = t / 10;
    }
    if (carry)
    {
        number[len] = carry;
        len++;
    }
}

bool Check()
{
    for (int i = 0; i <= len / 2; i++)
        if (number[i] != number[len - 1 - i])
            return false;
    return true;
}

int main()
{
    scanf("%s", &char_number);
    scanf("%d", &K);
    len = strlen(char_number);
    reverse(char_number, char_number + len);

    for (int i = 0; i < len; i++)
        number[i] = char_number[i] - '0';

    if (Check() || K == 0)
    {
        for (int i = len - 1; i >= 0; i--)
            printf("%d", number[i]);
        printf("\n0");
        return 0;
    }
    int step = 1;
    for (; step <= K; step++)
    {
        for (int i = 0; i < len; i++)
            rev_number[i] = number[i];
        reverse(rev_number, rev_number + len);
        Add();
        if (Check() || step == K)
            break;
    }
    for (int i = len - 1; i >= 0; i--)
        printf("%d", number[i]);
    printf("\n%d", step);
    return 0;
}
