#include<iostream>
#include<iomanip>
using namespace std;

void getInput(double&, double&, double&);
void dispTier(int );
int calcAverage(int, double);
void dispSummary(int);

void getInput(double& score1, double& score2, double& score3){
   do{
      cout<<"Q1 mark: ";
      cin>>score1;
    }while(score1<0 || score1>100);
    do{
     cout<<"Q2 mark: ";
     cin>>score2;
    }while(score2<0 || score2>100);
    do{
     cout<<"Q3 mark: ";
     cin>>score3;
    }while(score3<0 || score3>100);
}

void dispTier(int totalmark){
    cout<<"Tier"<<setw(8)<<": ";
    if(totalmark<40)
      cout<<"Tier 3";
    else if(totalmark<75)  
      cout<<"Tier 2";
    else if(totalmark>=75)
      cout<<"Tier 1" ; 
}

int calcAverage(int numStudent, double total){
    return (total/numStudent);
}

void dispSummary(int totalmark){
    cout<<"Total marks: "<<totalmark<<endl;
    dispTier(totalmark);
}

int main(){
    string studentName,higheststudent,loweststudent;
    double totalmark, score1, score2 ,score3 , total ;//beacuse if int 12/100=0 so need to use double
    int numStudent =0;
    double lowest =999;
    double highest =0;

    do{
        cout<<"<<<<<<<<<<<<<< DATA >>>>>>>>>>>>>\n";
        cout<<"Name"<<setw(5)<<": ";
        getline(cin,studentName);

        if(studentName=="")
           break;
        else
           numStudent++;
        getInput(score1,score2,score3);//task1
        cout<<"<<<<<<<<<<<<< SUMMARY >>>>>>>>>>>"<<endl;
        totalmark=(score1/100*35)+(score2/100*25)+(score3/100*40);
        total+=totalmark;  

        if(totalmark > highest){
           highest = totalmark;
           higheststudent = studentName;
           }
        if( totalmark < lowest){
           lowest = totalmark ;
           loweststudent = studentName;
           }
        
        dispSummary(totalmark);//task4
        cout<<endl<<endl;
        cin.ignore();
    }while(studentName!="");

    cout<<"<<<<<<< RESULTS ANALYSIS >>>>>>>>\n";
    cout<<"Lowest mark  : "<<static_cast<int>(lowest)<<" ("<< loweststudent <<")\n";
    cout<<"Highest mark : "<<static_cast<int>(highest)<<" ("<< higheststudent <<")\n";
    cout<<"Average for "<<numStudent<<" students: "<<static_cast<int>(calcAverage(numStudent,total))<<endl;

    system("pause");
    return 0;
}