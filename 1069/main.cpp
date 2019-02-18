#include <cstdio>
#include <algorithm>
#include <cstring>

#define DIGIT_N 4

using namespace std;

char n1[DIGIT_N + 4];
char n2[DIGIT_N + 4];

int main()
{
    fill_n(n1, DIGIT_N + 4, '\0');
    fill_n(n2, DIGIT_N + 4, '\0');

    int t;

    scanf("%d", &t);
    sprintf(n2, "%04d", t);

    int res = -1;

    while (res != 6174 && res != 0)
    {
        sort(n2, n2 + DIGIT_N);
        memcpy(n1, n2, (DIGIT_N + 1) * sizeof(char));
        reverse(n1, n1 + DIGIT_N);
        int in1, in2;
        sscanf(n1, "%d", &in1);
        sscanf(n2, "%d", &in2);
        res = in1 - in2;
        printf("%04d - %04d = %04d\n", in1, in2, res);
        sprintf(n2, "%04d", res);
    }

    return 0;
}
