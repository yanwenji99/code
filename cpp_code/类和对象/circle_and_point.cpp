#include<bits/stdc++.h>
using namespace std;
class Point
{
public:
    Point() : m_x(0), m_y(0) {}
    Point(int x, int y) : m_x(x), m_y(y) {}
    void setx(int x)
    {
        m_x = x;
    }
    void sety(int y)
    {
        m_y = y;
    }
    int getx()
    {
        return m_x;
    }
    int gety()
    {
        return m_y;
    }
private:
    double m_x;
    double m_y;
};
class Circle
{
public:
    Circle() : m_R(0), m_Center(0,0) {}
    Circle(int R,Point Center) : m_R(R), m_Center(Center) {}
    void setR(int R)
    {
        m_R = R;
    }
    void setCenter(Point Center)
    {
        m_Center = Center;
    }
    int getR()
    {
        return m_R;
    }
    Point getCenter()
    {
        return m_Center;
    }
private:
    int m_R;
    Point m_Center;
};
void isinCircle(Circle c,Point p)
{
    double distance = sqrt(pow((c.getCenter().getx() - p.getx()), 2) + pow((c.getCenter().gety() - p.gety()), 2));
    if (distance < c.getR())
        cout << "Point is inside the circle" << endl;
    else if (distance == c.getR())
        cout << "Point is on the circle" << endl;
    else
        cout << "Point is outside the circle" << endl;
}
int main()
{
    Point p(1,1), Center(0,0);
    Circle c(1, Center);
    isinCircle(c, p);
    return 0;
}