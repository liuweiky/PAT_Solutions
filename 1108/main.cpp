#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX_N 128

#define EPS 0.0000001

using namespace std;

int N;

int main()
{
    scanf("%d", &N);

    double total = 0;
    int val_cnt = 0;

    for (int i = 0; i < N; i++)
    {
        char buf[10240];
        scanf("%s", buf);
        int len = strlen(buf);

        bool val = true;
        int dot_pos = -1;

        for (int i = 0; i < len; i++)
            if (buf[i] == '.')
            {
                dot_pos = i;
                break;
            }

        if (dot_pos != -1 && len - dot_pos > 3)
            val = false;

        double d;
        if (sscanf(buf, "%lf", &d) != 1)
            val = false;

        if (val && !(d < 1000 + EPS && d > -1000 - EPS))
            val = false;

        if (!val)
            printf("ERROR: %s is not a legal number\n", buf);
        else
        {
            val_cnt++;
            total += d;
        }
    }

    if (val_cnt == 0)
        printf("The average of 0 numbers is Undefined");
    else if (val_cnt == 1)
        printf("The average of %d number is %.2f", val_cnt, total / val_cnt);
    else
        printf("The average of %d numbers is %.2f", val_cnt, total / val_cnt);

    return 0;
}
