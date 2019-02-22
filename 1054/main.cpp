#include <cstdio>
#include <map>

using namespace std;

int M, N;
map<long long, int> mps;

int main()
{
    scanf("%d %d", &M, &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            long long c;
            scanf("%lld", &c);
            if (mps.find(c) == mps.end())
                mps[c] = 1;
            else mps[c]++;
        }
    }

    int half = M * N / 2;

    for (map<long long, int>::iterator it = mps.begin(); it != mps.end(); it++)
        if (it->second > half)
        {
            printf("%lld", it->first);
            return 0;
        }

    return 0;
}
