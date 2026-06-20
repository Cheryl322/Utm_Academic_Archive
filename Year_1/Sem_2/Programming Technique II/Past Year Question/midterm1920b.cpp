#include <iostream>
#include<cstring>
#include<string>
#include<iomanip>

using namespace std;

class Person{
    private:
        string name;
        string NRIC;
        double height;
        double weight;
        int activity_level;
        double BMR;
        double calories;
    
    public:
        Person(string n="", double h=0.0, double w=0.0, int a=0){
            name=n;
            NRIC ="";
            height=h;
            weight=w;
            activity_level=a;
        }
        
        string getName ()const {return name;}

        string getGender()const{
            string gender;
            if(NRIC.substr(11,1)== "1" || NRIC.substr(11,1)== "3" || NRIC.substr(11,1)== "5" || NRIC.substr(11,1)== "7" ||NRIC.substr(11,1)== "9")
                return "Male";
            else
            //else if(NRIC.substr(12,1)== "0" || NRIC.substr(12,1)== "2" || NRIC.substr(12,1)== "4" || NRIC.substr(12,1)== "6" ||NRIC.substr(12,1)== "8")
                return "Female";   
            //else
                //return "Error" ;
        }
        int getAge ()const {
            //int age;
            //int birthyear=stoi(NRIC.substr(0,2));
            //age =
            string temp=NRIC.substr(0,2);
            int year=stoi(temp);
            int age;
            if(year<=20)
            {
                age=20-year;
            }
            else
            {
                age=100-year+20;
            }
            return age; 
        }
        void calcCalorie (){
            if(getGender()=="Male")
                BMR =(10*weight)+(6.25*height)-(5*getAge())+5;
            else
                BMR =(10*weight)+(6.25*height)-(5*getAge())-161;

            if(activity_level==1)
                calories=BMR*1.2;
            else if(activity_level==2)
                calories=BMR*1.375;
            else if(activity_level==3)
                calories=BMR*1.55;
            else if(activity_level==4)
                calories=BMR*1.725;
            else if(activity_level==5)
                calories=BMR*1.9;
            else
                cout<<"Error";
        }
        void readInput (){
            cout<<"<<< Input >>>"<<endl;
            //cin.ignore();
            cout<<"Name: ";
            getline(cin,name);
            cout<<"NRIC Number (without hyphen'-'): ";
            getline(cin,NRIC);
            cout<<"Height (in meter): ";
            cin>>height;
            cout<<"Weight (in kg): ";
            cin>>weight;
            cout<<"Choose the activity level: 1-Sedentary, 2-Lightly Active, 3-Moderately Active, 4-Very Active, 5-Extra Active"<<endl;
            cout<<"Activity level (1 - 5): ";
            cin>>activity_level;
        }
        bool operator==(Person right){
            if (activity_level==right.activity_level)
                return true;
            else
                return false;
        }
        friend void dispInfo(Person &obj);
        //{
            //cout<<endl;
            //cout<<"<<< Output>>> "<<endl;
        //}
        friend ostream& operator<<(ostream &strm, Person &P)
        {
            strm<<"Hello, "<<P.name<<endl;
            dispInfo(P);             
            strm<<"Your height is "<<fixed<<showpoint<<setprecision(2)<<P.height<<" cm"<<endl
                <<"Your weight is "<<fixed<<showpoint<<setprecision(2)<<P.weight<<" kg"<<endl
                <<"Your BMR is "<<fixed<<showpoint<<setprecision(2)<<P.BMR<<" kcal/day"<<endl
                <<"Your calorie based on activity level is "<<fixed<<showpoint<<setprecision(2)<<P.calories<<" kcal/day"<<endl;
            return strm;
        }

};

void dispInfo(Person &obj)
{
    cout<<"Your gender is "<<obj.getGender()<<endl
        <<"Your age is "<<obj.getAge()<<" years old"<<endl;
}

int main(){
    Person p1={"",0.0,0.0,0};
    Person p2={"Alisa Hashim",150,50,2};
    p1.readInput();
    p1.calcCalorie(); 
    cout<<"<<< Output>>> "<<endl;
    cout<<endl;
    cout<<p1;
    if(p1==p2) 
    {
        cout<<"**Note: "
            <<p1.getName()<<" and "<<p2.getName()<<" have same activity level."<<endl;
    }
    else
    {
        cout<<"**Note: " <<p1.getName()<<" and "<<p2.getName()<<" have different activity level."<<endl;
    }


    system("pause");
    return 0;

}