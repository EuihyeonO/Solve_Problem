#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    //set�� map�� key�� ���� �ڵ����ĵǴ� ���� �̿��Ͽ�, map�� n��°�� ���ĺ����� ���Ľ�Ű��, set�� n������ ���ĺ��� ���� ���ڿ����� ���Ľ�Ų��.
    map<char, set<string>> StringMap;

    for (int i = 0; i < strings.size(); i++)
    {
        char IndexChar = strings[i][n];

        StringMap[IndexChar].insert(strings[i]);
    }

    map<char, set<string>>::iterator StartIter = StringMap.begin();
    map<char, set<string>>::iterator EndIter = StringMap.end();

    set<string>::iterator SetStartIter;
    set<string>::iterator SetEndIter;

    for (; StartIter != EndIter; StartIter++)
    {
        SetStartIter = StartIter->second.begin();
        SetEndIter = StartIter->second.end();

        for (; SetStartIter != SetEndIter; SetStartIter++)
        {
            answer.push_back(SetStartIter->data());
        }
    }


    return answer;
}