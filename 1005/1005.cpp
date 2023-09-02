#include <cstdio>
#include <cstring>

const char* english[] = { "zero", "one", "two", "three" , "four" , "five" , "six", "seven", "eight", "nine" };

int main()
{
    int N;
    char buf[256];
    scanf("%s", buf);

    int len = strlen(buf);
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum += (buf[i] - '0');
    }

    char speak[256];
    sprintf(speak, "%d", sum);
    len = strlen(speak);

    for (int i = 0; i < len; i++)
    {
        if (i != 0)
        {
            printf(" ");
        }
        printf("%s", english[speak[i] - '0']);
    }

    return 0;
}
