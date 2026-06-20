#include<iostream>
#include <string>
#include<iomanip>
#include "admin.hpp"
#include"customer.hpp"
using namespace std;

Admin::Admin() : username("admin123"), password("admin24"){}
Admin::~Admin(){}

bool Admin::checkusername(string uname){
    if(uname==username){
        return true;
    }
    else{
        return false;
    }
}

bool Admin::checkpw(string pw){
    if(pw==password){
        return true;
    }   
    else{
        return false;
    }    
}

void Admin::selection(int &numPremium, int &numTwin, int &numTriple, int &numFamily,double &totalSales){
    int select;
    do{
        cout<<"\n--------------------------\n";
        cout<<right<<setw(15)<<"Menu\n";
        cout<<"--------------------------\n";
        cout<<"1. Check Availability\n2. Check Total Sales\n3. Back to mainpage.\n";
        cout<<"Please select: ";
        cin>>select;
        cout<<endl;
        switch(select){
            case 1: updateavailable(numPremium,numTwin,numTriple,numFamily);
                    break;
            case 2: Sales(totalSales);
                    break;
            case 3: break;
        }
    }while(select!=3);
}

void Admin ::updateavailable(int &numPremium, int &numTwin, int &numTriple, int &numFamily){
    int u1,u2,u3,u4;
    string select1;
    do{
        cout<<"Do you want to update the availability?(Yes/No)\n";
        cin>>select1;
        if(select1=="Yes"){
            cout<<"\n\n\nAvailability\n";
            cout<<"--------------------------\n";
            cout<<"1. Premium Queen: "<<numPremium<<endl;
            cout<<"2. Standard Twin: "<<numTwin<<endl;
            cout<<"3. Family Triple Room: "<<numTriple<<endl;
            cout<<"4. Family Suite: "<<numFamily<<endl;
            cout<<"\nUpdate Availability\n";
            cout<<"--------------------------\n";
            cout<<"Premium Queen: ";
            cin>>u1;
            cout<<"Standard Twin: ";
            cin>>u2;
            cout<<"Family Triple Room: ";
            cin>>u3;
            cout<<"Family Suite: ";
            cin>>u4;
            numPremium +=u1;
            numTwin +=u2;
            numTriple +=u3;
            numFamily +=u4;
            cout<<"\nAvailability\n";
            cout<<"--------------------------\n";
            cout<<"1. Premium Queen: "<<numPremium<<endl;
            cout<<"2. Standard Twin: "<<numTwin<<endl;
            cout<<"3. Family Triple Room: "<<numTriple<<endl;
            cout<<"4. Family Suite: "<<numFamily<<endl;
        }
        if(select1=="No"){
            cout<<"Availability\n";
            cout<<"--------------------------\n";
            cout<<"1. Premium Queen: "<<numPremium<<endl;
            cout<<"2. Standard Twin: "<<numTwin<<endl;
            cout<<"3. Family Triple Room: "<<numTriple<<endl;
            cout<<"4. Family Suite: "<<numFamily<<endl;
        }

        
    }while(select1!="Yes"&&select1!="No");
    
}

void Admin ::Sales(double &totalSales){
    
    cout<<"Total Sales = RM "<<totalSales<<endl;
    
}