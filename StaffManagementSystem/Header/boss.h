//
// Created by Admin on 2021/6/26.
//

#ifndef STAFFMANAGEMENTSYSTEM_BOSS_H
#define STAFFMANAGEMENTSYSTEM_BOSS_H

#include "worker.h"
#include <iostream>

using namespace std;

// 老板类
class Boss : public Worker
{
public:
    // 初始化 老板 构造函数
    Boss(int w_Id, string w_Name, int w_DepartId);

    // 获得老板个人信息
    void getWorkerInfo() override;

    // 获得老板部门岗位名称
    string getWorkerDepartName() override;
};

#endif //STAFFMANAGEMENTSYSTEM_BOSS_H