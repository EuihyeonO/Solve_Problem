#include <string>
#include <vector>
#include <algorithm>

std::string solution(std::string s, std::string skip, int index)
{
    std::string answer;
    char NextChar;

    for (int i = 0; i < s.size(); i++)
    {
        NextChar = s[i];

        for (int j = 0; j < index; j++)
        {
            ++NextChar;

            if (NextChar > 122) //z를 넘어가면 a로 돌아감
            {
                NextChar = 97;
            }

            if (skip.find(NextChar) != -1) //skip에 있는 알파벳이 맞으면, 1턴을 넘어감
            {
                j--;
            }
        }

        answer.push_back(NextChar);
    }
    return answer;
}