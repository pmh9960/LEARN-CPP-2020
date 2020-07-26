#include <iostream>
using namespace std;

int main()
{
    int max_num = 0, cur = 0;
    int input[10], output[10];
    for (int i = 0; i < 10; i++)
    {
        cin >> output[i] >> input[i];
        cur -= output[i];
        cur += input[i];
        if (cur > max_num)
        {
            max_num = cur;
        }
    }
    cout << max_num;

    return 0;
}