//1 x 1 크기의 칸들로 이루어진 직사각형 격자 형태의 미로에서 탈출하려고 합니다.각 칸은 통로 또는 벽으로 구성되어 있으며, 
// 벽으로 된 칸은 지나갈 수 없고 통로로 된 칸으로만 이동할 수 있습니다.통로들 중 한 칸에는 미로를 빠져나가는 문이 있는데, 
// 이 문은 레버를 당겨서만 열 수 있습니다.레버 또한 통로들 중 한 칸에 있습니다.
// 따라서, 출발 지점에서 먼저 레버가 있는 칸으로 이동하여 레버를 당긴 후 미로를 빠져나가는 문이 있는 칸으로 이동하면 됩니다.
// 이때 아직 레버를 당기지 않았더라도 출구가 있는 칸을 지나갈 수 있습니다.
// 미로에서 한 칸을 이동하는데 1초가 걸린다고 할 때, 최대한 빠르게 미로를 빠져나가는데 걸리는 시간을 구하려 합니다.
//
//미로를 나타낸 문자열 배열 maps가 매개변수로 주어질 때, 미로를 탈출하는데 필요한 최소 시간을 return 하는 solution 함수를 완성해주세요.
// 만약, 탈출할 수 없다면 - 1을 return 해주세요.
//
//제한사항
//5 ≤ maps의 길이 ≤ 100
//5 ≤ maps[i]의 길이 ≤ 100
//maps[i]는 다음 5개의 문자들로만 이루어져 있습니다.
//S : 시작 지점
//E : 출구
//L : 레버
//O : 통로
//X : 벽
//시작 지점과 출구, 레버는 항상 다른 곳에 존재하며 한 개씩만 존재합니다.
//출구는 레버가 당겨지지 않아도 지나갈 수 있으며, 모든 통로, 출구, 레버, 시작점은 여러 번 지나갈 수 있습니다.



//거의 다 맞긴 했는데, 몇개의 케이스에서 틀린 경우가 나옴 (몇 군데는 아예 메모리를 벗어난 걸 보니 인덱스 초과인듯?)
#include <string>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> StartIndex;
pair<int, int> LeverIndex;
pair<int, int> DestIndex;

int solution(vector<string> maps)
{
    for (int i = 0; i < maps.size(); i++)
    {
        bool isFindStart = false;
        bool isFindLever = false;
        bool isFindDest = false;

        for (int j = 0; j < maps[i].size(); j++)
        {

            if (maps[i][j] == 'S')
            {
                StartIndex = { i, j };
                isFindStart = true;
            }
            else if (maps[i][j] == 'L')
            {
                LeverIndex = { i, j };
                isFindLever = true;
            }
            else if (maps[i][j] == 'E')
            {
                DestIndex = { i, j };
                isFindDest = true;
            }

            if (isFindStart == true && isFindLever == true && isFindDest == true)
            {
                break;
            }
        }
    }

    vector<vector<bool>> IsVisit(maps.size(), vector<bool>(maps.size(), false));
    vector<vector<int>> DistToLever(maps.size(), vector<int>(maps.size(), 0));
    vector<vector<int>> DistToDest(maps.size(), vector<int>(maps.size(), 0));

    queue<pair<int, int>> NodeCheck;
    NodeCheck.push(StartIndex);

    while (NodeCheck.size() != 0)
    {
        int x = NodeCheck.front().second;
        int y = NodeCheck.front().first;

        IsVisit[y][x] = true;

        if (x >= 1 && maps[y][x - 1] != 'X' && IsVisit[y][x - 1] != true)
        {
            DistToLever[y][x - 1] = DistToLever[y][x] + 1;
            IsVisit[y][x - 1] = true;
            NodeCheck.push({ y, x - 1 });
        }
        if (x <= maps[0].size() - 2 && maps[y][x + 1] != 'X' && IsVisit[y][x + 1] != true)
        {
            DistToLever[y][x + 1] = DistToLever[y][x] + 1;
            IsVisit[y][x + 1] = true;
            NodeCheck.push({ y, x + 1 });
        }
        if (y >= 1 && maps[y - 1][x] != 'X' && IsVisit[y - 1][x] != true)
        {
            DistToLever[y - 1][x] = DistToLever[y][x] + 1;
            IsVisit[y - 1][x] = true;
            NodeCheck.push({ y - 1, x });
        }
        if (y <= maps.size() - 2 && maps[y + 1][x] != 'X' && IsVisit[y + 1][x] != true)
        {
            DistToLever[y + 1][x] = DistToLever[y][x] + 1;
            IsVisit[y + 1][x] = true;
            NodeCheck.push({ y + 1, x });
        }

        NodeCheck.pop();
    }


    int answer = DistToLever[LeverIndex.first][LeverIndex.second];

    if (answer == 0)
    {
        return -1;
    }

    vector<vector<bool>> IsVisitToEnd(maps.size(), vector<bool>(maps.size(), false));

    NodeCheck.push(LeverIndex);

    while (NodeCheck.size() != 0)
    {
        int x = NodeCheck.front().second;
        int y = NodeCheck.front().first;

        IsVisitToEnd[y][x] = true;

        if (x >= 1 && maps[y][x - 1] != 'X' && IsVisitToEnd[y][x - 1] != true)
        {
            DistToDest[y][x - 1] = DistToDest[y][x] + 1;
            IsVisitToEnd[y][x - 1] = true;
            NodeCheck.push({ y, x - 1 });
        }
        if (x <= maps[0].size() - 2 && maps[y][x + 1] != 'X' && IsVisitToEnd[y][x + 1] != true)
        {
            DistToDest[y][x + 1] = DistToDest[y][x] + 1;
            IsVisitToEnd[y][x + 1] = true;
            NodeCheck.push({ y, x + 1 });
        }
        if (y >= 1 && maps[y - 1][x] != 'X' && IsVisitToEnd[y - 1][x] != true)
        {
            DistToDest[y - 1][x] = DistToDest[y][x] + 1;
            IsVisitToEnd[y - 1][x] = true;
            NodeCheck.push({ y - 1, x });
        }
        if (y <= maps.size() - 2 && maps[y + 1][x] != 'X' && IsVisitToEnd[y + 1][x] != true)
        {
            DistToDest[y + 1][x] = DistToDest[y][x] + 1;
            IsVisitToEnd[y + 1][x] = true;
            NodeCheck.push({ y + 1, x });
        }

        NodeCheck.pop();
    }

    if (DistToDest[DestIndex.first][DestIndex.second] == 0)
    {
        return -1;
    }

    answer += DistToDest[DestIndex.first][DestIndex.second];

    return answer;
}