#include<bits/stdc++.h>
using namespace std;

class Staff
{
    friend istream &operator>>(istream &in, Staff &staff);
    friend ostream &operator<<(ostream &out, const Staff &staff);
public:
    Staff() : m_num(""), m_name(""), m_department("") {}
    Staff(const string &num, const string &name, const string &department)
        : m_num(num), m_name(name), m_department(department) {}
    void setinformation(const string &num, const string &name, const string &department)
    {
        m_num = num;
        m_name = name;
        m_department = department;
    }
    string getnum() const
    {
        return m_num;
    }
private:
    string m_num, m_name, m_department;
};
istream &operator>>(istream &in, Staff &staff)
{
    in >> staff.m_num >> staff.m_name >> staff.m_department;
    return in;
}
ostream &operator<<(ostream &out, const Staff &staff)
{
    out << staff.m_num << " " << staff.m_name << " " << staff.m_department << endl;
    return out;
}

void Addstaff();
void Showstaff();
void Deletestaff();
void Modifystaff();
void Searchstaff();
void Sortstaff();
void Clearstaff();

void Start_Control()
{
    cout<<"Welcome to the staff management system!"<<endl;
    cout<<"0: Exit"<<endl;
    cout<<"1: Add Staff"<<endl;
    cout<<"2: Show Staff"<<endl;
    cout<<"3: Delete Staff"<<endl;
    cout<<"4: Modify Staff"<<endl;
    cout<<"5: Search Staff"<<endl;
    cout<<"6: Sort Staff"<<endl;
    cout<<"7: Clear All Staff"<<endl;
    
    char option;
    do
    {
        cout << "Please select an option: ";
        cin >> option;
        switch(option)
        {
            case '0':
                cout << "Exiting the system." << endl;
                break;
            case '1':
                Addstaff();
                break;
            case '2':
                Showstaff();
                break;
             case '3':
                 Deletestaff();
                 break;
             case '4':
                 Modifystaff();
                 break;
             case '5':
                 Searchstaff();
                 break;
             case '6':
                 Sortstaff();
                 break;
             case '7':
                 Clearstaff();
                 break;
            default:
                cout << "Invalid option, please try again." << endl;
        }
    }while(option != '0');
}

void Addstaff()
{
    ofstream file;
    file.open("staff_list.txt", ios::app);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    cout << "Enter staff information (num name department): ";
    while (true)
    {
        string num, name, department;
        cin >> num;
        if (num == "0") break;
        cin >> name >> department;
        Staff staff;
        staff.setinformation(num, name, department);
        if (staff.getnum() != "0")
        {
            file << staff;
        }
    };
    file.close();
}
void Showstaff()
{
    ifstream file;
    file.open("staff_list.txt");
    string s;
    while (getline(file, s))
    {
        cout << s << endl;
    }
    file.close();
}
void Deletestaff() 
{
    cout<<"Please enter the staff number to delete: ";
    string num;
    cin >> num;
    ifstream file;
    file.open("staff_list.txt");
    vector<Staff> staffList; 
    // 用来存储剩余的员工信息
    // vector 是一个动态数组，可以存储任意数量的元素
    // push_back(obj)       尾部添加元素 obj
    // size()               返回容器的大小
    // clear()              清空容器
    // erase(iterator pos)  删除指定位置的元素
    // staffs[i]            访问第 i 个元素
    Staff staff;
    while (file >> staff)
    {
        if (staff.getnum() != num)
        {
            staffList.push_back(staff);
        }
    }
    file.close();

    ofstream newfile;
    newfile.open("staff_list.txt", ios::trunc);
    for (const auto &s : staffList)
    {
        newfile << s;
    }
    newfile.close();
}
void Modifystaff() 
{
    cout << "Please enter the staff number to modify: ";
    string num;
    cin >> num;
    ifstream file;
    file.open("staff_list.txt");
    vector<Staff> staffList; 
    Staff staff;
    while (file >> staff)
    {
        if (staff.getnum() == num)
        {
            cout << "Current information: " << staff << endl;
            cout << "Enter new information (num name department): ";
            string newNum, newName, newDepartment;
            cin >> newNum >> newName >> newDepartment;
            staff.setinformation(newNum, newName, newDepartment);
        }
        staffList.push_back(staff);
    }
    file.close();

    ofstream newfile;
    newfile.open("staff_list.txt", ios::trunc);
    for (const auto &s : staffList)
    {
        newfile << s;
    }
    newfile.close();
}
void Searchstaff() 
{
    cout<<"Please enter the staff number to search: ";
    string num;
    cin >> num;
    ifstream file;
    file.open("staff_list.txt",ios::in);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    Staff staff;
    while(file>>staff)
    {
        if (staff.getnum() == num)
        {
            cout << "Staff found: " << staff << endl;
            file.close();
            return;
        }
    }
    cout << "Staff not found." << endl;
    file.close();
}
void Searchstaff(string num)
{
    ifstream file;
    file.open("staff_list.txt", ios::in);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    Staff staff;
    while (file >> staff)
    {
        if (staff.getnum() == num)
        {
            cout << "Staff found: " << staff << endl;
            file.close();
            return;
        }
    }
    cout << "Staff not found." << endl;
    file.close();
}
void Sortstaff() 
{
    ifstream file;
    file.open("staff_list.txt", ios::in);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    vector<Staff> staffList;
    Staff staff;
    while (file >> staff)
    {
        staffList.push_back(staff);
    }
    file.close();

   
    sort(staffList.begin(), staffList.end(), [](const Staff &a, const Staff &b) {
        return a.getnum() < b.getnum();
    });

    ofstream newfile;
    newfile.open("staff_list.txt", ios::trunc);
    for (const auto &s : staffList)
    {
        newfile << s;
    }
    newfile.close();
}
void Clearstaff() 
{
    ofstream file;
    file.open("staff_list.txt", ios::trunc);
    if (!file)
    {
        cerr << "Error opening file!" << endl;
        return;
    }
    file.close();
}

int main()
{
    Start_Control();
    return 0;
}