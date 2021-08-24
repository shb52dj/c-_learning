#include<iostream>
using namespace std;
#include"workerManager.h"




int main()
{
	//Worker* worker = NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->show_Info();
	//delete worker;
	//worker = new Boss(2, "李四", 2);
	//worker->show_Info();
	//delete worker;

	//worker = new Manager(3, "王五", 3);
	//worker->show_Info();
	//delete worker;
	WorkerManager wm;
	int chioce=0;
	while (true)
	{
		wm.Show_Menu();
		
		cout << "请输入你的选择" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0: //退出系统
			wm.exitSystem();
			break;
		case 1: //添加职工
			wm.Add_Emp();
			break;
		case 2: //显示职工
			wm.Show_Emp();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break;
		case 4: //修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: //排序职工
			wm.Sort_Emp();
			break;
		case 7: //清空文件
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
		
	}

	system("pause");
	return 0;
}