#include <string>
#include <vector>
#include <cmath>

using namespace std;

//소수를 걸러낼 때에는 에라토스테네스의 체를 이용하자. 걸리는 시간이 진짜 말이 안되게 줄어드네;;
int solution(int n)
{
    int answer = 0;

    int* arr = new int[n+1];

    //모든 배열을 초기화 (bool을 이용해도 됨)
    for (int i = 2; i <= n; i++)
    {
        arr[i] = i;
    }
    
    //이후 2부터 최대숫자의 제곱근까지, 각 수의 배수를 모두 제거한다.
    for (int i = 2; i <= sqrt(n); i++)
    {
        for (int j = 2 * i; j <= n; j += i)
        {
            arr[j] = 0;
        }
    }
    
    //남아있는 수가 소수이므로, 결과값에 넣으면 됨.
    for (int i = 2; i <= n; i++)
    {
        if (arr[i] != 0)
        {
            answer++;
        }
    }

    return answer;
}