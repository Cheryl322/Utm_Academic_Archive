#include<iostream>
using namespace std;

double getAmount(){
    double spent;
    while(spent<=0){
        cout<<"Please enter the amount spent :";
        cin>>spent;
        return spent;
    }
}

void times (float& timein,float& timeout){
    do{
     cout<<"Please enter the punch in time (HH.MM) : ";
     cin>>timein;
    
    cout<<"Please enter the punch out time (HH.MM) : ";
    cin>>timeout; 
    validTime();
    }while(timeout<timein);
}

