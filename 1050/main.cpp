#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX_N 10240

using namespace std;

char orgstr[MAX_N];
bool ascii_map[256];

int main()
{
    memset(ascii_map, 0, 256);

    cin.getline(orgstr, MAX_N);

    char ch;
    while ((ch = getchar()) != '\n')
        ascii_map[ch] = 1;

    for (int i = 0; i < strlen(orgstr); i++)
        if (ascii_map[orgstr[i]] == 0)
            putchar(orgstr[i]);

    return 0;
}
