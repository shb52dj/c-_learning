#include"employee.h"
Employee::Employee(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;

}
//��ʾԱ����Ϣ
void Employee::show_Info()
{
	cout << "ְ����ţ� " << this->m_Id
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->getDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
}
//��ȡ��λ��Ϣ
string Employee::getDeptName()
{
	return string("Ա��");
}