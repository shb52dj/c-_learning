#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"


class Boss : public Worker
{
public:
	//���캯��
	Boss(int id, string name, int dId);
	//��ʾԱ����Ϣ
	virtual void show_Info();
	//��ȡ��λ��Ϣ
	virtual string getDeptName();
};