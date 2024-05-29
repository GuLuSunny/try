#include <iostream>

using namespace std; 
class Account 
{
protected://������Աbalance�ɼ̳з��� 
    double balance;

public:
    Account(double initialBalance) //ȷ�ϳ�ʼ������Ч��
	{
        if (initialBalance < 0) 
		{
            balance = 0;
            cout << "��ʼ�����������Чֵ" <<endl;
        } 
		else 
		{
            balance = initialBalance;
        }
    }

    void credit(double amount) // ��ǰ����Ǯ
	{
        balance += amount;
    }

    void debit(double amount) // ���˻���ȡǮ������֤�˻�����͸֧ 
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

    double getBalance() //��ѯ��� 
	{
        return balance;
    }
};

class SavingsAccount : public Account // ������SavingsAccount���̳л���Account
{
private:
    double rate;//������ 
    int Years;//������ 

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
    SavingsAccount account(0, 0);//��ʼ��������Ϊ�� 

    cout << "initial balance: ";
    cin >> initialBalance;//�����ʼ��� 
    account = SavingsAccount(initialBalance, 0);
    
    cout << "Choose an operation:" <<endl;
        cout << "1. ���" << endl;
        cout << "2. ȡ��" << endl;
        cout << "3. ��ѯ���" << endl;
        cout << "4. ������ݺ�����" << endl;
        cout << "5. ���㱾Ϣ��" << endl;
        cout << "6. �˳�" << endl;
    do 
	{
        cin >> choice;
        switch (choice)  
		{
            case 1:
                double creditAmount;
                cout << "��������: ";
                cin >> creditAmount;
                account.credit(creditAmount);
                break;
            case 2:
                double debitAmount;
                cout << "��������: ";
                cin >> debitAmount;
                account.debit(debitAmount);
                break;
            case 3:
                cout << "��ǰ���Ϊ: " << account.getBalance() << endl;
                break;
            case 4:
                cout << "���������: ";
                cin >> Years;
                cout << "�����ʼ���� : ";
                cin >> initialRate;
                account = SavingsAccount(account.getBalance(), initialRate);
                break;
            case 5:
                cout << Years << " ���ı�Ϣ��" << account.calculate() << endl;
                break;
            case 6:
                cout << "�˳�" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } 
	while (choice != 6);

    return 0;
}

