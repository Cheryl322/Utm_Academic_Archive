#include<iostream>
#include<iomanip>
#include "customer.cpp"
#include "admin.cpp"
#include "receipt.cpp"
using namespace std;


int main(){

    int role;
    string uname, pw;
    int numPremium = 70, numTwin = 70, numTriple = 60, numFamily = 50;
    double totalSales =0.0;
    Customer customer;
    Admin admin;
    //Receipt receipt;

    do{
        cout<<"--------------------------------------------------"<<endl;
        cout<<right<<setw(37)<<"Hotel Reservation System"<<endl;
        cout<<"--------------------------------------------------"<<endl;
        cout<<"Role: \n1. Customer\n2. Admin\n3. Exit\n\nPlease select your role:";
        cin>>role;
        switch(role){
            case 1: cout<<"--------------------------------------------------\n";
                    cout<<right<<setw(29)<<"Customer\n";
                    cout<<"--------------------------------------------------\n";
                    customer.enterInformation();
                    customer.availability(numPremium,numTwin,numTriple,numFamily);
                    customer.selectPaymentMethod();
                    customer.printReceipt(totalSales);
                    cout<<"Thank you. Have a nice trip!"<<endl<<endl;
                    break;
            case 2: cout<<"---------------------------------------------------\n";
                    cout<<right<<setw(30)<<"Admin\n";
                    cout<<"--------------------------------------------------\n";
                    while(true){
                        cout<<"Please Enter Your Username and Password"<<endl;
                        cout<<"Username: ";
                        cin>>uname;
                        if(admin.checkusername(uname)){
                            cout<<"Password: ";
                            cin>>pw;
                            if(admin.checkpw(pw)){
                                admin.selection(numPremium,numTwin,numTriple,numFamily,totalSales);
                                break;
                            }
                            else{
                            cout<<"Wrong Password. Please enter again your username and password.\n\n";
                            //break;
                            }
                            //break;
                        }
                        else{
                            cout<<"Wrong Username. Please enter again your username and password.\n\n";
                            //break;
                        }
                    }break;
                    
            case 3: cout<<"\nThank you for choosing our hotel reservation system."<<endl<<endl;
                    break;
        }

    }while(role!=3);
   
    system("pause");
    return 0;
}