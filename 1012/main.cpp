#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

#define MAX_N 2048

using namespace std;

char course[] = {'A', 'C', 'M', 'E'};

struct Student
{
    char id[16];
    int a, c, m, e;
    int rnk[4];
};

bool acmp(Student* s1, Student* s2)
{
    return s1->a > s2->a;
}

bool ccmp(Student* s1, Student* s2)
{
    return s1->c > s2->c;
}

bool mcmp(Student* s1, Student* s2)
{
    return s1->m > s2->m;
}

bool ecmp(Student* s1, Student* s2)
{
    return s1->e > s2->e;
}

vector<Student*> stus;

int rnk[MAX_N][4];

int M, N;

int main()
{
    scanf("%d %d", &N, &M);
    memset(rnk, 0, MAX_N * 4);

    for (int i = 0; i < N; i++)
    {
        Student* s = new Student;
        int id;
        scanf("%s %d %d %d", s->id, &s->c, &s->m, &s->e);
        s->a = (s->c + s->m + s->e) / 3;
        stus.push_back(s);
    }

    sort(stus.begin(), stus.end(), acmp);

    stus[0]->rnk[0] = 1;

    for (int i = 1; i < stus.size(); i++)
    {
        if (stus[i]->a == stus[i - 1]->a)
            stus[i]->rnk[0] = stus[i - 1]->rnk[0];
        else
            stus[i]->rnk[0] = i + 1;
    }

    sort(stus.begin(), stus.end(), ccmp);

    stus[0]->rnk[1] = 1;

    for (int i = 1; i < stus.size(); i++)
    {
        if (stus[i]->c == stus[i - 1]->c)
            stus[i]->rnk[1] = stus[i - 1]->rnk[1];
        else
            stus[i]->rnk[1] = i + 1;
    }

    sort(stus.begin(), stus.end(), mcmp);

    stus[0]->rnk[2] = 1;

    for (int i = 1; i < stus.size(); i++)
    {
        if (stus[i]->m == stus[i - 1]->m)
            stus[i]->rnk[2] = stus[i - 1]->rnk[2];
        else
            stus[i]->rnk[2] = i + 1;
    }

    sort(stus.begin(), stus.end(), ecmp);

    stus[0]->rnk[3] = 1;

    for (int i = 1; i < stus.size(); i++)
    {
        if (stus[i]->e == stus[i - 1]->e)
            stus[i]->rnk[3] = stus[i - 1]->rnk[3];
        else
            stus[i]->rnk[3] = i + 1;
    }

    for (int i = 0; i < M; i++)
    {
        char id[16];
        scanf("%s", id);

        int flag = 0;

        for (int i = 0; i < stus.size(); i++)
        {
            int d = 0, m = INT_MAX;
            if (strcmp(id, stus[i]->id) == 0)
            {
                flag = 1;
                for (int j = 0; j < 4; j++)
                {
                    if (stus[i]->rnk[j] < m)
                    {
                        d = j;
                        m = stus[i]->rnk[j];
                    }
                }
                printf("%d %c\n", m, course[d]);
                break;
            }
        }

        if (!flag)
            printf("N/A\n");
    }

    return 0;
}
