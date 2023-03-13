#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;

    //set과 map은 key에 따라 자동정렬되는 것을 이용하여, map은 n번째의 알파벳으로 정렬시키고, set은 n번쨰의 알파벳이 같은 문자열들을 정렬시킨다.
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