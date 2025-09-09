#pragma once
#include <easyx.h>
#include <list>
#include <conio.h>
#include <windows.h>
#include <chrono>
using namespace std;

// 图片大小
#define BGWEIGHT 400
#define BGHEIGHT 600
// 飞机大小
#define myBGWEIGHT 54
#define myBGHEIGHT 48
// 敌机大小
#define enemyBGWEIGHT 45
#define enemyBGHEIGHT 30
// 子弹大小
#define bulBGWEIGHT 18
#define bulBGHEIGHT 24

// 图片数组
IMAGE img[4];

// 飞机类
class myPlane
{
public:
    double x, y;
    double speed;
};
myPlane my;

// 子弹类
class Bullet
{
public:
    Bullet(double x, double y, double speed)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
    double x, y;
    double speed;
};

// 敌机类
class Enemy
{
public:
    Enemy(double x, double y, double speed)
    {
        this->x = x;
        this->y = y;
        this->speed = speed;
    }
    double x, y;
    double speed;
};

// 全局变量
list<Bullet> bulletList;
list<Enemy> enemyList;
chrono::steady_clock::time_point lastBulletTime;
chrono::steady_clock::time_point lastEnemyTime;
const double bulletInterval = 0.2; // 子弹发射间隔（秒）
const double enemyInterval = 1.0;  // 敌机生成间隔（秒）
int score = 0;                     // 得分

// 初始化函数
void init()
{
    // 加载图片
    loadimage(&img[0], _T("res\\背景.jpg"), BGWEIGHT, BGHEIGHT);
    loadimage(&img[1], _T("res\\飞机.jpg"), myBGWEIGHT, myBGHEIGHT);
    loadimage(&img[2], _T("res\\敌机.jpg"), enemyBGWEIGHT, enemyBGHEIGHT);
    loadimage(&img[3], _T("res\\子弹.jpg"), bulBGWEIGHT, bulBGHEIGHT);

    my.x = BGWEIGHT / 2 - myBGWEIGHT / 2;
    my.y = BGHEIGHT - 50 - myBGHEIGHT;
    my.speed = 3.0;

    // 初始化时间点
    lastBulletTime = chrono::steady_clock::now();
    lastEnemyTime = chrono::steady_clock::now();

    // 清空列表
    bulletList.clear();
    enemyList.clear();

    // 重置得分
    score = 0;
}

// 绘制函数
void drawmap()
{
    BeginBatchDraw();
    cleardevice();  // 清空屏幕，避免残影

    // 绘制背景
    putimage(0, 0, &img[0]);

    // 绘制飞机
    putimage(static_cast<int>(my.x), static_cast<int>(my.y), &img[1]);

    // 绘制所有子弹
    for (auto& bullet : bulletList)
    {
        putimage(static_cast<int>(bullet.x), static_cast<int>(bullet.y), &img[3]);
    }

    // 绘制所有敌机
    for (auto& enemy : enemyList)
    {
        putimage(static_cast<int>(enemy.x), static_cast<int>(enemy.y), &img[2]);
    }

    // 显示得分
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    TCHAR scoreText[20];
    _stprintf_s(scoreText, _T("得分: %d"), score);
    outtextxy(10, 10, scoreText);

    // 显示操作提示
    outtextxy(10, 30, _T("WASD移动, 空格射击"));
    outtextxy(10, 50, _T("按ESC退出游戏"));

    EndBatchDraw();
}

// 射击函数 - 创建子弹
void createBullet()
{
    Bullet bul(my.x + myBGWEIGHT / 2 - bulBGWEIGHT / 2, my.y, 10.0);
    bulletList.push_back(bul);
}

