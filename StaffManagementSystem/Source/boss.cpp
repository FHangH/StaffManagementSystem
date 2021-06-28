//
// Created by Admin on 2021/6/26.
//

#include "../Header/boss.h"

// 构造函数 初始化 老板 信息
Boss::Boss(int w_Id, string w_Name, int w_DepartId)
{
    this->worker_ID = w_Id;
    this->worker_Name = w_Name;
    this->worker_DepartID = w_DepartId;
}

// 获得 职工信息
void Boss::getWorkerInfo()
{
    cout << "编号：" << this->worker_ID
         << "\t姓名：" << this->worker_Name
         << "\t\t岗位：" << this->getWorkerDepartName()
         << "\t职责：管理所有的事务" << endl;
}

// 获得 职工 岗位信息
string Boss::getWorkerDepartName()
{
    return string("老板");
}
