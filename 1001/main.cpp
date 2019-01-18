#include <cstdio>
#include <cstring>

using namespace std;

int a, b;

int main()
{
    scanf("%d %d", &a, &b);

    int c = a + b;
    if (c < 0)
    {
        printf("-");
        c = -c;
    }
    char s[50];

    sprintf(s, "%d", c);
    int l = strlen(s);
    int offset = l % 3;
    for (int i = 0; i < offset; i++)
        printf("%c", s[i]);

    for (int i = 0; i < l - offset; i++)
    {
        if (i % 3 == 0 && !(offset == 0 && i == 0))
            printf(",");
        printf("%c", s[i + offset]);
    }

    return 0;
}
