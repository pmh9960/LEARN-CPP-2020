#include <iostream>

using namespace std;

// String I/O
int main()
{
    char id[30];
    // 공백을 포함한 문자열
    // Input string which include space
    cin.getline(id, sizeof(id));
    cout << id;

    return 0;
}