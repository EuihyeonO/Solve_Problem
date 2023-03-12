#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {

    std::map<char, int> KeyMinInput;

    int KeySize = keymap.size();
    int TargetSize = targets.size();

    vector<int> answer(TargetSize, 0);

    //map�� ���ĺ��� �ϳ��� key�� �ְ�, data�� -1�� �ʱ�ȭ
    for (int i = 0; i < 26; i++)
    {
        KeyMinInput.insert({ 65 + i, -1 });
    }

    //map�� ���ĺ��� �ּ� Ŭ��Ƚ���� ����

    for (int Y = 0; Y < KeySize; Y++)
    {
        int X_Keysize = keymap[Y].size();

        for (int X = 0; X < X_Keysize; X++)
        {
            if (KeyMinInput[keymap[Y][X]] == -1 || KeyMinInput[keymap[Y][X]] >= X + 1)
            {
                KeyMinInput[keymap[Y][X]] = X + 1;
            }
        }
    }

    //target�� ���ĺ� ������ map�� �־�, �ּ��Է�Ƚ���� Ȯ�� �� answer�� �ִ´�.

    for (int Y = 0; Y < TargetSize; Y++)
    {
        int X_TargetSize = targets[Y].size();

        for (int X = 0; X < X_TargetSize; X++)
        {
            if (KeyMinInput[targets[Y][X]] == -1)
            {
                answer[Y] = -1;
                break;
            }

            answer[Y] += KeyMinInput[targets[Y][X]];
        }
    }

    return answer;
}