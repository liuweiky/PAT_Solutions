#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char s1[128];
char s2[128];
char s3[128];
char s4[128];

char day[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    scanf("%s", &s1);
    scanf("%s", &s2);
    scanf("%s", &s3);
    scanf("%s", &s4);

    char a;
    int b, c;

    int cnt = 0;

    for (int i = 0; i < min(strlen(s1), strlen(s2)); i++)
    {
        if (s1[i] == s2[i] && cnt == 1)
        {
            if (s1[i] >= 'A' && s1[i] <= 'N')
            {
                b = s1[i] - 'A' + 10;
                break;
            } else if (s1[i] >= '0' && s1[i] <= '9')
            {
                b = s1[i] - '0';
                break;
            }
        }

        if (s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G' && cnt == 0)
        {
            cnt++;
            a = s1[i];
        }
    }

    for (int i = 0; i < min(strlen(s3), strlen(s4)); i++)
    {
        if (s3[i] == s4[i] && (s3[i] >= 'a' && s3[i] <= 'z') || s3[i] >= 'A' && s3[i] <= 'Z')
        {
            c = i;
            break;
        }
    }

    printf("%s %02d:%02d", day[a - 'A'], b, c);

    return 0;
}
