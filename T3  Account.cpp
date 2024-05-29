#include <iostream>

using namespace std; 
class Account 
{
protected://保护成员balance可继承访问 
    double balance;

public:
    Account(double initialBalance) //确认初始余额的有效性
	{
        if (initialBalance < 0) 
		{
            balance = 0;
            cout << "初始化的余额是无效值" <<endl;
        } 
		else 
		{
            balance = initialBalance;
        }
    }

    void credit(double amount) // 向当前余额加钱
	{
        balance += amount;
    }

    void debit(double amount) // 从账户中取钱，并保证账户不会透支 
	{
        if (amount > balance) 
		{
            cout << "Debit amount exceeded account balance." << std::endl;
        } 
		else 
		{
            balance -= amount;
        }
    }

    double getBalance() //查询余额 
	{
        return balance;
    }
};

class SavingsAccount : public Account // 派生类SavingsAccount，继承基类Account
{
private:
    double rate;//年利率 
    int Years;//存款年份 

public:
    SavingsAccount(double initialBalance, double initialRate) : Account(initialBalance), rate(initialRate) {}

    double calculate() 
	{
        double totalBalance = balance;
        for (int i = 0; i < Years; i++) 
		{
            totalBalance += totalBalance * rate;
        }
        return totalBalance;
    }

};

int main() 
{
    double initialBalance, initialRate;
    int choice, Years;
    SavingsAccount account(0, 0);//初始金额和利率为零 

    cout << "initial balance: ";
    cin >> initialBalance;//输入初始金额 
    account = SavingsAccount(initialBalance, 0);
    
    cout << "Choose an operation:" <<endl;
        cout << "1. 存款" << endl;
        cout << "2. 取款" << endl;
        cout << "3. 查询余额" << endl;
        cout << "4. 设置年份和利率" << endl;
        cout << "5. 计算本息和" << endl;
        cout << "6. 退出" << endl;
    do 
	{
        cin >> choice;
        switch (choice)  
		{
            case 1:
                double creditAmount;
                cout << "存入金额数: ";
                cin >> creditAmount;
                account.credit(creditAmount);
                break;
            case 2:
                double debitAmount;
                cout << "提出金额数: ";
                cin >> debitAmount;
                account.debit(debitAmount);
                break;
            case 3:
                cout << "当前余额为: " << account.getBalance() << endl;
                break;
            case 4:
                cout << "输入存款年份: ";
                cin >> Years;
                cout << "输入初始利率 : ";
                cin >> initialRate;
                account = SavingsAccount(account.getBalance(), initialRate);
                break;
            case 5:
                cout << Years << " 年后的本息和" << account.calculate() << endl;
                break;
            case 6:
                cout << "退出" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } 
	while (choice != 6);

    return 0;
}

