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
    queue<int> RQx, RQy, BQx, BQy, cntQ;

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
    int isGoalR = 0, isGoalB = 0;
    cntQ.push(0);

    while (!cntQ.empty())
    {
        for (int dir = 0; dir < 4; dir++)
        {
            int Rx = RQx.front(), Ry = RQy.front(), Bx = BQx.front(), By = BQy.front(), cnt = cntQ.front();

            if (arr[Rx][Ry] != 'O')
            {
                isGoalR = 0;
            }
            else
            {
                isGoalR = 1;
            }
            if (arr[Bx][By] != 'O')
            {
                isGoalB = 0;
            }
            else
            {
                isGoalB = 1;
            }

            int isMoveR = 1;
            int isMoveB = 1;
            while (isMoveR || isMoveB)
            {
                isMoveR = 0;
                isMoveB = 0;
                while (!isGoalR)
                {
                    int nextRx = Rx + mx[dir], nextRy = Ry + my[dir];

                    if (arr[nextRx][nextRy] == 'O')
                    {
                        isGoalR = 1;
                        Rx = nextRx;
                        Ry = nextRy;
                        isMoveR = 1;
                        break;
                    }
                    else if (arr[nextRx][nextRy] == '#' || (nextRx == Bx && nextRy == By))
                    {
                        break;
                    }
                    Rx = nextRx;
                    Ry = nextRy;
                    isMoveR = 1;
                }
                while (!isGoalB)
                {
                    int nextBx = Bx + mx[dir], nextBy = By + my[dir];

                    if (arr[nextBx][nextBy] == 'O')
                    {
                        isGoalB = 1;
                        Bx = nextBx;
                        By = nextBy;
                        isMoveB = 1;
                        break;
                    }
                    else if (arr[nextBx][nextBy] == '#' || (nextBx == Rx && nextBy == Ry))
                    {
                        break;
                    }
                    Bx = nextBx;
                    By = nextBy;
                    isMoveB = 1;
                }
            }

            if (isGoalB)
            {
                // Fail
                continue;
            }
            else if (isGoalR)
            {
                // Success
                std::cout << cnt + 1 << endl;

                // system("pause");
                return 0;
            }
            else if (cnt == 9)
            {
                // Fail
                continue;
            }

            RQx.push(Rx);
            RQy.push(Ry);
            BQx.push(Bx);
            BQy.push(By);
            cntQ.push(cnt + 1);
            // cout << Rx << " " << Ry << endl
            //      << Bx << " " << By << endl
            //      << cnt << endl;
        }

        RQx.pop();
        RQy.pop();
        BQx.pop();
        BQy.pop();
        cntQ.pop();
    }

    std::cout << -1 << endl;

    // system("pause");

    return 0;
}