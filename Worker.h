#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:
	//��ʾԱ����Ϣ
	virtual void show_Info() = 0;
	//��ȡ��λ��Ϣ
	virtual string getDeptName() = 0;
	int m_Id; //ְ�����
	string m_Name; //ְ������
	int m_DeptId; //ְ�����ڲ������Ʊ��
};