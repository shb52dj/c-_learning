#include<iostream>
using namespace std;
#include"workerManager.h"




int main()
{
	//Worker* worker = NULL;
	//worker = new Employee(1, "����", 1);
	//worker->show_Info();
	//delete worker;
	//worker = new Boss(2, "����", 2);
	//worker->show_Info();
	//delete worker;

	//worker = new Manager(3, "����", 3);
	//worker->show_Info();
	//delete worker;
	WorkerManager wm;
	int chioce=0;
	while (true)
	{
		wm.Show_Menu();
		
		cout << "���������ѡ��" << endl;
		cin >> chioce;
		switch (chioce)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
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