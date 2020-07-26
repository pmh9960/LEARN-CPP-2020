#include <iostream>
using namespace std;

int main()
{
    char str[10];
    cin.getline(str, sizeof(str));
    char a[5], b[5];
    a[2] = str[0];
    a[1] = str[1];
    a[0] = str[2];

    b[2] = str[4];
    b[1] = str[5];
    b[0] = str[6];

    int x = 0, y = 0;
    x = (a[0] - '0') * 100 + (a[1] - '0') * 10 + (a[2] - '0');
    y = (b[0] - '0') * 100 + (b[1] - '0') * 10 + (b[2] - '0');

    if (x > y)
    {
        cout << x;
    }
    else
    {
        cout << y;
    }

    return 0;
}