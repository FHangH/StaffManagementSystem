//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_MANAGER_H
#define STAFFMANAGEMENTSYSTEM_MANAGER_H

#include "worker.h"
#include <iostream>

using namespace std;

// 经理类
class Manager : public Worker
{
public:
    // 初始化 经理 构造函数
    Manager(int w_Id, string w_Name, int w_DepartId);

    // 获得经理个人信息
    void getWorkerInfo() override;

    // 获得经理部门岗位名称
    string getWorkerDepartName() override;
};

#endif //STAFFMANAGEMENTSYSTEM_MANAGER_H