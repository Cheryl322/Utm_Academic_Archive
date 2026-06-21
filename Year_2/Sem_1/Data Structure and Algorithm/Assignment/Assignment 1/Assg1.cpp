// Assignment 1 - SECJ2013 - 23241 (Assg1.cpp)
// Group Members:
// 1. ???
// 2. ???
// 3. ???

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"

using namespace std;

// function headers
void listStudent(Student* [], int);
void sortByGrade(Student* [], int);
void sortByName(Student* [], int);

// main function
int main() {
    const int LIST_SIZE = 10;
    string name;
    int cw, fe, idx = 0;
    Student* studList[LIST_SIZE];

    fstream fileIn("Marks.txt", ios::in);

    if (!fileIn) {
        cout << "File input/output error!\n";
        return 1;

    } else {
        while (fileIn >> name >> cw >> fe) {
            studList[idx] = new Student(name, cw, fe);
            idx++;
        }
        
        int opt = 0;

        while (opt != 4) {
            cout << "\n1. List results (original list)";
            cout << "\n2. List results (sort by name)";
            cout << "\n3. List results (sort by grade)";
            cout << "\n4. Exit\n\n";
            
            cout << "Enter your choice [1, 2, 3, 4]: ";
            cin >> opt;
            
            if (opt == 1) {
                listStudent(studList, idx);
            }
            else if(opt == 2){
                sortByName(studList, idx);
                listStudent(studList, idx);
            }
            else if(opt == 3){
               sortByGrade(studList, idx);
               listStudent(studList, idx);
            }
            
            if (opt != 4) system("pause");
        }

        fileIn.close();
    }
    return 0;
}

// function implementation
void listStudent(Student* sl[], int size) {
    for (int i = 0; i < size; i++) {
        sl[i]->printResult();
    }
}

void sortByGrade(Student *sl[], int size){
    for(int last=size -1;last>=1;--last){
        int largest=0;
        for(int j=1;j<=last;++j){
            if(sl[j]->getGrade() > sl[largest]->getGrade() || (sl[j]->getGrade() == sl[largest]->getGrade()) && sl[j]->getName() > sl[largest]->getName()){
                largest=j;
            }
            Student * temp=sl[largest];
            sl[largest]=sl[last];
            sl[last]=temp;
        }
    }
}

void sortByName(Student *sl[], int size){
    for(int last=size -1;last>=1;--last){
        int largest=0;
        for(int j=1;j<=last;++j){
            if(sl[j]->getName() > sl[largest]->getName()){
                largest=j;
            }
            Student * temp=sl[largest];
            sl[largest]=sl[last];
            sl[last]=temp;
        }
    }
}
