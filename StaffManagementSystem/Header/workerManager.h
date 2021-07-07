//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H
#define STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H

#define wm workerManager
#define WORKER_FILENAME "../File/workerFile.txt"
#include <iostream>
#include <fstream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

using namespace std;

class WorkerManager
{
public:
    // 记录文件中的人数
    int worker_EmpNum;

    // 判断文件是否为空
    bool isFileEmpty;

    // 判断文件是否存在某个编号
    bool isIDExist;

    // 员工数组指针
    Worker ** worker_EmpArray;

    WorkerManager();
    ~WorkerManager();

    // 显示员工管理系统主菜单
    void Show_Menu();

    // 保持录入职工的信息到文件
    void saveNewToFile();

    // 获得记录职工人数
    int getEmpNum();

    // 初始化职工
    void initEmployee();

    // 职工是否存在
    int isEmployeeExist(int workerID);

    // 排查添加的新职工的编号在文件中是否存在
    bool isEmployeeIDExist(int workerID);

    // 0.退出管理系统
    void exitSystem();

    // 1.增加职工信息
    void addEmployee();

    // 2.显示职工信息
    void showEmployeeInfo();

    // 3.删除离职职工
    void deletEmployee();

    // 4.修改职工信息
    void modifyEmployeeInfo();

    // 5.查找职工信息
    void findEmployee();

    // 6.按照编号排序
    void sortEmployeeByID();

    // 7.清空所有文档
    void toEmptyFile();

};

#endif //STAFFMANAGEMENTSYSTEM_WORKERMANAGER_H