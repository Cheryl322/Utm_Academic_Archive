#include<iostream>
using namespace std;

const int MAX_OPERATION = 100;

int operand1[MAX_OPERATION];
int results[MAX_OPERATION];

int  multiplyUsingAddition(int,int);
void displayMainMenu();
void performMultiplication(int&);
void displayResults(int&);

int main(){
    int operationCount = 0;
    int choice;

    do{
      displayMainMenu();
      cout<<"Enter your choice: ";
      cin>>choice;

      switch(choice){
        case 1: performMultiplication(operationCount);
                break;
        case 2: displayResults(operationCount);
                break;
        case 3: cout << "\n\nGoodbye!\n\n"<<"-------------------------------\n\n"; 
                break;
        default : cout<<" Invalid choice. Please enter a number between 1-3\n\n";                
      }
    }while(choice!=3);

    system("pause");
    return 0;
}

int  multiplyUsingAddition(int a, int b){
    int result =0;
    for(int i=0; i<b; i++)
        result += a;
    return result;
}

void displayMainMenu(){
    cout<<"<<<<<Main Menu>>>>>\n\n";
    cout<<"=====================================\n\n";
    cout<<"1. Perform Multiplication\n";
    cout<<"2. Display Result\n";
    cout<<"3. Quit\n";

}

void performMultiplication(int &operationCount){
    int result=1;
    int operand;
    cout<<"\n\nEnter the number of operands for multiplication: ";
    cin>>operand1[operationCount];

    for(int i=0; i<operand1[operationCount]; i++){
        cout<<"\nEnter operand "<<(i+1)<<": ";
        cin>>operand;
        result=multiplyUsingAddition(result,operand);
    }
    cout<<"\n\nMultiplication performed successfully!\n\n";
    results[operationCount]=result;
    operationCount++;
}

void displayResults(int &operationCount){
    if(operationCount > 0){
      cout<<"\n\nResult of Mathematical Operations: \n\n";
      cout<<"==================================================\n\n";
      for(int i=0; i<operationCount; i++){
         cout<<"Operation "<< (i+1) <<": "<< results[i]<<" (Operands: "<<operand1[i]<<")\n\n";
         }
    }
    else{
        cout<<"\nNo Operation performed. \n";
    }     
}
