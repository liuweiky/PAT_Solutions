#include <iostream>
#include <sstream>

#define CARD_NUM 64

using namespace std;

string bak[CARD_NUM];
string scard[CARD_NUM];

int order[CARD_NUM];
int sftime;

void init()
{
    for (int i = 1; i <= 13; i++)
    {
        stringstream ss;
        ss << i;
        bak[i] = "S";
        bak[i] += ss.str();
        scard[i] = bak[i];
    }
    for (int i = 14; i <= 26; i++)
    {
        stringstream ss;
        ss << i - 13;
        bak[i] = "H";
        bak[i] += ss.str();
        scard[i] = bak[i];
    }
    for (int i = 27; i <= 39; i++)
    {
        stringstream ss;
        ss << i - 26;
        bak[i] = "C";
        bak[i] += ss.str();
        scard[i] = bak[i];
    }
    for (int i = 40; i <= 52; i++)
    {
        stringstream ss;
        ss << i - 39;
        bak[i] = "D";
        bak[i] += ss.str();
        scard[i] = bak[i];
    }
    bak[53] = "J1";
    bak[54] = "J2";
    scard[53] = bak[53];
    scard[54] = bak[54];
}

void shuffle()
{
    for (int i = 1; i <= 54; i++)
    {
        int pos = order[i];
        scard[pos] = bak[i];
    }

    for (int i = 1; i <= 54; i++)
        bak[i] = scard[i];
}

int main()
{
    init();
    cin >> sftime;
    for (int i = 1; i <= 54; i++)
        cin >> order[i];

    for (int i = 1; i <= sftime; i++)
        shuffle();

    for (int i = 1; i <= 54; i++)
    {
        cout << bak[i];
        if (i != 54)
            cout << " ";
    }

    return 0;
}
