//
// Created by Admin on 2021/6/26.
//
#include "../Header/workerManager.h"

WorkerManager::WorkerManager()
{
    // 1. 初始化 读文件对象
    ifstream ifs;
    ifs.open(WORKER_FILENAME, ios::in);

    // 2. 文件不存在的情况
    if (!ifs.is_open())
    {
        cout << "<-- 提示：职工文件不存在 -->" << endl;
        this->worker_EmpNum = 0;
        this->worker_EmpArray = nullptr;
        // 初始化 文件 是空
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    // 3. 文件存在 数据为空
    string str;
    ifs >> str;
    if (ifs.eof())
    {
        cout << "<-- 提示：职工文件为空 -->" << endl;
        this->worker_EmpNum = 0;
        this->worker_EmpArray = nullptr;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    // 4. 文件存在 有数据
    // 获得文件已记录人数
    int empNum = this->getEmpNum();
    // 更新 记录人数
    this->worker_EmpNum = empNum;
    cout << "<-- 职工数量: " << empNum << " -->" << endl;

    // 根据职工数量创建数组
    this->worker_EmpArray = new Worker *[this->worker_EmpNum];
    this->initEmployee();
    // 测试代码
//    for (int i = 0; i <worker_EmpNum; i++)
//    {
//        cout << "<-- 职工编号：" << this->worker_EmpArray[i]->worker_ID
//             << "   职工姓名：" << this->worker_EmpArray[i]->worker_Name
//             << "   职工部门：" << this->worker_EmpArray[i]->worker_DepartID
//             << " -->" << endl;
//    }
}

WorkerManager::~WorkerManager()
{
    if (this->worker_EmpArray != nullptr)
    {
        for (int i= 0; i < this->worker_EmpNum; i++)
        {
            if (this->worker_EmpArray[i] != nullptr)
            {
                delete this->worker_EmpArray[i];
            }
        }
        delete[] this->worker_EmpArray;
        this->worker_EmpArray = nullptr;
    }
}

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
}

// 保持录入职工的信息到文件
void WorkerManager::saveNewToFile()
{
    // 初始化 写文件对象
    ofstream ofs;
    ofs.open(WORKER_FILENAME, ios::out);

    for (int i = 0; i < this->worker_EmpNum; i++)
    {
        ofs << this->worker_EmpArray[i]->worker_ID << " "
            << this->worker_EmpArray[i]->worker_Name << " "
            << this->worker_EmpArray[i]->worker_DepartID << endl;
    }

    ofs.close();
}

// 获得记录职工人数
int WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(WORKER_FILENAME, ios::in);

    // 存入 读到的数据
    int worker_ID;
    string worker_Name;
    int worker_DepartID;
    // 初始化 记录人数
    int empNum = 0;

    // 当 读文件操作对象 返回为真
    while (ifs >> worker_ID && ifs >> worker_Name && ifs >> worker_DepartID)
    {
        // 记录人数 +1
        empNum++;
    }
    ifs.close();

    return empNum;
}

// 初始化职工
void WorkerManager::initEmployee()
{
    ifstream ifs;
    ifs.open(WORKER_FILENAME, ios::in);

    // 存入 读到的数据
    int worker_ID;
    string worker_Name;
    int worker_DepartID;
    // 初始化 记录人数
    int index = 0;

    // 当 读文件操作对象 返回为真
    while (ifs >> worker_ID && ifs >> worker_Name && ifs >> worker_DepartID)
    {
        Worker *worker = nullptr;

        // 根据 DepartID，创建不同职工对象
        if (worker_DepartID == 1)
        {
            worker = new Employee(worker_ID, worker_Name, worker_DepartID);
        }
        else if (worker_DepartID == 2)
        {
            worker = new Manager(worker_ID, worker_Name, worker_DepartID);
        }
        else
        {
            worker = new Boss(worker_ID, worker_Name, worker_DepartID);
        }
        // 生成职工对象后，存入职工数组中
        this->worker_EmpArray[index] = worker;
        index++;
    }
    ifs.close();
}

// 职工是否存在
int WorkerManager::isEmployeeExist(int workerID)
{
    // 默认index为职工的编号，-1是不存在
    int index = -1;
    for (int i = 0; i < this->worker_EmpNum; i++)
    {
        if (this->worker_EmpArray[i]->worker_ID == workerID)
        {
            index = i;
            break;
        }
    }
    // 返回 -1 表示不存在这个职工，其他表示找到了对应职工的ID编号
    return index;
}

