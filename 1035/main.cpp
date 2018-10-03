#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

struct account
{
    char username[16];
    char psw[16];
};

int N;

vector<account*> accounts;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        account* a = new account;
        scanf("%s %s", a->username, a->psw);

        int flag = 0;

        for (int j = 0; j < strlen(a->psw); j++)
        {
            switch (a->psw[j])
            {
            case '1':
                a->psw[j] = '@';
                flag = 1;
                break;
            case '0':
                a->psw[j] = '%';
                flag = 1;
                break;
            case 'l':
                a->psw[j] = 'L';
                flag = 1;
                break;
            case 'O':
                a->psw[j] = 'o';
                flag = 1;
                break;
            }
        }

        if (flag)
            accounts.push_back(a);

    }

    if (accounts.size() == 0)
    {
        if (N == 1)
            printf("There is 1 account and no account is modified");
        else
            printf("There are %d accounts and no account is modified", N);
        return 0;
    }

    printf("%d", accounts.size());

    for (int i = 0; i < accounts.size(); i++)
        printf("\n%s %s", accounts[i]->username, accounts[i]->psw);

    return 0;
}
