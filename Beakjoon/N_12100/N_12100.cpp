#include <iostream>

void MoveUp(int** Map, int Map_size)
{
	//������ �ùķ��̼� �ؾ��ϱ� ������, Map�� �����迭�� ������� ����, �Լ������� ���� ������ �� ���� �Լ��� ������ �� Map ���� return�ؾ��Ѵ�.

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

	//�׽�Ʈ���
	for (int j = 0; j < Map_size; j++)
	{
		for (int i = 0; i < Map_size; i++)
		{
			printf_s("%d ", Map[j][i]);
		}
	}
}