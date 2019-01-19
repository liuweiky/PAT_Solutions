#include <cstdio>
#include <cstring>

#define MAX_LEN 128

using namespace std;

char N[MAX_LEN];
char eng[10][32] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int sum_digit()
{
    int s = 0;
    for (int i = 0; i < strlen(N); i++)
        s += N[i] - '0';
    return s;
}

void eng_out(int n)
{
    char s[512];
    sprintf(s, "%d", n);
    for (int i = 0; i < strlen(s); i++)
    {
        printf("%s", eng[s[i] - '0']);
        if (i != strlen(s) - 1)
            printf(" ");
    }
}

int main()
{
    scanf("%s", N);
    eng_out(sum_digit());
    return 0;
}
