#include <cstdio>
#include <cstring>

#define MAX_N 16

using namespace std;

char num[MAX_N];

char spoken[12][12] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

char unit[12][12] = {"Yi", "Qian", "Bai", "Shi", "", "Qian", "Bai", "Shi", ""};



int zerochk(int s)
{
    for (int i = s + 1; i < 9; i++)
        if (num[i] != '0')
            return i;
    return 9;
}

int main()
{

    scanf("%s", num);
    if (num[0] == '-')
    {
        printf("Fu ");
        for (int i = 0; i < strlen(num); i++)
            num[i] = num[i + 1];
    }

    int len = strlen(num);

    int d = 9 - len;

    for (int i = 9; i >= d; i--)
        num[i] = num[i - d];

    for (int i = 0; i < d; i++)
        num[i] = '0';

    int zero_cnt = 0;

    for (int i = 0; i < 9; i++)
        if (num[i] != '0')
            break;
        else
            zero_cnt++;
    if (zero_cnt == 9)
    {
        printf("ling");
        return 0;
    }

    int i = zero_cnt;

    int flag = 0;

    while (i < 9)
    {
        if (flag)
        {
            printf(" ");
            flag = 1;
        }
        printf("%s", spoken[num[i] - '0']);

        if (i != 8)
            printf(" ");
        printf("%s", unit[i]);

        int n = zerochk(i);

        if (i == 4)
            printf("Wan");
        else if (i != 0 && i < 4 && n >4)
            printf(" Wan");

        if (n != i + 1 && n != 9)
        {
            printf(" ling");
        }
        i = n;
        flag = 1;
    }

    return 0;
}
