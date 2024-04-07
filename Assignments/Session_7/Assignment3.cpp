#include <iostream>
#include <string>

class Account {
protected:
    int accountNumber;
    std::string accountHolder;
    double balance;

public:
    Account(int accNum, const std::string& accHolder, double bal)
        : accountNumber(accNum), accountHolder(accHolder), balance(bal) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (balance >= amount)
            balance -= amount;
        else
            std::cout << "Insufficient balance!" << std::endl;
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, const std::string& accHolder, double bal, double rate)
        : Account(accNum, accHolder, bal), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
    }
};

class CheckingAccount : public Account {
private:
    double transactionFee;

public:
    CheckingAccount(int accNum, const std::string& accHolder, double bal, double fee)
        : Account(accNum, accHolder, bal), transactionFee(fee) {}

    void deductTransactionFee() {
        if (balance >= transactionFee)
            balance -= transactionFee;
        else
            std::cout << "Insufficient balance to deduct transaction fee!" << std::endl;
    }
};

int main() {
    SavingsAccount savings(1001, "John Doe", 5000.0, 5.0);
    CheckingAccount checking(2001, "Jane Smith", 3000.0, 10.0); 

    savings.deposit(1000);
    savings.calculateInterest();
    savings.display();

    std::cout << std::endl;

    checking.withdraw(500);
    checking.deductTransactionFee();
    checking.display();

    return 0;
}


