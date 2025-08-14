#include"workerManager.h"

WorkerManager::WorkerManager()
{
    // �ļ�������
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ�������" << endl;
        this->m_Empnum = 0;
        this->m_Emparr = NULL;
        this->m_fileempty = true;
        ifs.close();
        return;
    }
    // �ļ�Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;
        this->m_Empnum = 0;
        this->m_Emparr = NULL;
        this->m_fileempty = true;
        ifs.close();
        return;
    }
    // �ļ���Ϊ��
    int num = this->getnum();
    cout << "ְ������Ϊ��" << num << endl;
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
    cout << "��ӭʹ��ְ������ϵͳ" << endl;
    cout << "0: �˳�" << endl;
    cout << "1: ���ְ����Ϣ" << endl;
    cout << "2: չʾְ����Ϣ" << endl;
    cout << "3: ɾ��ְ����Ϣ" << endl;
    cout << "4: �޸�ְ����Ϣ" << endl;
    cout << "5: ����ְ����Ϣ" << endl;
    cout << "6: ְ����Ϣ����" << endl;
    cout << "7: ���ְ����Ϣ" << endl;
    cout << endl;
}
void WorkerManager::exitSystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}
void WorkerManager::add_emp()
{
    cout << "���������ְ��������";
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
            cout << "¼���" << i + 1 << " ��ְ����Ϣ" << endl;
            cout << "ְ����ţ�" ;
            while (true)
            {
                cin >> ID;
                int is = this->IDexit(ID);
                if (is != -1)
                {
                    cout << "�˱���Ѿ����ڣ����������룺";
                }
                else
                    break;
            }
            cout << "ְ��������";
            cin >> name;
            cout << "ְλ��ţ� 1��ְ��  2������  3��Boss"<<endl;
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
        cout << "��ӳɹ�" << endl;

        this->save();
    }
    else
        cout << "��������" << endl;
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
        cout << "�ļ������ڻ�Ϊ��" << endl;
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
        cout << "�ļ������ڻ�Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫɾ����ְ����ţ�";
        int id;
        cin >> id;
        int index = this->IDexit(id);
        if (index == -1)
        {
            cout << "��ְ����Ų����ڣ�"<<endl;
        }
        else
        {
            for (int i = index; i < this->m_Empnum - 1; i++)
            {
                this->m_Emparr[i] = this->m_Emparr[i + 1];
            }
            this->m_Empnum--;
            this->save();
            cout << "ɾ���ɹ�" << endl;
        }
    }
}
void WorkerManager::mod_emp()
{
    if (this->m_fileempty)
    {
        cout << "�ļ������ڻ�Ϊ��" << endl;
    }
    else
    {
        cout << "������Ҫ�޸ĵ�ְ�����:";
        int id;
        cin >> id;
        int index = this->IDexit(id);
        if (index == -1)
        {
            cout << "��ְ����Ų����ڣ�" << endl;
        }
        else
        {
            cout << "���ҵ�ְ����Ϣ" << endl;
            this->m_Emparr[index]->showinfo();
            cout << "�������޸ĺ����Ϣ:"<<endl;
            int ID;
            string name;
            int depart;
            cout << "ְ����ţ�";
            cin >> ID;
            cout << "ְ��������";
            cin >> name;
            cout << "ְλ��ţ� 1��ְ��  2������  3��Boss" << endl;
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
            cout << "�޸ĳɹ�" << endl;
            this->save();
        }
    }
}
void WorkerManager::find_emp()
{
    if (this->m_fileempty)
    {
        cout << "�ļ������ڻ�Ϊ��" << endl;
    }
    else
    {
        cout << "��ѡ����ҷ�ʽ��" << endl;
        cout << "1.ʹ�ñ�Ų���" << endl;
        cout << "2.ʹ����������" << endl;
        int way;
        cin >> way;
        if (way == 1)
        {
            cout << "������Ҫ���ҵı�ţ�";
            int id;
            cin >> id;
            int index = this->IDexit(id);
            if (index != -1)
            {
                this->m_Emparr[index]->showinfo();
            }
            else
            {
                cout << "��ְ����Ų����ڣ�" << endl;
            }
        }
        else if (way == 2)
        {
            cout << "������Ҫ���ҵ�������";
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
                cout << "��ְ�������ڣ�" << endl;
            }
        }
    }
}
void WorkerManager::sort_emp()
{
    if (this->m_fileempty)
    {
        cout << "�ļ������ڻ�Ϊ��" << endl;
    }
    else
    {
        cout << "��ѡ������ʽ��1.���� 2.����" << endl;
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
        cout << "����ɹ�" << endl;
        this->save();
    }
}
void WorkerManager::clean_file()
{
    cout << "ȷ����գ�(y/n)";
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
        cout << "��ճɹ�" << endl;
    }
    else if (ch == 'n' || ch == 'N')
    {
        return;
    }
}