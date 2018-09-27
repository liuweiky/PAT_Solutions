#include <cstdio>
#include <vector>

using namespace std;

struct Stu
{
    char name[16];
    char ID[16];
    char gender;
    int grade;
};

vector<Stu*> stus;

int N;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        Stu* s = new Stu;
        scanf("%s %c %s %d", &s->name, &s->gender, &s->ID, &s->grade);
        stus.push_back(s);
    }

    int maxfidx = -1, minmidx = -1;
    int maxfg = -1, minmg = 128;

    for (int i = 0; i < N; i++)
    {
        Stu* s = stus[i];
        if (s->gender == 'F' && s->grade > maxfg)
        {
            maxfidx = i;
            maxfg = s->grade;
        } else if (s->gender == 'M' && s->grade < minmg)
        {
            minmidx = i;
            minmg = s->grade;
        }
    }

    if (maxfidx == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", stus[maxfidx]->name, stus[maxfidx]->ID);

    if (minmidx == -1)
        printf("Absent\n");
    else
        printf("%s %s\n", stus[minmidx]->name, stus[minmidx]->ID);

    if (maxfidx == -1 || minmidx == -1)
        printf("NA");
    else
        printf("%d", stus[maxfidx]->grade - stus[minmidx]->grade);

    return 0;
}
