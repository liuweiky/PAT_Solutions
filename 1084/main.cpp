#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

bool hmap[512];

int main()
{
    memset(hmap, 0, 512);

    char ch;
    char s[128];
    scanf("%s", s);

    getchar();

    for (int i = 0; i < strlen(s); i++)
        hmap[toupper(s[i])] = 1;

    while ((ch = getchar()) != '\n')
        if (hmap[toupper(ch)] == 1)
            hmap[toupper(ch)] = 0;

    for (int i = 0; i < strlen(s); i++)
        if (hmap[toupper(s[i])])
        {
            printf("%c", toupper(s[i]));
            hmap[toupper(s[i])] = 0;
        }
    return 0;
}
