#include <cstdio>
#include <stack>
#include <cstring>

using namespace std;

int red, green, blue;
char r13[4], g13[4], b13[4];


void to13(int a, char b[])
{
    if (a == 0)
    {
        b[0] = '0';
        b[1] = '\0';
        return;
    }
    stack<int> s;
    while (a)
    {
        int t = a % 13;
        s.push(t);
        a /= 13;
    }
    int cnt = 0;
    while (!s.empty())
    {
        int t = s.top();
        s.pop();
        if (t < 10)
        {
            b[cnt] = t + '0';
        } else {
            b[cnt] = t - 10 + 'A';
        }
        cnt++;
    }
    b[cnt] = '\0';
}


int main()
{
    scanf("%d %d %d", &red, &green, &blue);

    to13(red, r13);
    to13(green, g13);
    to13(blue, b13);

    // 注意这里的字符串定长表示

    if (strlen(r13) < 2)
    {
        char zero[] = "0";
        strcat(zero, r13);
        strcpy(r13, zero);
    }

    if (strlen(g13) < 2)
    {
        char zero[] = "0";
        strcat(zero, g13);
        strcpy(g13, zero);
    }

    if (strlen(b13) < 2)
    {
        char zero[] = "0";
        strcat(zero, b13);
        strcpy(b13, zero);
    }

    printf("#%s%s%s", r13, g13, b13);

    return 0;
}
