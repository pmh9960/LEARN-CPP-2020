#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int T;
    int a[100'000], b[100'000];
    int cur, end;
    int seq[1000];

    int last;

    scanf("%d", &T);
    // T = 1;

    // while (1)
    // {
    for (int t = 0; t < T; t++)
    {
        scanf("%d %d", &a[t], &b[t]);
    }
    for (int t = 0; t < T; t++)
    {
        if (b[t] >= 2 || a[t] * pow(10, b[t]) >= 21)
        {
            if (a[t] * pow(10, b[t]) < 0)
            {
                cout << "1-3-5-7-9-12-15-1...";
            }
            else
            {
                end = a[t] * pow(10, b[t]);
                cur = 0;
                while (end > 0)
                {
                    if (end < 20)
                    {
                        seq[cur] = end;
                        cur++;
                    }
                    int len = 0;
                    int temp = end;
                    while (temp > 0)
                    {
                        temp /= 10;
                        len++;
                    }
                    end -= len + 1;
                }
                if (seq[0] == 18)
                {
                    cout << "1-3-5-7-9-12-15-1...";
                }
                else if (seq[0] == 19)
                {
                    cout << "1-3-5-7-10-13-16-...";
                }
                else
                {
                    cout << "-2-4-6-8-11-14-17...";
                }
            }
        }
        else
        {
            end = a[t] * pow(10, b[t]);
            cur = 0;
            while (end > 0)
            {
                if (end < 20)
                {
                    seq[cur] = end;
                    cur++;
                }
                int len = 0;
                int temp = end;
                while (temp > 0)
                {
                    temp /= 10;
                    len++;
                }
                end -= len + 1;
            }
            if (seq[cur - 1] == 1)
            {
                for (int i = cur - 1; i > 0; i--)
                {
                    cout << seq[i] << "-";
                }
                cout << seq[0];
            }
            else
            {
                for (int i = cur - 1; i >= 0; i--)
                {
                    cout << "-" << seq[i];
                }
            }
        }
        cout << endl;
    }
    // }

    // system("pause");
    return 0;
}