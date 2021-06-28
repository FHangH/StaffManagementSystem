//
// Created by Admin on 2021/6/26.
//
#include "../Header/workerManager.h"
#include "../Header/employee.h"
#include "../Header/manager.h"
#include "../Header/boss.h"

WorkerManager::WorkerManager()
{
    // 初始化人数
    this->worker_EmpNum = 0;

    // 初始化数组指针
    this->worker_EmpArray = nullptr;
}

WorkerManager::~WorkerManager()
{}

// 显示员工管理系统主菜单
void WorkerManager::Show_Menu()
{
    cout << "======================" << endl;
    cout << "====员工管理系统主菜单====" << endl;
    cout << "=====0.退出管理系统=====" << endl;
    cout << "=====1.增加职工信息=====" << endl;
    cout << "=====2.显示职工信息=====" << endl;
    cout << "=====3.删除离职职工=====" << endl;
    cout << "=====4.修改职工信息=====" << endl;
    cout << "=====5.查找职工信息=====" << endl;
    cout << "=====6.按照编号排序=====" << endl;
    cout << "=====7.清空所有文档=====" << endl;
    cout << "======================" << endl;
    cout << endl;
}

// 0.退出管理系统
void WorkerManager::exitSystem()
{
    cout << "=====员工管理系统-退出=====" << endl;
    exit(0);
}

// 1.增加职工信息
void WorkerManager::addEmployee()
{
    cout << "输入增加职工数量：>>";
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算需要的空间大小 = 已用的空间 + 新需要的空间
        int newSize = this->worker_EmpNum + addNum;
        worker_EmpNum = sizeof(this->worker_EmpArray);

        // 在 堆区中开辟 计算好大小的内存空间
        Worker **newSpace = new Worker *[newSize];

        // 将已有空间的内容存在新的内村空间中
        if (this->worker_EmpArray != nullptr)
        {
            for (int i = 0; i < this->worker_EmpNum; i++)
            {
                newSpace[i] = this->worker_EmpArray[i];
            }
        }

        // 再将 需要添加的新内容加入
        for (int j = 0; j < addNum; j++)
        {
            int worker_ID; // 职工ID
            string worker_Name; // 职工姓名
            int worker_DepartID; // 职工部门编号

            cout << "输入第" << j + 1 << "位员工信息:" << endl;
            cout << "职工编号>>";
            cin >> worker_ID;

            cout << "职工姓名>>";
            cin >> worker_Name;

            cout << "职工岗位_ 1.员工_2.经理_3.老板>>";
            cin >> worker_DepartID;

            Worker *worker = nullptr;

            switch (worker_DepartID)
            {
                case 1:
                    worker = new Employee(worker_ID, worker_Name, 1);
                    break;
                case 2:
                    worker = new Manager(worker_ID, worker_Name, 2);
                    break;
                case 3:
                    worker = new Boss(worker_ID, worker_Name, 3);
                    break;
                default:
                    break;
            }

            newSpace[this->worker_EmpNum + j] = worker;

            // 释放原本的空间
            delete[] this->worker_EmpArray;

            // 更改新空间的执向
            this->worker_EmpArray = newSpace;

            // 更新 新的个数
            this->worker_EmpNum = newSize;

            // 提示信息
            cout << "添加成功" << addNum << "名新职工" << endl;
        }
    }
    else
    {
        cout << "需输入正确的数字" << endl;
    }

    system("cls");
}

// 2.显示职工信息

// 3.删除离职职工

// 4.修改职工信息

// 5.查找职工信息

// 6.按照编号排序

// 7.清空所有文档