#include <iostream>
#include <string>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;

public:
    BankAccount(const std::string& accNum, double initBalance) : accountNumber(accNum), balance(initBalance) {}

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            std::cout << "Insufficient funds." << std::endl;
    }

    virtual void displayInfo() {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const std::string& accNum, double initBalance, double rate) : BankAccount(accNum, initBalance), interestRate(rate) {}

    void calculateInterest() {
        double interest = balance * interestRate / 100.0;
        deposit(interest);
    }

    void displayInfo() override {
        BankAccount::displayInfo();
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
    }
};

class CheckingAccount : public BankAccount {
private:
    double transactionFee;

public:
    CheckingAccount(const std::string& accNum, double initBalance, double fee) : BankAccount(accNum, initBalance), transactionFee(fee) {}

    void deductTransactionFee() {
        if (balance >= transactionFee)
            balance -= transactionFee;
        else
            std::cout << "Insufficient funds to deduct transaction fee." << std::endl;
    }

    void displayInfo() override {
        BankAccount::displayInfo();
        std::cout << "Transaction Fee: $" << transactionFee << std::endl;
    }
};

int main() {
    SavingsAccount savings("SAV12345", 1000.0, 3.5); // Account Number, Initial Balance, Interest Rate
    CheckingAccount checking("CHK54321", 1500.0, 5.0); // Account Number, Initial Balance, Transaction Fee

    std::cout << "Savings Account Info:" << std::endl;
    savings.displayInfo();
    savings.calculateInterest();
    std::cout << "After calculating interest:" << std::endl;
    savings.displayInfo();

    std::cout << "\nChecking Account Info:" << std::endl;
    checking.displayInfo();
    checking.deductTransactionFee();
    std::cout << "After deducting transaction fee:" << std::endl;
    checking.displayInfo();

    return 0;
}
