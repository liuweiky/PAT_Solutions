#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

struct Testee
{
    int score, location_number, final_rank, local_rank;
    char registration_number[16];
};

vector<Testee*> testees;

int N;

bool cmp1(Testee* t1, Testee* t2)
{
    return t1->score > t2->score;
}

bool cmp2(Testee* t1, Testee* t2)
{
    if (t1->score > t2->score)
        return true;
    else if (t1->score == t2->score)
    {
        return strcmp(t1->registration_number, t2->registration_number) < 0 ? true : false;
    } else
        return false;
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        int k, prev_size = testees.size();
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            Testee* t = new Testee();
            scanf("%s", &t->registration_number);
            scanf("%d", &t->score);
            t->location_number = i;
            testees.push_back(t);
        }
        sort(testees.begin() + prev_size, testees.end(), cmp1);

        int cnt = 1;

        testees[prev_size]->local_rank = 1;

        for (int j = prev_size + 1; j < testees.size(); j++)
        {
            cnt++;
            if (testees[j - 1]->score == testees[j]->score)
                testees[j]->local_rank = testees[j - 1]->local_rank;
            else
                testees[j]->local_rank =cnt;
        }
    }

    sort(testees.begin(), testees.end(), cmp2);

    int rnk = 1;
    testees[0]->final_rank = 1;

    for (int i = 1; i < testees.size(); i++)
    {
        if (testees[i - 1]->score == testees[i]->score)
            testees[i]->final_rank = testees[i - 1]->final_rank;
        else
            testees[i]->final_rank = i + 1;
    }


    printf("%d\n", testees.size());

    for (int i = 0; i < testees.size(); i++)
        printf("%s %d %d %d\n", testees[i]->registration_number, testees[i]->final_rank, testees[i]->location_number, testees[i]->local_rank);

    return 0;
}
