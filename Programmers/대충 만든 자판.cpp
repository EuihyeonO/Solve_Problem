#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {

    std::map<char, int> KeyMinInput;

    int KeySize = keymap.size();
    int TargetSize = targets.size();

    vector<int> answer(TargetSize, 0);

    //map에 알파벳을 하나씩 key에 넣고, data는 -1로 초기화
    for (int i = 0; i < 26; i++)
    {
        KeyMinInput.insert({ 65 + i, -1 });
    }

    //map에 알파벳당 최소 클릭횟수를 저장

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

    //target의 알파벳 정보를 map에 넣어, 최소입력횟수를 확인 후 answer에 넣는다.

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