// 更新子弹位置
void updateBullets()
{
    auto it = bulletList.begin();
    while (it != bulletList.end())
    {
        it->y -= it->speed;

        // 如果子弹飞出屏幕，移除它
        if (it->y < -bulBGHEIGHT)
        {
            it = bulletList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// 生成敌机
void createEnemy()
{
    // 随机生成敌机位置
    double x = rand() % (BGWEIGHT - enemyBGWEIGHT);
    Enemy enemy(x, -enemyBGHEIGHT, 2.0 + score * 0.01);
    enemyList.push_back(enemy);
}

// 更新敌机位置
void updateEnemies()
{
    auto it = enemyList.begin();
    while (it != enemyList.end())
    {
        it->y += it->speed;

        // 如果敌机飞出屏幕，移除它
        if (it->y > BGHEIGHT)
        {
            it = enemyList.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

// 检测碰撞
void checkCollisions()
{
    // 检测子弹和敌机的碰撞
    for (auto bulletIt = bulletList.begin(); bulletIt != bulletList.end(); )
    {
        bool bulletRemoved = false;

        for (auto enemyIt = enemyList.begin(); enemyIt != enemyList.end(); )
        {
            // 简单的矩形碰撞检测
            if (bulletIt->x < enemyIt->x + enemyBGWEIGHT &&
                bulletIt->x + bulBGWEIGHT > enemyIt->x &&
                bulletIt->y < enemyIt->y + enemyBGHEIGHT &&
                bulletIt->y + bulBGHEIGHT > enemyIt->y)
            {
                // 碰撞发生，移除敌机和子弹
                enemyIt = enemyList.erase(enemyIt);
                bulletIt = bulletList.erase(bulletIt);
                bulletRemoved = true;

                // 增加得分
                score += 10;

                break;
            }
            else
            {
                ++enemyIt;
            }
        }

        if (!bulletRemoved)
        {
            ++bulletIt;
        }
    }

    // 检测飞机和敌机的碰撞
    for (auto enemyIt = enemyList.begin(); enemyIt != enemyList.end(); )
    {
        if (my.x < enemyIt->x + enemyBGWEIGHT &&
            my.x + myBGWEIGHT > enemyIt->x &&
            my.y < enemyIt->y + enemyBGHEIGHT &&
            my.y + myBGHEIGHT > enemyIt->y)
        {
            // 碰撞发生，游戏结束
            MessageBox(GetHWnd(), _T("游戏结束!"), _T("提示"), MB_OK);
            exit(0);
        }
        else
        {
            ++enemyIt;
        }
    }
}

// 移动函数
void move()
{
    // 使用GetAsyncKeyState检测按键状态，避免阻塞
    if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)
    {
        my.y -= my.speed;
        if (my.y < 0) my.y = 0;  // 上边界检查
    }
    if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        my.y += my.speed;
        if (my.y > BGHEIGHT - myBGHEIGHT) my.y = BGHEIGHT - myBGHEIGHT;  // 下边界检查
    }
    if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        my.x -= my.speed;
        if (my.x < 0) my.x = 0;  // 左边界检查
    }
    if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        my.x += my.speed;
        if (my.x > BGWEIGHT - myBGWEIGHT) my.x = BGWEIGHT - myBGWEIGHT;  // 右边界检查
    }

    // 检测空格键发射子弹
    if (GetAsyncKeyState(VK_SPACE) & 0x8000)
    {
        auto currentTime = chrono::steady_clock::now();
        double timeSinceLastBullet = chrono::duration<double>(currentTime - lastBulletTime).count();

        if (timeSinceLastBullet >= bulletInterval)
        {
            createBullet();
            lastBulletTime = currentTime;
        }
    }

    // 定时生成敌机
    auto currentTime = chrono::steady_clock::now();
    double timeSinceLastEnemy = chrono::duration<double>(currentTime - lastEnemyTime).count();

    if (timeSinceLastEnemy >= enemyInterval - score * 0.0009)
    {
        createEnemy();
        lastEnemyTime = currentTime;
    }
}

// 设置窗口焦点
void setupWindowFocus(HWND hwnd)
{
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);
}

// 游戏主循环
void start()
{
    initgraph(BGWEIGHT, BGHEIGHT);
    init();

    // 获取窗口句柄并设置焦点
    HWND hwnd = GetHWnd();
    setupWindowFocus(hwnd);

    // 游戏主循环
    while (true)
    {
        // 检测ESC键退出
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        // 如果窗口失去焦点，尝试重新获取
        if (GetForegroundWindow() != hwnd)
        {
            setupWindowFocus(hwnd);
        }

        move();              // 处理移动和输入
        updateBullets();     // 更新子弹位置
        updateEnemies();     // 更新敌机位置
        checkCollisions();   // 检测碰撞
        drawmap();           // 绘制画面

        Sleep(10);           // 控制游戏速度
        if (score == 1000)
        {
            settextcolor(RED);
            setbkcolor(RGB(135, 206, 250)); // 天蓝色背景
            cleardevice(); // 用背景色清空屏幕
            settextstyle(70, 50,_T("黑体"));
            outtextxy(165, 300, "WIN");
            getchar();
            break;
        }
    }
    closegraph();
}
