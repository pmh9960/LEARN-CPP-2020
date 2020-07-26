#include <iostream>

extern int add(int, int);

using namespace std;

int main()
{
    int a, b;
    cout << "hello" << endl;
    cin >> a >> b;
    cout << add(a, b);

    return 0;
}