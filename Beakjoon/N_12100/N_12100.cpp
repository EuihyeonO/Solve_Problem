#include <iostream>

void MoveUp(int** Map, int Map_size)
{
	//여러번 시뮬레이션 해야하기 때문에, Map을 원본배열을 사용하지 말고, 함수내에서 값을 복사한 뒤 따로 함수를 실행한 뒤 Map 값만 return해야한다.

	for(int count = 0; count<Map_size; count++)
	{
		for (int j = 1; j < Map_size; j++)
		{
			for (int i = 0; i < Map_size; i++)
			{
				if (Map[j - 1][i] == 0 || Map[j][i] == Map[j - 1][i])
				{
					Map[j - 1][i] += Map[j][i];
					Map[j][i] = 0;
				}
				else
				{
					continue;
				}
			}
		}
	}
}

int main()
{
	int Map_size = 0;
	scanf_s("%d", &Map_size);

	int** Map = new int*[Map_size];

	for (int i = 0; i < Map_size; i++)
	{
		Map[i] = new int[Map_size];
	}

	for (int j = 0; j < Map_size; j++)
	{
		for (int i = 0; i < Map_size; i++)
		{
			scanf_s("%d", &Map[j][i]);
		}
	}

	MoveUp(Map, Map_size);

	//테스트출력
	for (int j = 0; j < Map_size; j++)
	{
		for (int i = 0; i < Map_size; i++)
		{
			printf_s("%d ", Map[j][i]);
		}
	}
}