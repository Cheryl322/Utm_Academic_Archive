#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstdlib>

using namespace std;

class WordNumber {
    private:
        string data;
    public:
        WordNumber(string _d="zero"){
            data=_d;
        }
        WordNumber(int num){
            switch (num){
                case 0 : data="zero";
                        break;
                case 1 : data="one";
                        break;
                case 2 : data="two";
                        break;
                case 3 : data="three";
                        break;
                case 4 : data="four";
                        break;
                case 5 : data="five";
                        break;
                case 6 : data="six";
                        break;
                case 7 : data="seven";
                        break;
                case 8 : data="eight";
                        break;
                case 9 : data="nine";
                        break;
                default : data=" ";
            }

        }

        string setData (){ }

};