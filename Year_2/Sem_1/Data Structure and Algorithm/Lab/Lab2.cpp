// Lab 2 - SECJ2013 - 23241 (Lab2.cpp)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>

using namespace std;

/*void printStar(int n) {
     for (int i = 1; i <= n; i++) {
         cout << "*";
     }
}*/

void printStar(int n){
    if(n==0||n>6){
         
    }
    else{
        cout<<"*";
        printStar(n-1);

    }
}

/*void printNum(int n) {
     for (int i = 1; i <= n; i++) {
         cout << i << " - ";
         printStar(i);
         cout << endl;
     }
}*/

void printNum(int n,int i=1){
    if(i>n){

    }
    else{
        cout<<i<<"-";
        printStar(i);
        cout<<endl;
        printNum(n,i+1);
    }
}

/*int totalOdd(int list[], int n) {
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (list[i] % 2 != 0) {
             cout << list[i] << " ";
             total += list[i];
        }
    }

    return total;
}*/

int totalOdd(int list[],int n){
    if(n==0){
        return 0;
    }
    int num=list[n-1];
    int total=totalOdd(list,n-1);
    if(num%2!=0){
        cout<<num<<" ";
        total+=num;
    }
    return total;
}

// Main function
int main(int argc, char *argv[])
{
    printNum(6);

    cout << "\n\n";

    int num[6] = {0, 1, 2, 3, 4, 5};
    int result = totalOdd(num, 6);
    cout << "= " << result << endl;
    system("pause");
    return 0;
}

