#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
using namespace std;

class BankAccount 
{
    private:
        string accountHolder;
        int accountNumber;
        double balance;
        string pin;
        static int accountCount;
    
    protected:
        double B;
        void setBalance(double B){ balance = B;}
        int getBalance() const {return balance;}

    
    public:
        BankAccount(string name, double initialBalance, string pin)
            {
                accountHolder = name;
                accountNumber = accountCount;
                this -> pin = pin ;
                balance = initialBalance;
                accountCount++;
                ofstream file("Account_Details.txt", ios::app) ;
                file << accountHolder << "\t|\t"<< accountNumber <<"\t|\t" << balance << endl;
                file.close() ;
            }
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
 
    void displayAccDetails()
  {
    cout<<"Account Number : "<< accountNumber<< endl <<"Account Holder Name : "<<accountHolder<<endl<<"Balance : $"<<fixed<<setprecision(4)<<balance;
  }
};

int BankAccount :: accountCount = 1;

class Banking : public BankAccount
{   
    public:
        Banking(string name, double bal, string pass) : BankAccount(name , bal, pass){}
        void deposit(double amount) override
        {
            cout<<"Enter the amount : $";
            cin>>amount;
            double newBalance = getBalance() + amount ; 
            setBalance(newBalance);
            cout<<"Deposited Successfully!!";
            cout<<"$"<<getBalance()<<endl;
        }
        
        void withdraw(double amount) override
        {
            if(amount > getBalance())
            cout<<"Insufficient Fund !"<<endl;
            else 
            {
                setBalance(getBalance() - amount);
            }
            cout<<"$"<<getBalance()<<endl;
        }
};

string pinCreation(int length = 6)
{
    string pin = "";
    char ch;
    cout<<"Enter a 6 Digit Pin :"<<endl;
    while(pin.length() < length)
    {
        ch = _getch();
        if (isdigit(ch)){
            cout<<"*";
            pin += ch ;
        }
        
    };
     return pin;

}

int main()
{
  cout<<"======= Banking System Menu =======\n\n\n"<<"Choose the preferred service below :\n\n";
  cout<<"1. Account Creation\n"<<"2. Banking\n"<<"3. Show Account Balance\n";
  int choice;
  string name;
  int pin;
  double bal;
  string pass;
  double amount;
  cin>>choice;
  cin.ignore();
  
  BankAccount *p;
  
  if (choice == 1)
  {
    cout<<"Enter your Name : " ;
    getline(cin,name);
    cout<<"\nCreate PIN for your Account\n";
    pass = pinCreation();
    cout<<"\nEnter the Initial Deposit amount : ";
    cin>>bal;
    Banking b1(name, bal, pass);
    p = &b1;
    p -> displayAccDetails();
  }
  else if(choice == 2)
  {
    cout<<"Choose Preferred Service"<<endl;
    cout<<"1.Withdrawal"<<endl<<"2.Deposit"<<endl;
    int a;
    cin>>a;
    if(a == 1)
    {
        cout<<"Enter the Amount to be Withdrawn : $";
        cin>>amount;
        p -> withdraw(amount);
    }
    if(a == 2)
    {
        cout<<"Enter The Amount to be Deposited : $";
        cin>>amount;
        p -> deposit(amount);
    }
    else
    {
        cout<<"Invalid Response!!"<<endl;
    }
  }
  else if(choice == 3)
  {
    cout << p->getBalance() << endl;
  }
  return 0;

}