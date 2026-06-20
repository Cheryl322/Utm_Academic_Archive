#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void readQty (int&,int&,int&);
void displayHighProd(double,double,double);
double calcAverg(int, double);
void summaryCom(double,double,double,double);
//task5
int main(){
    string Agentname,lowcomAgent, highcomAgent,highcomAgentA,highcomAgentB,highcomAgentC;
    int qtyA,qtyB,qtyC;
    int numAgent=0;
    double totalA,totalB,totalC,totalallcom,total,lowestcom,highestcom,highestcomA,highestcomB,highestcomC;
    qtyA = 0;
    qtyB = 0;
    qtyC = 0;
   
   while(true){
      cout<<"------------------- AGENT -------------------\n";
      cout<<"Agent Name: ";
      cin.ignore();
      getline(cin, Agentname);
         if (Agentname.empty()) {
               break;
        }
	  numAgent++;	
      cout<<endl;

       readQty (qtyA, qtyB, qtyC);//task1

       totalA =qtyA *((150*0.025));
       totalB =qtyB *((300*0.05));
       totalC =qtyC *((450*0.1));

       totalallcom = totalA + totalB + totalC;
       total += totalallcom;
       summaryCom(totalA,totalB,totalC,totalallcom);//task4

        if (numAgent == 1){
			lowestcom = totalallcom;
			highestcom = totalallcom;
			highestcomA = totalA;
			highestcomB = totalB;
			highestcomC = totalC;
			lowcomAgent = Agentname;
			highcomAgent = Agentname;
			highcomAgentA = Agentname;
			highcomAgentB = Agentname;
			highcomAgentC = Agentname;
            }
        else{ 
            if(totalallcom<lowestcom){
               lowestcom = totalallcom;
               lowcomAgent = Agentname;
            }
            if(totalallcom>highestcom){
                highestcom = totalallcom;
                highcomAgent = Agentname;
            }
            if(highestcomA < totalA){
                highestcomA = totalA;
                highcomAgentA = Agentname;
            }
            if(highestcomB < totalB){
                highestcomB = totalB;
                highcomAgentB = Agentname;
            }
            if(highestcomC < totalC){
                highestcomC = totalC;
                highcomAgentC = Agentname;
            }
        
        }

     
    }
    cout<<"------------------ SALES ANALYSIS -----------------\n";
    cout<<"Lowest commission for three products: RM"<<lowestcom<<"( "<<lowcomAgent<<" )"<<endl;
    cout<<"Highest commission for three products: RM"<<highestcom<<"( "<<highcomAgent<<" )"<<endl;
    cout<<"Highest commission for Product A: RM"<<highestcomA<<"( "<<highcomAgentA<<" )"<<endl;
    cout<<"Highest commission for Product B: RM"<<highestcomB<<"( "<<highcomAgentB<<" )"<<endl;
    cout<<"Highest commission for Product C: RM"<<highestcomC<<"( "<<highcomAgentC<<" )"<<endl;
    cout<<"Total of commission for "<<numAgent<<" agents: RM"<<total<<endl;
    cout<<"Average commission for "<<numAgent<<" agents: RM"<<calcAverg(numAgent, total)<<endl;
    system("pause");
    return 0;
}
//task1
void readQty (int &qtyA, int &qtyB, int &qtyC){
    do{
    cout<<"Product A: ";
    cin>>qtyA;}while(qtyA<0 || qtyA >100);
    do{
    cout<<"Product B: ";
    cin>> qtyB;}while(qtyB<0 || qtyB>100);
    do{
    cout<<"Product C: ";
    cin>> qtyC;
    }while(qtyC<0 || qtyC>100 );
}
//task2
void displayHighProd(double totalA,double totalB,double totalC ){

    cout<<"\nHighest commission - Product ";
     if(totalA > totalB && totalA > totalC)
       cout<<"Product A: RM"<<totalA<<endl;
    else if (totalB > totalA && totalB > totalC) 
       cout<<"Product B: RM"<<totalB<<endl;
    else
       cout<<"Product C: RM"<<totalC<<endl; 
    
    
}
//task3
double calcAverg(int numAgent,double total){

    return (total/numAgent);
}
//task4
void summaryCom(double totalA,double totalB,double totalC,double totalallcom){
    cout<<"------------------ SALES SUMMARY -------------------\n";

    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Total of commision for three products: RM"<<totalallcom;
    displayHighProd(totalA,totalB,totalC);
}