//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H
#define STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H

#define wm workerManager
#include <iostream>
#include "worker.h"

using namespace std;

class WorkerManager
{
public:
    // 记录文件中的人数
    int worker_EmpNum;

    // 员工数组指针
    Worker ** worker_EmpArray;

    WorkerManager();
    ~WorkerManager();

    // 显示员工管理系统主菜单
    void Show_Menu();

    // 0.退出管理系统
    void exitSystem();

    // 1.增加职工信息
    void addEmployee();

    // 2.显示职工信息

    // 3.删除离职职工

    // 4.修改职工信息

    // 5.查找职工信息

    // 6.按照编号排序

    // 7.清空所有文档

};

#endif //STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H