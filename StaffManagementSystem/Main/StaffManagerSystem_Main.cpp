#include <iostream>
#include "../Header/workerManager.h"
#include "../Header/employee.h"
#include "../Header/manager.h"
#include "../Header/boss.h"

void demo()
{
    Worker *worker;

    worker = new Employee(1, "Normal_A", 1);
    worker->getWorkerInfo();
    delete worker;

    worker = new Manager(2, "Manager_A", 2);
    worker->getWorkerInfo();
    delete worker;

    worker = new Boss(3, "Boss_A", 3);
    worker->getWorkerInfo();
    delete worker;
}

void showMenu()
{
    // 初始选择
    int choice = 0;

    // 生成 管理界面 对象
    WorkerManager workerManager;
    // 调用 菜单界面
    ReShowMenu:
    wm.Show_Menu();
    cout << "功能选择 >> ";
    cin >> choice;

    // 菜单界面的功能选择分支
    switch (choice)
    {
        case 0: // 0.退出管理系统
            wm.exitSystem();
            break;
        case 1: // 1.增加职工信息
            break;
        case 2: // 2.显示职工信息
            break;
        case 3: // 3.删除离职职工
            break;
        case 4: // 4.修改职工信息
            break;
        case 5: // 5.查找职工信息
            break;
        case 6: // 6.按照编号排序
            break;
        case 7: // 7.清空所有文档
            break;
        default: // 0 ~ 7 之外任意值，清空，重来菜单界面
            system("cls");
            goto ReShowMenu;
    }
}

int main()
{
    demo();
    return 0;
}