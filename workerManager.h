#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#define FILENAME "empFile.txt"
class WorkerManager
{
public:
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void exitSystem();


	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���Ա������
	void Add_Emp();
	//�����ļ�
	void save();
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
	//ͳ���ļ�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();
	//��ʾԱ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//����ְ��
	int isExit(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����
	void Sort_Emp();
	//�������
	void cleanFile();
	~WorkerManager();
};