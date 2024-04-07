#include <iostream>
#include <vector>

using namespace std;

class BankAccount
{
    int ID;
    string ownerName;
    string type;
    int balance;

public:
    BankAccount(int id, string n, string t, int b)
    {
        ID = id;
        ownerName = n;
        type = t;
        balance = b;
    }

    int getID(void) {return ID;}
    string getName(void) {return ownerName;}
    string getType(void) {return type;}
    int getBalance(void) {return balance;}

    void deposite(int n)
    {
        balance += n;
    }

    void withdraw(int n)
    {
        balance -= n;
    }

    void displayAcc(void)
    {
        cout << "ID: " <<ID<<endl;
        cout << "Name: " <<ownerName<<endl;
        cout << "Type: " <<type<<endl;
        cout << "Balance: " <<balance<<endl;
    }

};


class Bank
{
    vector<BankAccount*> accounts;

public:
    void addAccount()
    {
        int ID;
        string name;
        string type;
        int balance;

        cout << "Enter ID: ";
        cin >> ID;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Type: ";
        cin >> type;
        cout << "Enter Balance: ";
        cin >> balance;

        BankAccount* acc = new BankAccount(ID, name, type, balance);

        accounts.push_back(acc);


    }



    void displayTotalBalance(void)
    {
        int sum = 0;

        for(auto i = accounts.begin(); i != accounts.end(); ++i)
        {
            sum += (*i)->getBalance();
        }

        cout << "Total balance is: " << sum<< endl;
    }

    void displayAllAccounts(void)
    {
        for(auto i = accounts.begin(); i != accounts.end(); ++i)
        {
            (*i)->displayAcc();
        }
    }

    void withdraw()
    {
        int id = -1, money = 0;
        cout << "Enter the account ID: ";
        cin >> id;

        BankAccount * acc = nullptr;

        for(auto i = accounts.begin(); i != accounts.end(); ++i)
        {
            if((*i)->getID() == id)
            {
                acc = (*i);
            }
        }

        if(acc != nullptr)
        {
            cout << "Enter the amount: ";
            cin >> money;
            acc->withdraw(money);
        }
        else
        {
            cout << "Account not found!"<<endl;
        }
    }

    void deposite()
    {
        int id = -1, money = 0;
        cout << "Enter the account ID: ";
        cin >> id;

        BankAccount * acc = nullptr;

        for(auto i = accounts.begin(); i != accounts.end(); ++i)
        {
            if((*i)->getID() == id)
            {
                acc = (*i);
            }
        }

        if(acc != nullptr)
        {
            cout << "Enter the amount: ";
            cin >> money;
            acc->deposite(money);
        }
        else
        {
            cout << "Account not found!"<<endl;
        }
    }
};



int main()
{
    int exit = 0;
    int choice = 0;

    Bank b;
    do
    {
        cout << "Menu:"<<endl;
        cout << "1. Create an account"<<endl;
        cout << "2. Deposite "<<endl;
        cout << "3. Withdraw "<<endl;
        cout << "4. Total Balance"<<endl;
        cout << "5. Display all accounts"<<endl;
        cout << "6. Exit"<<endl;

        cin >> choice;

        switch (choice)
        {
            case 1:
                b.addAccount();
                break;

            case 2:
                b.deposite();
                break;

            case 3:
                b.withdraw();
                break;

            case 4:
                b.displayTotalBalance();
                break;

            case 5:
                b.displayAllAccounts();
                break;

            case 6:
                exit = 1;
                break;
            
            default:
                cout << "Invalid choice!"<<endl;
                break;
        }


    }while(!exit);
    
    return 0;
}