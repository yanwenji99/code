#include<bits/stdc++.h>
// #include <fstream>运用fstream读写文件
using namespace std;
int main()
{
    // 读文件

    // 创建输入文件流对象
    ifstream ifs;
    // 打开文件
    ifs.open("input.txt", ios::in);
    // 检查文件是否成功打开
    if(!ifs.is_open())
    {
        cout<<"error: file not found!"<<endl;
        return 1; // 返回错误码
    }
    // 读取文件

    // 方法1
    // char buf[1024] = {0};
    // while(ifs>>buf)
    // {
    //     cout << buf << endl;
    // }

    // 方法2
    // char buf[1024] = {0};
    // while(ifs.getline(buf, sizeof(buf)))
    // {
    //     cout << buf << endl;
    // }

    // 方法3
    string line;
    while(getline(ifs, line))
    {
        cout << line << endl;
    }

    // 方法4
    // char c;
    // while((c=ifs.get()) != EOF)
    // {
    //     cout << c;
    // }
    
    // 关闭文件
    ifs.close();

    // 写文件

    // 创建输出文件流对象
    ofstream ofs;
    // 打开文件
    ofs.open("output.txt",ios::out);
    // 检查文件是否成功打开
    if(!ofs.is_open())
    {
        cout<<"error: file not found!"<<endl;
        return 1; // 返回错误码
    }
    // 打开方式
    // ios::in     表示输入文件流
    // ios::out    表示输出文件流
    // ios::ate    表示打开文件并将文件指针移动到文件末尾
    // ios::app    表示追加到文件末尾
    // ios::trunc  表示清空文件内容
    // ios::binary 表示以二进制方式打开文件

    // 写入文件
    ofs << "Hello, World!" << endl;
    // 关闭文件
    ofs.close();
    return 0;
}