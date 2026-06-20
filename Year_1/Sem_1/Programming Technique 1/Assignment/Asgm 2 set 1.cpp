//LAU YEE WEN A23CS0099
//CHERYL CHEONG KAH VOON A23CS0060
//Assignment 2 (SET1)
#include<iostream>
#include <string>
using namespace std;

//function prototypes
void displayAccountInfo(int &); 
void deposit(int &, int);
void withdraw(int &, int);

void displayAccountInfo(int &balance)
{
	cout<<"<<<<< My Accounts Overview >>>>>"<<endl;
	cout << "Account Holder Name : User 1";
	cout << "\nAccount Number : 1013202341";
	cout << "\nBalance : RM " <<balance;
}

void deposit(int &balance, int num)
{
	balance = balance + num;
	cout <<"\n<<<<< Deposit Transaction >>>>>"<<endl;
	cout <<"Deposit of RM 500 successful.";
}

void withdraw(int &balance, int withdraw_num)
{
	cout<<"\n<<<<< Withdrawal Transaction >>>>>";
	if (withdraw_num <= balance)
	{
		balance = balance- withdraw_num;
		cout<<"\nWithdrawal of RM 200 successful.";
	}
	else
		cout<<"\nInsufficient funds for withdrawal" <<endl;	
}

int main()
{
	int  balance = 200;
	int num =500, withdraw_num= 200;
	char input;
	
	while(input !='N'&& input !='n' )
	{
		displayAccountInfo(balance);
		cout<<endl;
		
		deposit(balance, num);
		cout<<endl;
		
		withdraw(balance, withdraw_num);
		cout<<endl<<endl;	
		
		displayAccountInfo(balance);
		
		cout <<"\n\nDo you want to perform another transaction? (Y/N): ";
		cin >> input;
		cout <<endl;
	}
	return 0;
}

