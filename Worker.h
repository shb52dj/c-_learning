#pragma once
#include<iostream>
#include<string>
using namespace std;
class Worker
{
public:
	//显示员工信息
	virtual void show_Info() = 0;
	//获取岗位信息
	virtual string getDeptName() = 0;
	int m_Id; //职工编号
	string m_Name; //职工姓名
	int m_DeptId; //职工所在部门名称编号
};