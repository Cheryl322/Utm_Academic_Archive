// ? EXERCISE 2: CLASS AND OBJECT MANIPULATIONS

// Programming Technique II
// Semester 2, 2021/2022

// Section: 01
// Member 1's Name: _____________    Location: ____________ (i.e. where are you currently located)
// Member 2's Name: _____________    Location: ____________
//
// Date and time of pair programming sessions:
//   _________  (Date, time and estimate duration)
//   _________  (Date, time and estimate duration)
//
// Video link:
//   _________

// ? Notes: Choose the debug mode "Console Program" to run the program.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define MAX_SUBJECT_COUNT 10

class Subject
{
private:
	string name;
	string code;
	int score;
   

public:
	Subject();
	int credit() const;
	string grade() const;
	double point() const;
	void print() const;
    friend int readUserInput(Subject subjects[]);
	bool operator <( Subject &other)const;
};

Subject lower(Subject,Subject);

int main()
{    
    Subject subjects [MAX_SUBJECT_COUNT];
	double subTotal;
	int num_subject=readUserInput(subjects);

	cout << endl
		 << endl
		 << "THE RESULT"
		 << endl
		 << endl;

	// Print the output table header
	cout << left << setw(15) << "Subject Code";
	cout << left << setw(30) << "Subject Name";
	cout << left << setw(10) << "Credit";
	cout << left << setw(10) << "Score";
	cout << left << setw(10) << "Grade";
	cout << left << setw(10) << "Point";
	cout << left << setw(10) << "Sub Total";
	cout << endl
		 << endl;

	int total_credit=0;
	double total_point =0, gpa=0;

	for(int i=0; i<num_subject;i++)
	{
		subjects[i].print();
		total_credit+=subjects[i].credit();
		total_point+=(subjects[i].point()*subjects[i].credit());
	}

	gpa = total_point/total_credit;

	cout << endl;
	cout << "TOTAL POINT  : " << total_point <<endl;
	cout << "TOTAL CREDIT : " <<total_credit <<endl;
	cout << "GPA          : " << setprecision(3) <<gpa <<endl;

	cout << endl;
	cout << "LOWEST SUBJECT : " << endl;
	
	Subject lowest_subject=subjects[0];
    for (int i = 1; i < num_subject; i++)
    {
        lowest_subject = lower(lowest_subject,subjects[i]);
    }
    lowest_subject.print();

	cout<<endl;

	system("pause");

	return 0;
}

// The definition of the default constructor is fully given
Subject::Subject() : name(""), code(""), score(0) {}

// The definition of the getter for the 'credit()' is fully given
int Subject::credit() const { return code[7] - '0'; }

// The definition of the getter for the 'grade()' is fully given
string Subject::grade() const
{
	if (score >= 90)
		return "A+";
	if (score >= 80)
		return "A";
	if (score >= 75)
		return "A-";
	if (score >= 70)
		return "B+";
	if (score >= 65)
		return "B";
	if (score >= 60)
		return "B-";
	if (score >= 55)
		return "C+";
	if (score >= 50)
		return "C";
	if (score >= 45)
		return "C-";
	if (score >= 40)
		return "D+";
	if (score >= 35)
		return "D";
	if (score >= 30)
		return "D-";
	return "E";
}

double Subject ::point() const
{
	string gradeearn = grade();
	if (gradeearn == "A+")
		return 4.00;
	if (gradeearn == "A")
		return 4.00;
	if (gradeearn == "A-")
		return 3.67;
	if (gradeearn == "B+")
		return 3.33;
	if (gradeearn == "B")
		return 3.00;
	if (gradeearn == "B-")
		return 2.67;
	if (gradeearn == "C+")
		return 2.33;
	if (gradeearn == "C")
		return 2.00;
	if (gradeearn == "C-")
		return 1.67;
	if (gradeearn == "D+")
		return 1.33;
	if (gradeearn == "D")
		return 1.00;
	if (gradeearn == "D-")
		return 0.67;
	return 0.00;
}

void Subject ::print() const
{
	double subTotal = point() * credit();
	
		cout << left << setw(15) << code;
		cout << left << setw(30) << name;
		cout << left << setw(10) << credit();
		cout << left << setw(10) << score;
		cout << left << setw(10) << grade();
		cout << left << setw(10) << point();
		cout << left << setw(10) << subTotal;
		cout<<endl;
	
}

bool Subject::operator <( Subject &other)const
{
	if(this->score<other.score)
		return true;
	else
		return false;

}

// Define a regular function that read a list of subjects from user input
int readUserInput(Subject subjects[])
{   int num_subject = 0;
    cout<<"How many subjects do you want to enter? =>";
    cin>>num_subject;
    for (int i =0; i<num_subject;i++){
		cout<<endl;
        cout<<"Enter info for subject #"<<(i+1)<<":"<<endl;
        cout<<"Subject Code => ";
        cin>>subjects[i].code;
		cin.ignore();
        cout<<"Subject name => ";
        getline(cin, subjects[i].name);
        cout<<"Score earned => ";
        cin>>subjects[i].score;
    }
	return num_subject;
}

// Define a regular function that determines the lower subject.
Subject lower(Subject a, Subject b)
{
	if (a<b)
		return a;
	else 
		return b;
}