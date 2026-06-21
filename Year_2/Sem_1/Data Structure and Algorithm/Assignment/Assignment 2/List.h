#include <iostream>
#include <string>

using namespace std;

// List class definition
class List {
    private:
        Student *head, *last;
        
    public:
        List() { 
            cout << "Create list...\n";
            head = NULL; last = NULL;
        }
        
        void insertNode(Student *newStud) {
            Student *prev =NULL;
            Student *curr = head;
            cout << "Insert " << newStud->getName() << "\n";
            
            if(head == NULL){
                head = last = newStud;
            }
            else if(newStud->getName()<=head->getName()){
                newStud->setNext(head);
                head=newStud;
            }

            while(curr!=NULL && curr->getName()<newStud->getName()){
                prev=curr;
                curr = curr->getNext();
            }

            newStud->setNext(curr);
            prev->setNext(newStud);

            if(curr==NULL){
                last = newStud;
            }
        	
        }
        
        Student *findNode(string name) {
            Student *curr = head;
            while(curr!=NULL){
                if(curr->getName() == name){
                    return curr;
                }
                curr->getNext();
            }
            return NULL;
        }
        
        void deleteNode(string name) {
            //cout<<"Found and delete student: "<<name<<endl;
            Student *stud, *prev;
			stud = head;

            while(stud!=NULL){
                prev=stud;
                stud = stud->getNext();
            }
            if(stud == NULL){
                head=head->getNext();
                if(head=NULL){
                    last = NULL;
                }
            }
        }
        
        void displayList() {
        	Student *stud = head;
        	
        	while (stud != NULL) {
        		stud->printResult();
        		stud = stud->getNext();
			}
        }
        
        Student *getHead() { return head; }
        Student *getLast() { return last; }
        
        ~List() {
        	Student *stud = head;
        	cout << "Destroy list...\n";
        	while (stud != NULL) {
        		Student *prevStud = stud;
        		stud = stud->getNext();
        		delete prevStud;
			}
		}
};
