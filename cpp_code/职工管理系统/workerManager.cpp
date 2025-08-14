#include"workerManager.h"

WorkerManager::WorkerManager()
{
    // 文件不存在
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->m_Empnum = 0;
        this->m_Emparr = NULL;
        this->m_fileempty = true;
        ifs.close();
        return;
    }
    // 文件为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        this->m_Empnum = 0;
        this->m_Emparr = NULL;
        this->m_fileempty = true;
        ifs.close();
        return;
    }
    // 文件不为空
    int num = this->getnum();
    cout << "职工人数为：" << num << endl;
    this->m_Empnum = num;

    this->m_Emparr = new Worker * [this->m_Empnum];
    this->init_emp();

 }
WorkerManager::~WorkerManager()
{
    if (this->m_Emparr != NULL)
    {
        delete[] this->m_Emparr;
        this->m_Emparr = NULL;
    }
}
void WorkerManager::Shoe_Menu()
{
    cout << "欢迎使用职工管理系统" << endl;
    cout << "0: 退出" << endl;
    cout << "1: 添加职工信息" << endl;
    cout << "2: 展示职工信息" << endl;
    cout << "3: 删除职工信息" << endl;
    cout << "4: 修改职工信息" << endl;
    cout << "5: 查找职工信息" << endl;
    cout << "6: 职工信息排序" << endl;
    cout << "7: 清空职工信息" << endl;
    cout << endl;
}
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
void WorkerManager::add_emp()
{
    cout << "请输入添加职工人数：";
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        int newsize = this->m_Empnum + addNum;
        Worker** newspace= new Worker * [newsize];
        if (this->m_Emparr != NULL)
        {
            for (int i = 0; i < this->m_Empnum; i++)
            {
                newspace[i] = this->m_Emparr[i];
            }
        }
        for (int i = 0; i < addNum; i++)
        {
            int ID;
            string name;
            int depart;
            cout << "录入第" << i + 1 << " 个职工信息" << endl;
            cout << "职工编号：" ;
            while (true)
            {
                cin >> ID;
                int is = this->IDexit(ID);
                if (is != -1)
                {
                    cout << "此编号已经存在，请重新输入：";
                }
                else
                    break;
            }
            cout << "职工姓名：";
            cin >> name;
            cout << "职位编号： 1、职工  2、经理  3、Boss"<<endl;
            cin >> depart;
            Worker* worker = NULL;
            switch (depart)
            {
            case 1:
                worker = new Employee(ID, name, 1);
                break;
            case 2:
                worker = new Manager(ID, name, 2);
                break;
            case 3:
                worker = new Boss(ID, name, 3);
                break;
            default:
                break;
            }
            newspace[this->m_Empnum + i] = worker;
        }
        delete[] this->m_Emparr;
        this->m_Emparr = newspace;
        this->m_Empnum = newsize;
        this->m_fileempty = false;
        cout << "添加成功" << endl;

        this->save();
    }
    else
        cout << "输入有误" << endl;
}
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_Empnum; i++)
    {
        ofs << this->m_Emparr[i]->m_ID << " " << this->m_Emparr[i]->m_name << " " << this->m_Emparr[i]->m_department << endl;
    }
    ofs.close();
}
int WorkerManager::getnum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;
    string name;
    int depart;
    int num = 0;
    while (ifs >> ID && ifs >> name && ifs >> depart)
    {
        num++;
    }
    ifs.close();
    return num;
}
void WorkerManager::init_emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int ID;
    string name;
    int depart;
    int index = 0;
    while (ifs >> ID && ifs >> name && ifs >> depart)
    {
        Worker* worker=NULL;
        if (depart == 1)
        {
            worker = new Employee(ID, name, depart);
        }
        else if (depart == 2)
        {
            worker = new Manager(ID, name, depart);
        }
        else if (depart == 3)
        {
            worker = new Boss(ID, name, depart);
        }
        this->m_Emparr[index] = worker;
        index++;
    }
    ifs.close();

}
void WorkerManager::show_emp()
{
    if (this->m_fileempty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Empnum; i++)
        {
            this->m_Emparr[i]->showinfo();
        }
    }
}
int WorkerManager::IDexit(int ID)
{
    int index = -1;
    for (int i = 0; i < this->m_Empnum; i++)
    {
        if (this->m_Emparr[i]->m_ID == ID)
        {
            index = i;
            break;
        }
    }
    return index;
}
void WorkerManager::del_emp()
{
    if (this->m_fileempty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请输入要删除的职工编号：";
        int id;
        cin >> id;
        int index = this->IDexit(id);
        if (index == -1)
        {
            cout << "此职工编号不存在！"<<endl;
        }
        else
        {
            for (int i = index; i < this->m_Empnum - 1; i++)
            {
                this->m_Emparr[i] = this->m_Emparr[i + 1];
            }
            this->m_Empnum--;
            this->save();
            cout << "删除成功" << endl;
        }
    }
}
void WorkerManager::mod_emp()
{
    if (this->m_fileempty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请输入要修改的职工编号:";
        int id;
        cin >> id;
        int index = this->IDexit(id);
        if (index == -1)
        {
            cout << "此职工编号不存在！" << endl;
        }
        else
        {
            cout << "查找的职工信息" << endl;
            this->m_Emparr[index]->showinfo();
            cout << "请输入修改后的信息:"<<endl;
            int ID;
            string name;
            int depart;
            cout << "职工编号：";
            cin >> ID;
            cout << "职工姓名：";
            cin >> name;
            cout << "职位编号： 1、职工  2、经理  3、Boss" << endl;
            cin >> depart;
            Worker* worker = NULL;
            switch (depart)
            {
            case 1:
                worker = new Employee(ID, name, 1);
                break;
            case 2:
                worker = new Manager(ID, name, 2);
                break;
            case 3:
                worker = new Boss(ID, name, 3);
                break;
            default:
                break;
            }
            this->m_Emparr[index] = worker;
            cout << "修改成功" << endl;
            this->save();
        }
    }
}
void WorkerManager::find_emp()
{
    if (this->m_fileempty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请选择查找方式：" << endl;
        cout << "1.使用编号查找" << endl;
        cout << "2.使用姓名查找" << endl;
        int way;
        cin >> way;
        if (way == 1)
        {
            cout << "请输入要查找的编号：";
            int id;
            cin >> id;
            int index = this->IDexit(id);
            if (index != -1)
            {
                this->m_Emparr[index]->showinfo();
            }
            else
            {
                cout << "此职工编号不存在！" << endl;
            }
        }
        else if (way == 2)
        {
            cout << "请输入要查找的姓名：";
            string name;
            cin >> name;
            bool flag = false;
            for (int i = 0; i < this->m_Empnum; i++)
            {
                if (name == this->m_Emparr[i]->m_name)
                {
                    flag = true;
                    this->m_Emparr[i]->showinfo();
                }
            }
            if (flag == false)
            {
                cout << "此职工不存在！" << endl;
            }
        }
    }
}
void WorkerManager::sort_emp()
{
    if (this->m_fileempty)
    {
        cout << "文件不存在或为空" << endl;
    }
    else
    {
        cout << "请选择排序方式：1.升序 2.降序" << endl;
        int choice;
        cin >> choice;
        for (int i = 0; i < this->m_Empnum; i++)
        {
            int min_or_max = i;
            for (int j = i + 1; j < this->m_Empnum; j++)
            {
                if (choice == 1)
                {
                    if (this->m_Emparr[min_or_max]->m_ID > this->m_Emparr[j]->m_ID)
                    {
                        min_or_max = j;
                    }
                }
                else if (choice == 2)
                {
                    if (this->m_Emparr[min_or_max]->m_ID < this->m_Emparr[j]->m_ID)
                    {
                        min_or_max = j;
                    }
                }
            }
            if (i != min_or_max)
            {
                Worker* temp = this->m_Emparr[i];
                this->m_Emparr[i] = this->m_Emparr[min_or_max];
                this->m_Emparr[min_or_max] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->save();
    }
}
void WorkerManager::clean_file()
{
    cout << "确认清空：(y/n)";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        ofstream ofs;
        ofs.open(FILENAME, ios::trunc);
        ofs.close();

        if (this->m_Emparr != NULL)
        {
            for (int i = 0; i < this->m_Empnum; i++)
            {
                if (this->m_Emparr[i] != NULL)
                {
                    delete this->m_Emparr[i];
                }
            }
            this->m_Empnum = 0;
            delete[] this->m_Emparr;
            this->m_Emparr = NULL;
            this->m_fileempty = true;
        }
        cout << "清空成功" << endl;
    }
    else if (ch == 'n' || ch == 'N')
    {
        return;
    }
}