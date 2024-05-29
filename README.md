# 类设计题目
========
题目
--------
1.基类Account：

数据成员：

balance: double类型，表示账户余额；

构造函数：

构造函数接受一个初始余额参数,初始化数据成员balance,并能确认初始余额的有效性，保证它大于等于0，如果小于0，则将balance置为0，并显示出错信息，表示该初始化余额是一个无效的值；

成员函数：

    credit：可以向当前余额加钱，

    debit：负责从账户中取钱，并保证账户不会不会透支，如果提取金额大于账户余额，函数将保持balance不变，并打印信息“Debit amount exceeded account balance.”

    getBalance：返回当前balance的值；

2.派生类SavingsAccount：

    继承基类Account，并提供一个附加的double类型的数据成员rate表示这个账户的年利率和一个附加的int类型表示存款年份。

构造函数：

接收初始化余额和初始利率值

成员函数：

calculate：返回代表账户经过这些存款年后账户的总余额；

3.main.cpp函数中进行对类的测试，

要求一个账户能够创建账户（可以写在mian函数里），并对这个账户进行存取款操作(switch菜单操作)
可以输入存款年份和年利率(switch菜单操作)，求这些年后可以得到的总余额
提示：balance和rate的乘积即为年利息（存款后每年的余额都会变）