// 排查添加的新职工的编号在文件中是否存在
bool WorkerManager::isEmployeeIDExist(int workerID)
{
    if (this->isFileEmpty)
    {
        this->isIDExist = false;
    }
    else
    {
        for (int i = 0; i < this->worker_EmpNum; i++)
        {
            if (this->worker_EmpArray[i]->worker_ID == workerID)
            {
                this->isIDExist = true;
                break;
            }
            else
            {
                this->isIDExist = false;
            }
        }
    }
    return this->isIDExist;
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
    cout << "<-- 已录入职工数量：" << worker_EmpNum << " -->" << endl;
    cout << "输入增加职工数量：>> ";
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0)
    {
        // 计算需要的空间大小 = 已用的空间 + 新需要的空间
        int newSize = this->worker_EmpNum + addNum;

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
            bool isExistID = true; // 新增的变量，用于判断文件中是否已存在某个ID

            // 在输入职工ID的地方，进行了修改
            // 每次输入ID，都要判断一次，输入的ID在职工文件中是否已经存在
            // 存在就继续循环该语句，不存在再继续执行之后的语句
            while (true)
            {
                cout << "输入第" << j + 1 << "位员工信息:" << endl;
                cout << "职工编号>> ";
                cin >> worker_ID;
                this->isIDExist = isEmployeeIDExist(worker_ID);

                if (this->isIDExist)
                {
                    cout << "编号已经存在" << endl;
                    system("pause");
                    system("cls");
                }
                else
                {
                    break;
                }
            }

            cout << "职工姓名>> ";
            cin >> worker_Name;

            cout << "职工岗位_ 1.员工_2.经理_3.老板>> ";
            cin >> worker_DepartID;
            cout << endl;

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
        }
        // 释放原本的空间
        delete[] this->worker_EmpArray;

        // 更改新空间的指向
        this->worker_EmpArray = newSpace;

        // 更新 新的个数
        this->worker_EmpNum = newSize;

        // 更新 文件不在为假
        this->isFileEmpty = false;

        // 提示信息
        cout << "添加成功" << addNum << "名新职工" << endl;

        // 保存录入的职工信息到文本文件中
        this->saveNewToFile();
    }
    else
    {
        cout << "需输入正确的数字" << endl;
    }
    system("pause");
    system("cls");
}

// 2.显示职工信息
void WorkerManager::showEmployeeInfo()
{
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        for (int i = 0; i < worker_EmpNum; i++)
        {
            // 利用多态调用接口
            this->worker_EmpArray[i]->getWorkerInfo();
        }
    }
    system("pause");
    system("cls");
}

// 3.删除离职职工
void WorkerManager::deletEmployee()
{
    // 先判断是否存在职工文件
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int workerID = 0;
        cout << "输入需要删除的职工编号>> ";
        cin >> workerID;

        // 通过isEmployeeExit()，确定并返回一个存在且有效的职工编号
        int workerIndex = isEmployeeExist(workerID);
        if (workerIndex != -1)
        {
            // 删掉指定数据后，数组数据需要数据前移
            for (int i = workerIndex; i < this->worker_EmpNum - 1; i++)
            {
                this->worker_EmpArray[i] = this->worker_EmpArray[i + 1];
            }
            // 没移动一个数据，数组后面需要移动的数据就少一个
            this->worker_EmpNum--;
            // 修改数据后，将更新的数据保存到文件中
            this->saveNewToFile();
            cout << "编号:" << workerIndex + 1 << " 职工已删除" << endl;
        }
        else
        {
            cout << "删除失败，职工编号错误或不存在" << endl;
        }
    }
    system("pause");
    system("cls");
}

// 4.修改职工信息
void WorkerManager::modifyEmployeeInfo()
{
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int workerID = 0;
        cout << "输入需要修改的职工编号>> ";
        cin >> workerID;

        // 通过isEmployeeExit()，确定并返回一个存在且有效的职工编号
        int workerIndex = isEmployeeExist(workerID);
        if (workerIndex != -1)
        {
            // 找到存在且有效的职工编号后，删除数组中对应的信息
            delete this->worker_EmpArray[workerIndex];

            int newWorker_ID; // 职工ID
            string newWorker_Name; // 职工姓名
            int newWorker_DepartID; // 职工部门编号

            cout << "查的编号:" << workerID << " 的职工" << endl;
            cout << "新的职工编号>> ";
            cin >> newWorker_ID;

            cout << "新的职工姓名>> ";
            cin >> newWorker_Name;

            cout << "新的职工岗位_ 1.员工_2.经理_3.老板>> ";
            cin >> newWorker_DepartID;
            cout << endl;

            Worker *worker = nullptr;

            switch (newWorker_DepartID)
            {
                case 1:
                    worker = new Employee(newWorker_ID, newWorker_Name, 1);
                    break;
                case 2:
                    worker = new Manager(newWorker_ID, newWorker_Name, 2);
                    break;
                case 3:
                    worker = new Boss(newWorker_ID, newWorker_Name, 3);
                    break;
                default:
                    break;
            }

            // 更新数据到数组中对应的编号
            this->worker_EmpArray[workerIndex] = worker;

            cout << "新编号:" << newWorker_ID << " 职工的信息，修改完成"
                 << " 新部门编号:" << this->worker_EmpArray[workerIndex]->worker_DepartID << endl;
        }
        else
        {
            cout << "修改失败，职工编号错误或不存在" << endl;
        }
    }
    system("pause");
    system("cls");
}

