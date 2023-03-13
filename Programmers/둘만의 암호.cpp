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

            if (NextChar > 122) //z�� �Ѿ�� a�� ���ư�
            {
                NextChar = 97;
            }

            if (skip.find(NextChar) != -1) //skip�� �ִ� ���ĺ��� ������, 1���� �Ѿ
            {
                j--;
            }
        }

        answer.push_back(NextChar);
    }
    return answer;
}