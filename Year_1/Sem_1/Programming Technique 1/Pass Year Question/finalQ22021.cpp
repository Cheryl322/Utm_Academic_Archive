#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
//task 1
struct Employee{
    string Name;
    string Department;
    double basicSalary;
    int otHour;
    double otPay;
    double totalPay;
};

int readInput(Employee []);
double determineRate(string );
void displayOutput(Employee [], int );
void displayAnalysis(Employee [], int );
//task 2
int readInput(Employee employee[]){
    int numEmployee=0;
    ifstream inFile("input.txt");
    if(!inFile){
        cout<<"Error\n";
    }
    while(inFile>>employee[numEmployee].Department){
    
       inFile>>employee[numEmployee].basicSalary;
       inFile>>employee[numEmployee].otHour;
       getline(inFile,employee[numEmployee].Name );
       numEmployee++;
    }
    inFile.close();
    return numEmployee;
}
//task 3
double determineRate(string Department){
   double otRATE;
    if(Department=="Quality")
        otRATE= 11.5;
    if(Department=="Production")
        otRATE= 10.0;
    if(Department=="Accounting")
        otRATE= 12.5;
    if(Department=="Engineering")
        otRATE= 15.0;
    return otRATE;   
}
//task 4
void displayOutput(Employee employee[], int numEmployee){
    cout<<"------------------------------------------------------------------------------\n";
    
    cout<<left;
    cout<<setw(20)<<"NAME"<<setw(15)<<"DEPARTMENT"<<setw(11)<<"BASIC(RM)"<<setw(10)<<"OT(HOUR)"<<setw(12)<<"OT PAY(RM)"<<setw(10)<<"SALARY(RM)"<<endl;
    
    cout<<"------------------------------------------------------------------------------\n";
    for(int i=0;i<numEmployee;i++){

        double otRATE = determineRate(employee[i].Department);
        employee[i].otPay = otRATE *(employee[i].otHour);
        employee[i].totalPay = employee[i].otPay + employee[i].basicSalary; 
        cout<<left<<fixed<<showpoint<<setprecision(2);
        cout<<setw(20)<<employee[i].Name<<setw(15)<<employee[i].Department;
        cout<<fixed<<showpoint<<setprecision(2);
        cout<<setw(11)<<employee[i].basicSalary<<setw(10)<<employee[i].otHour<<setw(12)<<employee[i].otPay<<employee[i].totalPay<<endl;
    }
    
}
//task 5
void displayAnalysis(Employee employee[], int numEmployee){
    double totalotPayP=0,totalotPayQ=0,totalotPayE=0,totalotPayA=0;
    double totalsalaryP=0,totalsalaryQ=0,totalsalaryE=0,totalsalaryA=0;
    for(int i=0;i<numEmployee;i++){

        if(employee[i].Department=="Production"){
            totalotPayP += employee[i].otPay;
            totalsalaryP += employee[i].totalPay;
        }
        else if(employee[i].Department=="Quality"){
            totalotPayQ += employee[i].otPay;
            totalsalaryQ += employee[i].totalPay;
        }
        else if(employee[i].Department=="Engineering"){
            totalotPayE += employee[i].otPay;
            totalsalaryE += employee[i].totalPay;
        }
        else if(employee[i].Department=="Accounting"){
            totalotPayA += employee[i].otPay;
            totalsalaryA += employee[i].totalPay;
        }

    }
    cout<<"------------------------------------------------------------------------------\n";
    
    cout<<left<<fixed<<showpoint<<setprecision(2);
    cout<<setw(27)<<"DEPARTMENT"<<setw(30)<<"TOT. OT PAY(RM)"<<setw(21)<<"TOT. SALARY(RM)"<<endl;
    cout<<setw(30)<<"Production"<<setw(30)<<totalotPayP<<setw(18)<<totalsalaryP<<endl;
    cout<<setw(30)<<"Quality"<<setw(30)<<totalotPayQ<<setw(18)<<totalsalaryQ<<endl;
    cout<<setw(30)<<"Engineering"<<setw(30)<<totalotPayE<<setw(18)<<totalsalaryE<<endl;
    cout<<setw(30)<<"Accounting"<<setw(30)<<totalotPayA<<setw(18)<<totalsalaryA<<endl;

    cout<<"------------------------------------------------------------------------------\n";
}

int main(){

    const int MAX_EMPLOYEE = 50;
    Employee employee[MAX_EMPLOYEE];
    int numEmployee;

    numEmployee = readInput(employee);
    displayOutput(employee,numEmployee);
    displayAnalysis(employee,numEmployee);

    system("pause");
    return 0;
}