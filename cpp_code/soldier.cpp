// 回溯枚举，暴力求解，直观但是容易TLE
// #include<bits/stdc++.h>
// using namespace std;
// int way = 0;
// int chessboard[20][20];
// bool check(int bx,int by,int x,int y,int chess[][20])
// {
//     if(x>bx || y>by || x<0 || y<0)
//         return false;
//     return chess[x][y] == 0;
// }
// void soldier(int bx,int by,int chess[][20])
// {
//     static int x = 0, y = 0;

//     if(x==bx&&y==by)
//     {
//         way++;
//         return;
//     }
//     else
//     {
//         if(check(bx,by,x + 1, y,chess))
//         {
//             x++;
//             soldier(bx, by, chess);
//             x--;
//         }
//         if(check(bx,by,x, y + 1,chess))
//         {
//             y++;
//             soldier(bx, by, chess);
//             y--;
//         }
//     }
// } // 回溯枚举，暴力求解，直观但是容易TLE
// int main()
// {
// int x, y; // 棋盘边界
// cin >> x >> y;
// for (int i = 0; i <= 20; i++)
// {
//     for (int j = 0; j <= 20; j++)
//     {
//         chessboard[i][j] = 0;
//     }
// }
// int mx, my; // 马的位置
// cin >> mx >> my;
//     control(x, y, mx, my);
//     soldier(x, y,chessboard);
//     cout << way << endl;
// }

// 动态规划，快速但需满足重叠的子问题
#include<bits/stdc++.h>
using namespace std;
int chessboard[21][21];
void control(int bx, int by, int x, int y)
{
    chessboard[x][y] = 1;
    if (x - 2 >= 0 && y - 1 >= 0)
        chessboard[x - 2][y - 1] = 1;
    if (x - 1 >= 0 && y - 2 >= 0)
        chessboard[x - 1][y - 2] = 1;
    if (x + 2 >= 0 && y - 1 >= 0)
        chessboard[x + 2][y - 1] = 1;
    if (x + 2 >= 0 && y + 1 >= 0)
        chessboard[x + 2][y + 1] = 1;
    if (x + 1 >= 0 && y + 2 >= 0)
        chessboard[x + 1][y + 2] = 1;
    if (x - 2 >= 0 && y + 1 >= 0)
        chessboard[x - 2][y + 1] = 1;
    if (x + 1 >= 0 && y - 2 >= 0)
        chessboard[x + 1][y - 2] = 1;
    if (x - 1 >= 0 && y + 2 >= 0)
        chessboard[x - 1][y + 2] = 1;
}
long long soldier(int x,int y)
{
    long long dp[21][21] = {0};
    dp[0][0] = chessboard[0][0] ? 0 : 1;
    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            if (chessboard[i][j] == 0)
            {
                if (i > 0)
                    dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
            else
            {
                dp[i][j] = 0; // 如果当前位置被马攻击，则不能到达
            }
        }
    }
    return dp[x][y];
}
int main()
{
    int x, y; // 棋盘边界
    cin >> x >> y;
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            chessboard[i][j] = 0;
        }
    }
    int mx, my; // 马的位置
    cin >> mx >> my;
    control(x, y, mx, my);
    cout << soldier(x, y) << endl;
}