#include<iostream>
#include<iomanip>
using namespace std;

void dispStatus(int);
void getInput(int&, int&, int&, int&);
void dispOutput(int);
double calcAverage(int,int);

void dispStatus(int activecase){
    string status;
    if(activecase>40)
      status = "Red Zone";
    else if(activecase>=21 && activecase<=40)  
      status = "Orange Zone";
    else if(activecase>=1 && activecase<=20) 
      status = " Yellow Zone";
    else if(activecase==0) 
      status = "Green Zone"  ;

    cout<<"Status"<<setw(9)<<": "<<status<<endl;  
}

void getInput(int &totalcase, int &newcase, int &totaldeath, int &totalrecovered){
    cout<<"Total cases"<<setw(6)<<": ";
    cin>>totalcase;
    cout<<"New cases"<<setw(8)<<": ";
    cin>>newcase;
    cout<<"Total death"<<setw(6)<<": ";
    cin>>totaldeath;
    cout<<"Total recovered: ";
    cin>>totalrecovered;
    cout<<endl;
}

void dispOutput(int activecase){
    cout<<"Active cases"<<setw(3)<<": "<<activecase<<endl;
    dispStatus(activecase);
}

double calcAverage( int numofState, int totalactivecase){
    return (totalactivecase/numofState);
}

int main(){
  string continueloop;
  string statename,highstatename;
  int totalcase=0,newcase=0,totaldeath=0,totalrecovered=0,totalactivecase=0,numofState=0;
  int activecase=0,highest=0;

  do{
    cout<<endl;
    cout<<"<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>>"<<endl;
    cout<<"State Name"<<setw(7)<<": ";
    getline(cin,statename);

    getInput(totalcase,newcase,totaldeath, totalrecovered);
    numofState++;
        
    cout<<"<<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>>>>"<<endl;

    activecase = totalcase + newcase - totaldeath - totalrecovered;
    dispOutput(activecase);

    if(activecase>highest){
      highest = activecase;
      highstatename= statename;
    }
    totalactivecase+=activecase;
    cout<<endl;
    cin.ignore();
    cout<<"Press <ENTER> to continue...";
    getline(cin,continueloop);
    if(continueloop!="\0")
      break;
    
  }while(continueloop=="\0");
  calcAverage(numofState,totalactivecase);
  cout<<endl;
  cout<<"<<<<<<<<<< ACTIVE CASES >>>>>>>>>>"<<endl;
  cout<<"Total  : "<<totalactivecase<<endl;
  cout<<"Highest: "<<highest<<" ("<< highstatename <<")"<<endl;
  cout<<"Average for "<<numofState<<" states: "<<calcAverage(numofState, totalactivecase)<<endl; 
  system("pause");
  return 0;
}