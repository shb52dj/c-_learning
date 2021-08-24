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

	//展示菜单
	void Show_Menu();
	//退出系统
	void exitSystem();


	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加员工函数
	void Add_Emp();
	//保存文件
	void save();
	//判断文件是否为空
	bool m_FileIsEmpty;
	//统计文件的人数
	int get_EmpNum();

	//初始化员工
	void init_Emp();
	//显示员工
	void Show_Emp();
	//删除职工
	void Del_Emp();
	//查找职工
	int isExit(int id);
	//修改职工
	void Mod_Emp();
	//查找职工
	void Find_Emp();
	//排序
	void Sort_Emp();
	//清空数据
	void cleanFile();
	~WorkerManager();
};