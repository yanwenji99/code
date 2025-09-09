#pragma once
#include <easyx.h>
#include <list>
#include <conio.h>
#include <windows.h>
#include <chrono>
using namespace std;

// ͼƬ��С
#define BGWEIGHT 400
#define BGHEIGHT 600
// �ɻ���С
#define myBGWEIGHT 54
#define myBGHEIGHT 48
// �л���С
#define enemyBGWEIGHT 45
#define enemyBGHEIGHT 30
// �ӵ���С
#define bulBGWEIGHT 18
#define bulBGHEIGHT 24

// ͼƬ����
IMAGE img[4];

// �ɻ���
class myPlane
{
public:
    double x, y;
    double speed;
};
myPlane my;

// �ӵ���
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

// �л���
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

// ȫ�ֱ���
list<Bullet> bulletList;
list<Enemy> enemyList;
chrono::steady_clock::time_point lastBulletTime;
chrono::steady_clock::time_point lastEnemyTime;
const double bulletInterval = 0.2; // �ӵ����������룩
const double enemyInterval = 1.0;  // �л����ɼ�����룩
int score = 0;                     // �÷�

// ��ʼ������
void init()
{
    // ����ͼƬ
    loadimage(&img[0], _T("res\\����.jpg"), BGWEIGHT, BGHEIGHT);
    loadimage(&img[1], _T("res\\�ɻ�.jpg"), myBGWEIGHT, myBGHEIGHT);
    loadimage(&img[2], _T("res\\�л�.jpg"), enemyBGWEIGHT, enemyBGHEIGHT);
    loadimage(&img[3], _T("res\\�ӵ�.jpg"), bulBGWEIGHT, bulBGHEIGHT);

    my.x = BGWEIGHT / 2 - myBGWEIGHT / 2;
    my.y = BGHEIGHT - 50 - myBGHEIGHT;
    my.speed = 3.0;

    // ��ʼ��ʱ���
    lastBulletTime = chrono::steady_clock::now();
    lastEnemyTime = chrono::steady_clock::now();

    // ����б�
    bulletList.clear();
    enemyList.clear();

    // ���õ÷�
    score = 0;
}

// ���ƺ���
void drawmap()
{
    BeginBatchDraw();
    cleardevice();  // �����Ļ�������Ӱ

    // ���Ʊ���
    putimage(0, 0, &img[0]);

    // ���Ʒɻ�
    putimage(static_cast<int>(my.x), static_cast<int>(my.y), &img[1]);

    // ���������ӵ�
    for (auto& bullet : bulletList)
    {
        putimage(static_cast<int>(bullet.x), static_cast<int>(bullet.y), &img[3]);
    }

    // �������ел�
    for (auto& enemy : enemyList)
    {
        putimage(static_cast<int>(enemy.x), static_cast<int>(enemy.y), &img[2]);
    }

    // ��ʾ�÷�
    setbkmode(TRANSPARENT);
    settextcolor(BLACK);
    TCHAR scoreText[20];
    _stprintf_s(scoreText, _T("�÷�: %d"), score);
    outtextxy(10, 10, scoreText);

    // ��ʾ������ʾ
    outtextxy(10, 30, _T("WASD�ƶ�, �ո����"));
    outtextxy(10, 50, _T("��ESC�˳���Ϸ"));

    EndBatchDraw();
}

// ������� - �����ӵ�
void createBullet()
{
    Bullet bul(my.x + myBGWEIGHT / 2 - bulBGWEIGHT / 2, my.y, 10.0);
    bulletList.push_back(bul);
}

