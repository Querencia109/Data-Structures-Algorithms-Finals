#include <iostream>
using namespace std;

struct student {
	char idnum[10];
	char course[10];
	float grade;
	student *ptr;
};

typedef student st;

void display(st *rec, st *nxt) {
	cout << "-------------------------------------------------" << endl;
	cout << "Display Records:" << endl;
	nxt = rec;
	while(nxt) {
		cout << "Student Number: " << nxt->idnum << "\tCourse: "
			<< nxt->course <<"\tGrade: " << nxt->grade << endl;
			nxt = nxt->ptr;
	}
}

int main() 
{
	st *head = NULL;
	st *curr;
	st *temp;
	
	//(1) Inserting 5 Record in the list in reverse
	for(int i = 1; i <= 5; i++) {
		curr = new st;
		fflush(stdin);
		cout << "Insert Record [" << i <<"]" << endl;
		cout << "Enter Student Number: ";
	 	cin.getline(curr->idnum,10);
	 	cout<<"Enter Student course: ";
	 	cin.getline(curr->course,10);
	 	cout<<"Enter Student grade: ";
	 	cin >> curr->grade;
	 	
	 	if(i == 1) {
	 		head = curr;
            temp = head;
            curr->ptr = NULL;
		}
		
		else {
		 	temp = head;
            head = curr;
            curr->ptr = temp;
		 } 			
	}
	
	//(2) Deleting the Second Record of the List
	//Type '2'
	cout<<"-------------------------------------------------" << endl;
	cout<<"Deleting The Second Record:" << endl;
	st *prev = head;
	temp = head;
	int i = 0;
	 	
	while(temp != NULL) {
        if(i == 1) {
            if(temp->ptr == NULL) { //First Record
                prev->ptr = NULL;
            }
            else if(temp == head) { //Last Record
				head = head->ptr;
                prev = head;
            }
            else {
            	prev->ptr = temp->ptr;
			}
            delete(temp); //Delete 2nd Record
            break;
        }
        prev = temp;
        temp = temp->ptr;
        
        i++;
	}
	
	//(3) Displaying the Contents of the List
	display(head, temp);
	
	//(4) Insert A Record at the Beginning of the List
	cout << "-------------------------------------------------" << endl;
	cout << "Insert a record at the beginning of the list:" << endl;
	fflush(stdin);
	curr = new st;	
	cout << "Enter Student Number: ";
	cin.getline(curr->idnum,10);
	cout << "Enter Student course: ";
	cin.getline(curr->course,10);
	cout << "Enter Student grade: ";
	cin >> curr->grade;
	curr->ptr = head;
	head = curr;
	
	//(5) Insert A Record at the End of the List
	cout<<"-------------------------------------------------" << endl;
	cout<<"Insert a record at the end of the list:" << endl;
	temp = head;
	while(temp->ptr != NULL) {
		temp = temp->ptr;
	}
	
	fflush(stdin);
	curr = new st;	
	cout << "Enter Student Number: ";
	cin.getline(curr->idnum,10);
	cout << "Enter Student course: ";
	cin.getline(curr->course,10);
	cout << "Enter Student grade: ";
	cin >> curr->grade;
	temp->ptr = curr;
	curr->ptr = NULL;
	
	//(6) Displaying the Contents of the List
	display(head, temp);
	
	//(7) Change the grade of the Last Record to 78
	cout<<"-------------------------------------------------" << endl;
	cout<<"Changing the Grade of the Last Record to 78:" << endl;
	temp = head;
	i = 0;
	 	
	while(temp != NULL) {
        if(i == 5) {
            temp->grade = 78;
        }
        prev = temp;
        temp = temp->ptr;
        
        i++;
	}
	
	//(8) Change the grade of the 3rd record of the list to 90
	cout<<"-------------------------------------------------" << endl;
	cout<<"Changing the Grade of the 3rd Record to 90:" << endl;
	temp = head;
	i = 0;
	 	
	while(temp != NULL) {
        if(i == 2) {
            temp->grade = 90;
        }
        prev = temp;
        temp = temp->ptr;
        
        i++;
	}
	
	//(9) Displaying the Contents of the List
	display(head, temp);
	
	//(10) Deleting the First Record of the List
	cout<<"-------------------------------------------------" << endl;
	cout<<"Deleting The First Record:" << endl;
	prev = head;
	temp = head;
	int y = 0;
	 	
	while(temp != NULL) {
        if(y == 0) {
            if(temp->ptr == NULL) { //First Record
                prev->ptr = NULL;
            }
            else if(temp == head) { //Last Record
				head = head->ptr;
                prev = head;
            }
            else {
            	prev->ptr = temp->ptr;
			}
            delete(temp); //Delete 2nd Record
            break;
        }
        prev = temp;
        temp = temp->ptr;
        
        y++;
	}
	
	//(11) Displaying the Contents of the List
	display(head, temp);
	
	//(12) Calculate & display the average of grade of all nodes in the list
	float sum = 0, ave = 0;
	
	cout << "-------------------------------------------------" << endl;
	cout << "Averaging the Grades of All Nodes in the List:" << endl;
	temp = head;
	while(temp) {
		sum += temp->grade;
		temp = temp->ptr;
	}
	
	ave = sum/5;
	cout << "Average Grade of All Nodes: " << ave;
}
