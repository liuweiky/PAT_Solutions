#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

#define MAX_N 40960
#define MAX_K 4096

using namespace std;

int N, K;

vector<string> course_stu[MAX_K];

int main()
{
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        string name;
        char str_name[16];
        int num;
        scanf("%s %d", str_name, &num);
        name = str_name;
        for (int j = 0; j < num; j++)
        {
            int k;
            scanf("%d", &k);
            course_stu[k].push_back(name);
        }
    }

    for (int i = 1; i <= K; i++)
    {
        sort(course_stu[i].begin(), course_stu[i].end());
        int sz = course_stu[i].size();
        printf("%d %d\n", i, sz);
        for (int j = 0; j < sz; j++)
            printf("%s\n", course_stu[i][j].c_str());
    }

    return 0;
}
