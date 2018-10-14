#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct student
{
    char name[16];
    char id[16];
    int grade;
};

int N, grade1, grade2;
vector<student*> stus;

bool cmp(student* s1, student* s2)
{
    return s1->grade > s2->grade;
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        student* s = new student;
        scanf("%s %s %d", s->name, s->id, &s->grade);
        stus.push_back(s);
    }

    scanf("%d %d", &grade1, &grade2);

    sort(stus.begin(), stus.end(), cmp);

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        if (stus[i]->grade >= grade1 && stus[i]->grade <= grade2)
        {
            cnt++;
            printf("%s %s\n", stus[i]->name, stus[i]->id);
        }
    }

    if (cnt == 0)
        printf("NONE");

    return 0;
}
