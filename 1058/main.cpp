#include <cstdio>

using namespace std;

long long G = 0, S = 0, K = 0, sum = 0;

int main()
{
    scanf("%lld.%lld.%lld", &G, &S, &K);
    sum = G * 17 * 29 + S * 29 + K;
    scanf("%lld.%lld.%lld", &G, &S, &K);
    sum += G * 17 * 29 + S * 29 + K;
    printf("%lld.%lld.%lld", sum / (17 * 29), (sum / 29) % 17, sum % 29);
    return 0;
}
