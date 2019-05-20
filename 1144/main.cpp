#include <cstdio>
#include <set>

using namespace std;

int N;
set<int> st;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int t;
        scanf("%d", &t);
        st.insert(t);
    }

    int expect = 1;

    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        if (*it <= 0)
            continue;
        else if (*it != expect)
        {
            printf("%d", expect);
            return 0;
        }
        expect++;
    }
    printf("%d", expect);

    return 0;
}
