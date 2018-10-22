#include <cstdio>
#include <cstring>

using namespace std;

int beeds[256];

int main()
{
    memset(beeds, 0, 256);
    char ch;

    int tot = 0, mis = 0, need = 0;;

    while ((ch = getchar()) != '\n')
    {
        beeds[ch]++;
        tot++;
    }

    while ((ch = getchar()) != '\n')
    {
        need++;
        if (beeds[ch] == 0)
            mis++;
        else
            beeds[ch]--;
    }

    if (mis)
        printf("No %d", mis);
    else
        printf("Yes %d", tot - need);

    return 0;
}
