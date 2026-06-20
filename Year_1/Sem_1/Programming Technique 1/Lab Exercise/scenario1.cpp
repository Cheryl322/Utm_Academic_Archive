//CHERYL CHEONG KAH VOON A23CS0060
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

double calculateKeywordPercentage(double,char[],const char[]);

int main(){
    
    const int MAX_SIZE = 1000;
    char userInput[MAX_SIZE];
    double percentage = 0.0;
    const char keyword[] = "data";
    do{
     
     cout<<"Enter the input ( up to 999 characters, end with an enpty line): "<<endl;
     
     cin.getline(userInput, MAX_SIZE); 
     
    
    }while(userInput=="");
    
    
    
    cout<<"Input:\n"<<userInput<<endl;
    
    percentage = calculateKeywordPercentage(percentage, userInput, keyword);

    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Percentage of line containing 'data': "<<percentage<<"%"<<endl;;
    
    system("pause");
    return 0;
}

double calculateKeywordPercentage(double percentage, char userInput[],const char keyword[]){
    int totalWordCount = 1;
    int keywordCount = 0;
    int inputLength = strlen(userInput);
    int keywordLength = strlen(keyword);

    for (int a = 0; a < inputLength; a++) 
	{
        userInput[a] = tolower(userInput[a]);
    }


    for(int i=0; i<inputLength+1; i++){
        if(userInput[i]== ' ')
            totalWordCount ++;

        if(strstr(userInput + i, keyword) == userInput + i)
            keywordCount++;
    }

    percentage= (static_cast<double>(keywordCount)/totalWordCount)*100;
    return percentage;    
}