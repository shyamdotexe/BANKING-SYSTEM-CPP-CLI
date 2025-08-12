#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <bits/stdc++.h>
#include <conio.h>
#include <fstream>
#include <openssl/sha.h>
#include <sstream>
using namespace std;

string hashing_pin(string pin)
{   
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, pin.c_str(), pin.size());
    SHA256_Final(hash, &ctx);
    stringstream ss;
    for(auto i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}

class BankAccount 
{
    private:
        string accountHolder;
        int accountNumber;
        double balance;
        string pass;
    
    protected:
        double B;
        void setBalance(double B){ balance = B;}
        int getBalance() const {return balance;}

    
    public:
        static int accountCount;
        BankAccount(string name, double initialBalance, string pin)
            {
                accountHolder = name;
                accountNumber = accountCount;
                pass = hashing_pin(pin) ;
                balance = initialBalance;
                accountCount++;
                ofstream file("Account_Details.csv", ios::app) ;
                file << accountHolder<<','<< accountNumber<<','  << pass<<',' << balance << endl;
                file.close() ;
                cout << "Account Created Successfully !" << endl << "Your Account Number is : " << accountNumber;
            }
        virtual void deposit(double amount) = 0;
        virtual void withdraw(double amount) = 0;
 
    void displayAccDetails(int accNo, string pass)
  { 
    ifstream inputFile("Account_Details.csv");
    string entered_pin = hashing_pin(pass);
    bool result = false;
    string line, name, pin, accountNoStr, fileBalance;
    int accountNo;
   while(getline(inputFile, line))
{   
    stringstream ss(line);
    if(! getline(ss, name, ',')) continue;
    if(! getline(ss, accountNoStr, ',')) continue;
    if(! getline(ss, pin, ',')) continue;
    if(! getline(ss, fileBalance, ',')) continue;

    accountNo = stoi(accountNoStr);

   

    if(accountNo == accNo && entered_pin == pin)
    {   
        cout <<endl<<"Account Holder Name: "<<name << endl;
        cout <<"Account Number: "<< accountNo << endl;
        cout <<"Balance : $"<< fileBalance << endl;
        result = true;
        break;
    } 

 
    }  
    if(!result)
    {
        cout<< "Account Not Found !! Invalid Account No or PIN"<<endl;
    }
    inputFile.close();
  }
};

int BankAccount :: accountCount = 1000;

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

string pin_updation(int length = 6)
{
    string pin = "";
    char ch;
    cout<<"Enter 6 Digit Pin :"<<endl;
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
  int accNo;
  cin>>choice;
  cin.ignore();
  
  BankAccount *p;
  
  if (choice == 1)
  {
    cout<<"Enter your Name : " ;
    getline(cin,name);
    cout<<"\nCreate PIN for your Account\n";
    pass = pin_updation();
    cout<<"\nEnter the Initial Deposit amount : ";
    cin>>bal;
    Banking b1(name, bal, pass);
    p = &b1;
    
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
    cout << " Enter Account Number: ";
    cin>>accNo;
    cin.ignore();
    pass = pin_updation();
    p -> displayAccDetails(accNo, pass);
  }
  return 0;

}