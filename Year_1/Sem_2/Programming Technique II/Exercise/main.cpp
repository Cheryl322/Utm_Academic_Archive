// ? EXERCISE 1: INTRODUCTION TO CLASSES AND OBJECTS

// Programming Technique II
// Semester 2, 2023/2024

// Section: 01
// Member 1's Name: Chua Jia Lin    Location: Teluk Intan, Perak. (i.e. where are you currently located)
// Member 2's Name: Cheryl Cheong Kah Voon    Location: Johor Bahru, Johor
//
// Date and time of pair programming sessions:
//   6/4/24, 9.10pm - 10.20pm  (Date, time and estimate duration)
//   _________  (Date, time and estimate duration)
// 
// Video link:
//   _________  

// ? Notes: Choose the debug mode "Console Program" to run the program.

#include <iostream>
#include <string>

using namespace std;

class Subject{
	private:
	    std::string name;
		std::string code;
		int score;
	public:
	    //parameterized constructor
	    Subject(std::string subject_name,std::string subject_code,int subject_score){
			name=subject_name;
			code=subject_code;
			score=subject_score;
		}

        //default constructor
		Subject(){}

		//destructor
		~Subject(){}

		std::string getName()const{
			return name;
		}

        std::string getCode()const{
			return code;
		}
        
		int getScore()const{
			return score;
		}

		void setName(std::string subject_name){
            name=subject_name;
		}

		void setCode(std::string subject_code){
            code=subject_code;
		}

		void setScore(int subject_score){
			score=subject_score;
		}

		std::string determineGrade(int score)const{
            if(score>=90&&score<=100) return "A+";
            else if(score>=80&&score<=89) return "A";
            else if(score>=75&&score<=79) return "A-";
            else if(score>=70&&score<=74) return "B+";
            else if(score>=65&&score<=69) return "B";
            else if(score>=60&&score<=64) return "B-";
            else if(score>=55&&score<=59) return "C+";
            else if(score>=50&&score<=54) return "C";
            else if(score>=45&&score<=49) return "C-";
            else if(score>=40&&score<=44) return "D+";
            else if(score>=35&&score<=39) return "D";
            else if(score>=30&&score<=34) return "D-";
            else return "E";
        }

        double determinePointValue(int score)const{
            std::string grade=determineGrade(score);
            if(grade=="A+") return 4.00;
            else if(grade=="A") return 4.00;
            else if(grade=="A-") return 3.67;
            else if(grade=="B+") return 3.33;
            else if(grade=="B") return 3.00;
            else if(grade=="B-") return 2.67;
            else if(grade=="C+") return 2.33;
            else if(grade=="C") return 2.00;
            else if(grade=="C-") return 1.67;
            else if(grade=="D+") return 1.33;
            else if(grade=="D") return 1.00;
            else if(grade=="D-") return 0.67;
            else return 0.00;
        }
		
        double determineGradePointEarned(int credit_hour,int score)const{
            return determinePointValue(score)*credit_hour;
        }
};

int main()
{
	std::string name, code;
	int score,credit_hour;
	Subject s1;

	cout << "Enter the following data: " << endl;
	cout << "  Subject name => ";
	getline(cin,name);
	s1.setName(name);
	cout << endl;

	cout << "  Subject code => ";
	cin>> code;
	s1.setCode(code);
	cout << endl;

	cout << "  Score earned => ";
	cin>>score;
	s1.setScore(score);
	cout << endl;
    
    credit_hour=code.back()-'0';

	cout << endl
		 << endl;

	cout << "THE RESULT" << endl
		 << endl;

	cout << "Subject Code : " <<s1.getCode()<< endl;
	cout << "Subject Name : " <<s1.getName()<< endl;
	cout << "Credit Hour  : " <<credit_hour<< endl;
	cout << "Score Earned : " <<s1.getScore()<< endl;
	cout << "Grade Earned : " <<s1.determineGrade(score)<< endl;
	cout << "Grade Point  : " <<s1.determinePointValue(score)<< endl;
	cout << "Point Earned : " <<s1.determineGradePointEarned(credit_hour,score)<< endl;
	cout << endl;

	system("pause");

	return 0;
}

