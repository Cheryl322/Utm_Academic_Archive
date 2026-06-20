//CHERYL CHEONG KAH VOON A23CS0060
#include <iostream>
#include <cstring>
#include <iomanip>
#include<fstream>
using namespace std;

double calculateKeywordPercentage(double,char*,const char[]);

int main(){
    const int MAX_SIZE = 1000;
    char userInput[MAX_SIZE];
    double percentage = 0.00;
    const char keyword[] = "data";

    ifstream infile("input2.txt");
    ofstream outfile("output2.txt");

    infile.getline(userInput, MAX_SIZE);

    outfile<<"Input:\n";
    outfile<<userInput<<endl;
    
    percentage = calculateKeywordPercentage(percentage, userInput, keyword);

    outfile<<fixed<<showpoint<<setprecision(2);
    outfile<<"Percentage of line containing 'data': "<<percentage<<"%"<<endl;;
    
    infile.close();
    outfile.close();

    cout<<"Results written to 'output.txt'\n"<<endl;

    system("pause");
    return 0;
}

double calculateKeywordPercentage(double percentage,char* userInput,const char keyword[]){
    int totalWordCount = 1;
    int keywordCount = 0;
    int inputLength = strlen(userInput);
    int keywordLength = strlen(keyword);

    for (int a = 0; a < inputLength; a++) 
	{
        userInput[a] = static_cast<char>(tolower(userInput[a]));
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