//
// Created by Admin on 2021/6/26.
//

#include "../Header/manager.h"

// 构造函数 初始化 经理 信息
Manager::Manager(int w_Id, string w_Name, int w_DepartId)
{
    this->worker_ID = w_Id;
    this->worker_Name = w_Name;
    this->worker_DepartID = w_DepartId;
}

// 获得 职工信息
void Manager::getWorkerInfo()
{
    cout << "编号：" << this->worker_ID
         << "\t姓名：" << this->worker_Name
         << "\t岗位：" << this->getWorkerDepartName()
         << "\t职责：执行老板的任务" << endl;
}

// 获得 职工 岗位信息
string Manager::getWorkerDepartName()
{
    return string("经理");
}
