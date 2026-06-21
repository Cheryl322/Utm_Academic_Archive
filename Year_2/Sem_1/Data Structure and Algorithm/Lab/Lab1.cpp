// Lab 1 - SECJ2013 - 24251 (Lab1.cpp)
// Group Members:
// 1. Chua Jia Lin A23CS0069
// 2. Cheryl Cheong Kah Voon A23CS0060

#include <iostream>
#include <string>
#include<fstream>
#include"Student.h"

using namespace std;

// main function
int main() {
    string n=" ";
    int cw=0,fe=0,list=0;
    const int LIST_SIZE = 10;
    Student* studList[LIST_SIZE];

    fstream infile("Marks.txt",ios::in);
    if (infile){
        while(!infile.eof()){
            infile>>n>>cw>>fe;
            if(list>=LIST_SIZE){
                cout<<"The list is full.\n";
                break;
            }
            studList[list]=new Student(n,cw,fe);
            list++;
        }
        infile.close();
    }else{
        cout<<"Cannot open\n";
    }

    fstream outfile("Results.txt",ios::out);
    if(!outfile){
    	cout<<"File cannot be opened!";
    	return 0;
	}

    cout<<"Student mark info: \n";
    for(int i=0;i<list;i++){
        studList[i]->printInfo();
        cout<<endl;
    }

    cout<<"\n\nPrint and save results to file: \n";
    for(int k=0;k<list;k++){
        studList[k]->printResult();
        studList[k]->printResultFile(outfile);
        delete studList[k];
    }

    outfile.close();

    system("pause");
    return 0;
}
