#include"workerManager.h"
WorkerManager::WorkerManager()
{
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		/*cout << "�ļ�������" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	
	}
	//�ļ����ڣ���¼Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		/*cout << "�ļ�Ϊ��" << endl;*/
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	/*cout << "ְ������Ϊ��" << num << endl;*/
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
	/*for (int i = 0; i < m_EmpNum; i++)
	{
		cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
			<< " ְ�������� " << this->m_EmpArray[i]->m_Name
			<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	}*/
}

void WorkerManager::Show_Menu()
{

	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


//�˳�ϵͳ
void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
//����Ա��
void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;//�����û�����������
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//�¿ռ�Ĵ�С����ԭ��������+��������
		//�����¿ռ�
		Worker** newSpace = new Worker*[newSize];
		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//�������������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;
			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;
		//delete[] newSpace;
		this->m_FileIsEmpty = false;
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
		//�������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
//�����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();
}
//��ȡ����
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	return num;

}
//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId==1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3)
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}
//��ʾԱ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��!" << endl;

	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			this->m_EmpArray[i]->show_Info();
		}
	}
	system("pause");
	system("cls");
}

//����ְ��
int WorkerManager::isExit(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;

}
//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
		//����ְ�����ɾ�� 
		cout << "��������Ҫɾ��ְ���ı�ţ�" << endl;
		int id = 0;
		cin >> id;
		int index = this->isExit(id);
		if (index != -1)
		{
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ�" << endl;
		}
		system("pause");
		system("cls");
	}
}
void WorkerManager::Mod_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int ret = this->isExit(id);
		if (ret != -1)
		{
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "�鵽��" << id << "��ְ�����������µ�ְ�����" << endl;
			cin >> newId;
			cout << "��������������" << endl;
			cin >> newName;
			cout << "�������λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;

			}
			this->m_EmpArray[ret] = worker;
			cout << "�޸ĳɹ���" <<  endl;
			this->save();
		}
		else
		{
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ��!" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������ְ�����:" << endl;
			cin >> id;
			int ret = isExit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�����Ա����Ϣ���£�" << endl;
				this->m_EmpArray[ret]->show_Info();
			}
			else
			{
				cout << "���޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "���������Ա��������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->show_Info();
				}
			}
			if (flag == false)
			{
				cout << "���޴���" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
//����
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");

	}
	else
	{
		cout << "����������ʽ:" << endl;
		cout << "1������" << endl;
		cout << "2������" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0; i < m_EmpNum; i++)
		{
			int minOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					//����
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;

					}
				}
				else //����
				{
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;

					}
				}
			}
			//�ж�һ��ʼ���϶������ֵ�Ƿ����ֵ
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;

			}
			
		}
	}
	cout << "����ɹ�!�����Ľ��Ϊ��" << endl;
	this->save();
	this->Show_Emp();

}
void WorkerManager::cleanFile()
{
	cout << "ȷ�������" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
				
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "��ճɹ�" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}