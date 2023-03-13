//1 x 1 ũ���� ĭ��� �̷���� ���簢�� ���� ������ �̷ο��� Ż���Ϸ��� �մϴ�.�� ĭ�� ��� �Ǵ� ������ �����Ǿ� ������, 
// ������ �� ĭ�� ������ �� ���� ��η� �� ĭ���θ� �̵��� �� �ֽ��ϴ�.��ε� �� �� ĭ���� �̷θ� ���������� ���� �ִµ�, 
// �� ���� ������ ��ܼ��� �� �� �ֽ��ϴ�.���� ���� ��ε� �� �� ĭ�� �ֽ��ϴ�.
// ����, ��� �������� ���� ������ �ִ� ĭ���� �̵��Ͽ� ������ ��� �� �̷θ� ���������� ���� �ִ� ĭ���� �̵��ϸ� �˴ϴ�.
// �̶� ���� ������ ����� �ʾҴ��� �ⱸ�� �ִ� ĭ�� ������ �� �ֽ��ϴ�.
// �̷ο��� �� ĭ�� �̵��ϴµ� 1�ʰ� �ɸ��ٰ� �� ��, �ִ��� ������ �̷θ� ���������µ� �ɸ��� �ð��� ���Ϸ� �մϴ�.
//
//�̷θ� ��Ÿ�� ���ڿ� �迭 maps�� �Ű������� �־��� ��, �̷θ� Ż���ϴµ� �ʿ��� �ּ� �ð��� return �ϴ� solution �Լ��� �ϼ����ּ���.
// ����, Ż���� �� ���ٸ� - 1�� return ���ּ���.
//
//���ѻ���
//5 �� maps�� ���� �� 100
//5 �� maps[i]�� ���� �� 100
//maps[i]�� ���� 5���� ���ڵ�θ� �̷���� �ֽ��ϴ�.
//S : ���� ����
//E : �ⱸ
//L : ����
//O : ���
//X : ��
//���� ������ �ⱸ, ������ �׻� �ٸ� ���� �����ϸ� �� ������ �����մϴ�.
//�ⱸ�� ������ ������� �ʾƵ� ������ �� ������, ��� ���, �ⱸ, ����, �������� ���� �� ������ �� �ֽ��ϴ�.



//���� �� �±� �ߴµ�, ��� ���̽����� Ʋ�� ��찡 ���� (�� ������ �ƿ� �޸𸮸� ��� �� ���� �ε��� �ʰ��ε�?)
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