// 5.查找职工信息
void WorkerManager::findEmployee()
{
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int findSwitch = 0;
        cout << "查找选择_1.编号_2.姓名>> ";
        cin >> findSwitch;

        if (findSwitch == 1)
        {
            int findWorkerID;
            cout << "查找的职工编号>> ";
            cin >> findWorkerID;

            // 判断输入的编号有效性
            int workerIndex = isEmployeeExist(findWorkerID);
            if (workerIndex != -1)
            {
                cout << "查找成功" << endl;
                cout << "职工信息: ";
                this->worker_EmpArray[workerIndex]->getWorkerInfo();
            }
            else
            {
                cout << "查找失败，职工编号错误或不存在" << endl;
            }
        }
        else if (findSwitch == 2)
        {
            string findWorkerName;
            cout << "查找的职工姓名>> ";
            cin >> findWorkerName;

            bool isFindByName = false;
            for (int i = 0; i < this->worker_EmpNum; i++)
            {
                if (this->worker_EmpArray[i]->worker_Name == findWorkerName)
                {
                    isFindByName = true;
                    cout << "查到职工: " << findWorkerName << " 职工编号: " << worker_EmpArray[i]->worker_ID << endl;
                    cout << "职工信息: ";
                    worker_EmpArray[i]->getWorkerInfo();
                }
            }
            if (!isFindByName)
            {
                cout << "查找失败，职工编号、姓名错误或不存在" << endl;
            }
        }
        else
        {
            cout << "输入正确的选择" << endl;
        }
    }
    system("pause");
    system("cls");
}

// 6.按照编号排序
void WorkerManager::sortEmployeeByID()
{
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int switchSort = 0;
        cout << "依据编号，选择排序方式_1.升序排列_2.降序排列>> ";
        cin >> switchSort;

        for (int i = 0; i < this->worker_EmpNum; ++i)
        {
            int maxOrmin = i;
            for (int j = i + 1; j < this->worker_EmpNum; ++j)
            {
                // 升序排列
                if (switchSort == 1)
                {
                    // 升序排列，如是指定下标的值 大于 遍历出的最小值，说明指定的不是最小的，把遍历的下标赋值给变量
                    if (worker_EmpArray[maxOrmin]->worker_ID > worker_EmpArray[j]->worker_ID)
                    {
                        maxOrmin = j;
                    }
                }
                    // 降序排列
                else if (switchSort == 2)
                {
                    // 降序排列，如是指定下标的值 小于 遍历出的最大值，说明指定的不是最大的，把遍历的下标赋值给变量
                    if (worker_EmpArray[maxOrmin]->worker_ID < worker_EmpArray[j]->worker_ID)
                    {
                        maxOrmin = j;
                    }
                }
                else
                {
                    cout << "输入正确的选择" << endl;
                }
            }

            // 交换数据
            if (maxOrmin != i)
            {
                Worker *temp = worker_EmpArray[i];
                worker_EmpArray[i] = worker_EmpArray[maxOrmin];
                worker_EmpArray[maxOrmin] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->saveNewToFile();
        this->showEmployeeInfo();
    }
}

// 7.清空所有文档
void WorkerManager::toEmptyFile()
{
    if (this->isFileEmpty)
    {
        cout << "职工文件不存在或记录为空" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int switchNum = 0;
        cout << "确认清空文件_1.确认_2.取消>> ";
        cin >> switchNum;

        if (switchNum == 1)
        {
            // 打开模式 ios::trunc 如果存在文件 删除后 重新生成
            ofstream ofs(WORKER_FILENAME, ios::trunc);
            ofs.close();

            // 判断内存中堆区的是否存在 存在需要释放
            if (this->worker_EmpArray != nullptr)
            {
                for (int i = 0; i < this->worker_EmpNum; i++)
                {
                    if (this->worker_EmpArray[i] != nullptr)
                    {
                        delete this->worker_EmpArray[i];
                    }
                }
                this->worker_EmpNum = 0;
                delete[] worker_EmpArray;
                this->worker_EmpArray = nullptr;
                this->isFileEmpty = true;
            }
            cout << "职工文件清空完成" << endl;
            this->isIDExist = false;
        }
        else if (switchNum == 2)
        {
            cout << "已取消清空职工文件" << endl;

        }
        else
        {
            cout << "输入正确的选择" << endl;
        }
    }
    system("pause");
    system("cls");
}