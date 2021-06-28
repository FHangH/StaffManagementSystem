//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_WORKER_H
#define STAFFMANAGEMENTSYSTEM_WORKER_H

#include <iostream>

using namespace std;

// 职工抽象类
class Worker
{
public:
    int worker_ID; // 职工ID
    string worker_Name; // 职工姓名
    int worker_DepartID; // 职工部门编号

    // 获得 职工的信息
    virtual void getWorkerInfo() = 0;

    // 获得 职工部门的岗位名称
    virtual string getWorkerDepartName() = 0;
};

#endif //STAFFMANAGEMENTSYSTEM_WORKER_H