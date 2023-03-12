#include <string>
#include <vector>
#include <cmath>

using namespace std;

//�Ҽ��� �ɷ��� ������ �����佺�׳׽��� ü�� �̿�����. �ɸ��� �ð��� ��¥ ���� �ȵǰ� �پ���;;
int solution(int n)
{
    int answer = 0;

    int* arr = new int[n+1];

    //��� �迭�� �ʱ�ȭ (bool�� �̿��ص� ��)
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }
    
    //���� 2���� �ִ������ �����ٱ���, �� ���� ����� ��� �����Ѵ�.
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }
    
    //�����ִ� ���� �Ҽ��̹Ƿ�, ������� ������ ��.
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] != 0)
        {
            answer++;
        }
    }

    return answer;
}