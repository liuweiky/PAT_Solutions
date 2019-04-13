#include <cstdio>
#include <algorithm>
#include <set>
#include <map>

#define MAX_N 51200

using namespace std;

struct item
{
    int id, freq;
    item() {}
    bool operator < (const item& rhs) const
    {
        if (freq != rhs.freq)
            return freq > rhs.freq;
        return id < rhs.id;
    }
};

int N, K;
set<item> items;
map<int, int> mp;

int main()
{

    scanf("%d %d", &N, &K);

    int t;
    scanf("%d", &t);

    item itm;
    itm.id = t;
    itm.freq = 1;
    items.insert(itm);
    mp[t] = 1;

    for (int i = 1; i < N; i++)
    {
        scanf("%d", &t);
        printf("%d:", t);

        set<item>::iterator itr = items.begin();

        for (int j = 0; itr != items.end() && j < K; j++, itr++)
            printf(" %d", itr->id);
        printf("\n");
        if (mp.find(t) == mp.end())
        {
            item it;
            it.id = t;
            it.freq = 1;
            mp[t] = 1;
            items.insert(it);
        }
        else
        {
            item it;
            it.id = t;
            it.freq = mp[t];
            set<item>::iterator iter = items.find(it);
            items.erase(iter);
            it.freq++;
            items.insert(it);
            mp[t]++;
        }
    }

    return 0;
}
