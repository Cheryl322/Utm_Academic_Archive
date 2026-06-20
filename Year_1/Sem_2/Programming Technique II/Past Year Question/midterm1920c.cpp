#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;

class Student {
    private:
        string name;
        string matric_number;
        float GPA;
        float CGPA;
        int credit;
        int total_credit;
        string status;
    public:
        Student(string n="", string m_c="", float c=0.0, int _credit=0){
            name=n;
            matric_number=m_c;
            GPA = 0.0;
            CGPA=c;
            credit=_credit;
            total_credit = 0;
            updateCGPA ();
        }
        
        string getName() const{return name;}

        string getStatus() {
            if(CGPA <1.7)
                status = "Fail ";
            else if (CGPA>=1.7 && CGPA<2.0)
                status = "Probation ";
            else 
                status = " Good ";
            return status;
        }

        void updateCGPA(){
            float new_CGPA;
            new_CGPA = ((GPA*credit)+ (CGPA *total_credit))/(credit+total_credit);
        }

        void readInput(){
            cout<<"\n<<< Input >>>"<<endl;
            cout<<"Name: ";
            getline(cin,name);
            cout<<"Matric Number: ";
            getline(cin,matric_number);
            cout<<"CGPA: ";
            cin>>CGPA;
            cout<<"Total Credit: ";
            cin>>credit;
            cout<<"GPA: ";
            cin>>GPA;
            cout<<"Credit earned this semester: ";
            cin>>total_credit;

            updateCGPA();
        }

        bool operator==(Student right){
            if(status==right.status)
                return true;
            else
                return false;
        }

        friend void dispInfo(Student &obj){
            int year = stoi(obj.matric_number.substr(1,2));
            int years;
            if(year<20)
                years=20-year;
            else
                years=100-year+20;
            string course=obj.matric_number.substr(3,2);
            string program;
            if(course=="CS")
                program="Computer Science";
            else if(course=="EC")
                program="Engineering Computing";
            else
                program="Non Computing Program";

            cout<<"You are in year "<<years<<" in "<<program;
        }

        friend ostream &operator<<(ostream &os ,Student &S){
            os<<"Hello, "<<S.name<<endl;
            dispInfo(S);
            os<<"\nYour matric number is "<<S.matric_number<<endl;;
            os<<"Your current CGPA is " <<fixed<<showpoint<<setprecision(2)<<S.CGPA<<endl;
            os<<"Your status is "<<S.getStatus()<<endl;
            if(S.CGPA>=3.67)
                os<<"CONGRATULATIONS. You are awarded DEANs LIST";
            return os;
        }


};

int main(){

    Student p1={"","",0.0, 0};
    Student p2={"Hashim Abu", "A17CS1234",4.0, 18};
    cout<<"CGPA Calculator"<<endl;
    p1.readInput();
    cout<<endl;
    cout<<"<<< Output >>>"<<endl;
    cout<<p1<<endl;
    cout<<p2;
    cout<<"\n\n**Note: "<<p1.getName()<<" and "<<p2.getName()<<" have ";
    if(p1==p2){
        cout<<p1.getStatus();
    }
    else
        cout<<"different";
    cout<<" status."<<endl;

    system("pause");
    return 0;

}
