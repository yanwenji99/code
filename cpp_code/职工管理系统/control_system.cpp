#include"workerManager.h"
#include"Worker.h"
int main()
{
	WorkerManager wm;
	int choice;
	while (true)
	{
		wm.Shoe_Menu();
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º";
		cin >> choice;
		switch(choice)
		{
			case 0:
				wm.exitSystem();
				break;
			case 1:
				wm.add_emp();
				break;
			case 2:
				wm.show_emp();
				break;
			case 3:
				wm.del_emp();
				break;
			case 4:
				wm.mod_emp();
				break;
			case 5:
				wm.find_emp();
				break;
			case 6:
				wm.sort_emp();
				break;
			case 7:
				wm.clean_file();
				break;
			default:
				system("cls");
				break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}