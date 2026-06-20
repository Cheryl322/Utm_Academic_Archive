// LAU YEE WEN A23CS0099
//CHERYL CHEONG KAH VOON A23CS0060
//ASSIGNMENT 2 SET2
#include<iostream>
using namespace std;
int main(){
    int num;

    cout<<"Welcome to the Food Ordering System"<<endl;
    cout<<"1. Pizza - $10"<<endl;
    cout<<"2. Burger - $5"<<endl;
    cout<<"3. Sandwich - $7"<<endl;

    cout<<"Enter the number of the item you want to order: ";
    cin>>num;

    switch(num){
        case 1 : cout<<"Your total bill is : $10"<<endl;
                 break;
        case 2 : cout<<"Your total bill is : $5"<<endl;
                 break;
        case 3 : cout<<"Your total bill is : $7"<<endl; 
                 break;  
        default :cout<<"Invalid order" <<endl;
                 break;            
    }

    cout<<endl;
    cout<<endl;
    system("pause");
    return 0;
}