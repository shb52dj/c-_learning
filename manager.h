#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Worker.h"


class Manager : public Worker
{
public:
	//构造函数
	Manager(int id, string name, int dId);
	//显示员工信息
	virtual void show_Info();
	//获取岗位信息
	virtual string getDeptName();
};