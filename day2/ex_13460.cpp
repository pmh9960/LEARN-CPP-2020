#include <iostream>
#include <queue>
using namespace std;

// '.', '#', 'O', 'R', 'B' 로 이루어져 있다.
// '.'은 빈 칸을 의미하고,
// '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며,
// 'O'는 구멍의 위치를 의미한다.
// 'R'은 빨간 구슬의 위치,
// 'B'는 파란 구슬의 위치이다.

int main()
{
    int n, m;
    char arr[10][10];
    queue<int> RQx, RQy, BQx, BQy;

    // Input n, m, GRID
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'R')
            {
                RQx.push(i);
                RQy.push(j);
                arr[i][j] = '.';
            }
            else if (arr[i][j] == 'B')
            {
                BQx.push(i);
                BQy.push(j);
                arr[i][j] = '.';
            }
        }
    }

    int mx[4] = {0, 1, 0, -1}, my[4] = {1, 0, -1, 0}; // right, down, left, up

    for (int cnt = 0; cnt < 10; cnt++)
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int Rx = RQx.front(), Ry = RQy.front(), Bx = BQx.front(), By = BQy.front();

            int isMoveR = 1;
            int isMoveB = 1;
            while (isMoveR || isMoveB)
            {
                isMoveR = 0;
                isMoveB = 0;
                while (1)
                {
                    int nextRx = Rx + mx[dir], nextRy = Ry + my[dir];
                    if (arr[nextRx][nextRy] == '#' || (nextRx == Bx && nextRy == By))
                    {
                        break;
                    }
                    Rx = nextRx;
                    Ry = nextRy;
                    isMoveR = 1;
                }
                while (1)
                {
                    int nextBx = Bx + mx[dir], nextBy = By + my[dir];
                    if (arr[nextBx][nextBy] == '#' || (nextBx == Rx && nextBy == Ry))
                    {
                        break;
                    }
                    Bx = nextBx;
                    By = nextBy;
                    isMoveB = 1;
                }
            }

            RQx.push(Rx);
            RQy.push(Ry);
            BQx.push(Bx);
            BQy.push(By);
            cout << Rx << " " << Ry << endl
                 << Bx << " " << By << endl
                 << endl;
        }
        RQx.pop();
        RQy.pop();
        BQx.pop();
        BQy.pop();
        break;
    }

    system("pause");

    return 0;
}