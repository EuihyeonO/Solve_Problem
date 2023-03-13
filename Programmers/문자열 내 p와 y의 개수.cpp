#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int Pcount = 0;
    int Ycount = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P' || s[i] == 'p')
        {
            ++Pcount;
        }
        else if (s[i] == 'Y' || s[i] == 'y')
        {
            ++Ycount;
        }
    }

    return answer = (Pcount == Ycount) ? true : false;
}