// �����ӵ�λ��
void updateBullets()
{
    auto it = bulletList.begin();
    while (it != bulletList.end())
    {
        it->y -= it->speed;

        // ����ӵ��ɳ���Ļ���Ƴ���
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

// ���ɵл�
void createEnemy()
{
    // ������ɵл�λ��
    double x = rand() % (BGWEIGHT - enemyBGWEIGHT);
    Enemy enemy(x, -enemyBGHEIGHT, 2.0 + score * 0.01);
    enemyList.push_back(enemy);
}

// ���µл�λ��
void updateEnemies()
{
    auto it = enemyList.begin();
    while (it != enemyList.end())
    {
        it->y += it->speed;

        // ����л��ɳ���Ļ���Ƴ���
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

// �����ײ
void checkCollisions()
{
    // ����ӵ��͵л�����ײ
    for (auto bulletIt = bulletList.begin(); bulletIt != bulletList.end(); )
    {
        bool bulletRemoved = false;

        for (auto enemyIt = enemyList.begin(); enemyIt != enemyList.end(); )
        {
            // �򵥵ľ�����ײ���
            if (bulletIt->x < enemyIt->x + enemyBGWEIGHT &&
                bulletIt->x + bulBGWEIGHT > enemyIt->x &&
                bulletIt->y < enemyIt->y + enemyBGHEIGHT &&
                bulletIt->y + bulBGHEIGHT > enemyIt->y)
            {
                // ��ײ�������Ƴ��л����ӵ�
                enemyIt = enemyList.erase(enemyIt);
                bulletIt = bulletList.erase(bulletIt);
                bulletRemoved = true;

                // ���ӵ÷�
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

    // ���ɻ��͵л�����ײ
    for (auto enemyIt = enemyList.begin(); enemyIt != enemyList.end(); )
    {
        if (my.x < enemyIt->x + enemyBGWEIGHT &&
            my.x + myBGWEIGHT > enemyIt->x &&
            my.y < enemyIt->y + enemyBGHEIGHT &&
            my.y + myBGHEIGHT > enemyIt->y)
        {
            // ��ײ��������Ϸ����
            MessageBox(GetHWnd(), _T("��Ϸ����!"), _T("��ʾ"), MB_OK);
            exit(0);
        }
        else
        {
            ++enemyIt;
        }
    }
}

// �ƶ�����
void move()
{
    // ʹ��GetAsyncKeyState��ⰴ��״̬����������
    if (GetAsyncKeyState('W') & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8000)
    {
        my.y -= my.speed;
        if (my.y < 0) my.y = 0;  // �ϱ߽���
    }
    if (GetAsyncKeyState('S') & 0x8000 || GetAsyncKeyState(VK_DOWN) & 0x8000)
    {
        my.y += my.speed;
        if (my.y > BGHEIGHT - myBGHEIGHT) my.y = BGHEIGHT - myBGHEIGHT;  // �±߽���
    }
    if (GetAsyncKeyState('A') & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8000)
    {
        my.x -= my.speed;
        if (my.x < 0) my.x = 0;  // ��߽���
    }
    if (GetAsyncKeyState('D') & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8000)
    {
        my.x += my.speed;
        if (my.x > BGWEIGHT - myBGWEIGHT) my.x = BGWEIGHT - myBGWEIGHT;  // �ұ߽���
    }

    // ���ո�������ӵ�
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

    // ��ʱ���ɵл�
    auto currentTime = chrono::steady_clock::now();
    double timeSinceLastEnemy = chrono::duration<double>(currentTime - lastEnemyTime).count();

    if (timeSinceLastEnemy >= enemyInterval - score * 0.0009)
    {
        createEnemy();
        lastEnemyTime = currentTime;
    }
}

// ���ô��ڽ���
void setupWindowFocus(HWND hwnd)
{
    SetForegroundWindow(hwnd);
    SetFocus(hwnd);
}

// ��Ϸ��ѭ��
void start()
{
    initgraph(BGWEIGHT, BGHEIGHT);
    init();

    // ��ȡ���ھ�������ý���
    HWND hwnd = GetHWnd();
    setupWindowFocus(hwnd);

    // ��Ϸ��ѭ��
    while (true)
    {
        // ���ESC���˳�
        if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
            break;

        // �������ʧȥ���㣬�������»�ȡ
        if (GetForegroundWindow() != hwnd)
        {
            setupWindowFocus(hwnd);
        }

        move();              // �����ƶ�������
        updateBullets();     // �����ӵ�λ��
        updateEnemies();     // ���µл�λ��
        checkCollisions();   // �����ײ
        drawmap();           // ���ƻ���

        Sleep(10);           // ������Ϸ�ٶ�
        if (score == 1000)
        {
            settextcolor(RED);
            setbkcolor(RGB(135, 206, 250)); // ����ɫ����
            cleardevice(); // �ñ���ɫ�����Ļ
            settextstyle(70, 50,_T("����"));
            outtextxy(165, 300, "WIN");
            getchar();
            break;
        }
    }
    closegraph();
}
