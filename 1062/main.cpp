#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

#define SAGE 4
#define NOBLE 3
#define FOOL 2
#define SMALL 1

using namespace std;

struct Person
{
    char id[16];
    int talent, virtue, type;
};

vector<Person*> ps;

bool cmp1(Person* p1, Person* p2)
{
    if (p1->type != p2->type)
        return p1->type > p2->type;
    else if (p1->talent + p1->virtue != p2->talent + p2->virtue)
        return p1->talent + p1->virtue > p2->talent + p2->virtue;
    else if (p1->virtue != p2->virtue)
        return p1->virtue > p2->virtue;
    else
        return strcmp(p1->id, p2->id) < 0;
}

int N, L, H;

int main()
{
    scanf("%d %d %d", &N, &L, &H);

    for (int i = 0; i < N; i++)
    {
        Person* p = new Person;
        scanf("%s", p->id);
        scanf("%d %d", &p->virtue, &p->talent);

        if (p->talent >= H && p->virtue >= H)
            p->type = SAGE;
        else if (p->talent < H && p->virtue >= H)
            p->type = NOBLE;
        else if (p->talent < H && p->virtue < H && p->virtue >= p->talent)
            p->type = FOOL;
        else
            p->type = SMALL;

        if (p->talent >= L && p->virtue >= L)
            ps.push_back(p);
    }

    sort(ps.begin(), ps.end(), cmp1);

    printf("%d", ps.size());

    for (int i = 0; i < ps.size(); i++)
        printf("\n%s %d %d", ps[i]->id, ps[i]->virtue, ps[i]->talent);

    return 0;
}
