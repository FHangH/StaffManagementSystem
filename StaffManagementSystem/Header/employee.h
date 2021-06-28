//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_EMPLOYEE_H
#define STAFFMANAGEMENTSYSTEM_EMPLOYEE_H

#include "worker.h"
#include <iostream>

using namespace std;

// 普通员工 类
class Employee : public Worker
{
public:
    // 初始化 员工 构造函数
    Employee(int w_Id, string w_Name, int w_DepartId);

    // 获得员工个人信息
    void getWorkerInfo() override;

    // 获得员工部门岗位名称
    string getWorkerDepartName() override;
};

#endif //STAFFMANAGEMENTSYSTEM_EMPLOYEE_H