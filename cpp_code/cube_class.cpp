#include <iostream>
using namespace std;

class Cube
{
public:
    // 构造函数
    
    Cube() : m_length(0), m_width(0), m_height(0) {} // 冒号 : 表示后面跟随的是成员初始化列表，用于在构造函数体执行前初始化成员变量。默认构造函数，初始化成员变量为0

    Cube(int length, int width, int height)
        : m_length(length), m_width(width), m_height(height) {}
    // 此处为函数重载

    // 析构函数 ~Cube() {} 无参数且无需手动调用

    int getVolume()
    {
        return m_length * m_width * m_height;
    }

    int getSurfaceArea()
    {
        return 2 * (m_length * m_width + m_width * m_height + m_height * m_length);
    }

    void setLength(int length) { m_length = length; }
    void setWidth(int width) { m_width = width; }
    void setHeight(int height) { m_height = height; }

    int getLength() { return m_length; }
    int getWidth() { return m_width; }
    int getHeight() { return m_height; }

private:
    int m_length;
    int m_width;
    int m_height;
};

int main()
{
    Cube cube(3, 4, 5); // 使用带参构造函数直接初始化
    cout << "Volume: " << cube.getVolume() << endl;
    cout << "Surface Area: " << cube.getSurfaceArea() << endl;
    return 0;
}