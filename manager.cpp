#include"manager.h"
Manager::Manager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}
//��ʾԱ����Ϣ
void Manager::show_Info()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}
//��ȡ��λ��Ϣ
string Manager::getDeptName()
{
	return string("����");
}