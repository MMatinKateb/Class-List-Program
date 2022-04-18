#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class node {
    friend class linkedlist;

    long long int stnum;
    char name[15] , lastname[15];
    double avg;

    node *next;
};

class linkedlist {
    node *first , *last;

    public:
        linkedlist();
        void enter();
        void delNode();
        void display();
        void savefile(char name[]);
        void openfile(char name[]);
        ~linkedlist();
};

linkedlist::linkedlist() {
    first = last = NULL;
}

void linkedlist::enter() {
    node *newNode = new node;
    newNode->next = NULL;

    if(first == NULL)
        first = last = newNode;

    else {
        last->next = newNode;
        last = newNode;
    }

    cout << "\nEnter student name: ";
    cin >> last->name;
    cout << "Enter student last name: ";
    cin >> last->lastname;
    cout << "Enter student number: ";
    cin >> last->stnum;
    cout << "Enter student average score: ";
    cin >> last->avg;

    cout << "\n--> Student saved.\n";
}

void linkedlist::display() {
    if(first == NULL){
        cout << "\n--> List is empty.\n";
        return;
    }

    cout << "\n\n\nClass list:\n\n";
    node *ptr;
    for(ptr=first ; ptr!=NULL ; ptr=ptr->next) {
        cout << "--> Name: " << ptr->name << endl;
        cout << "--> Last Name: " << ptr->lastname << endl;
        cout << "--> Student Number: " << ptr->stnum << endl;
        cout << "--> Average Score: " << ptr->avg << endl;
        cout << "\n\n";
    }

    cout << endl;
}

void linkedlist::delNode() {
    if(first == NULL) {
        cout << "\n--> List is empty.\n";
        return;
    }

    else {
        long long int num;
        cout << "Enter student number to delete: ";
        cin >> num;

        node *prePtr;


        for(prePtr = first ; prePtr != NULL ; prePtr = prePtr->next) {
            node *ptr = prePtr->next;

            if(prePtr->stnum == num) {
                first = ptr;
                delete prePtr;
                cout << "--> Student deleted.\n";
                break;
            }

            else if(ptr->stnum == num) {
                prePtr->next = ptr->next;
                delete ptr;
                cout << "--> Student deleted.\n";
                break;
            }

            else if(!ptr->next) {
                cout << "--> Student not found.\n";
                break;
            }

        }//end of for
    }//end of else
}

void linkedlist::savefile(char *name)
{
    ofstream file(name);

    if(first == NULL){
        cout << "\n--> List is empty.\n";
        return;
    }

    file << "Class list:\n\n";
    node *ptr;
    for(ptr=first ; ptr!=NULL ; ptr=ptr->next) {
        file << "--> Name: " << ptr->name << endl;
        file << "--> Last Name: " << ptr->lastname << endl;
        file << "--> Student Number: " << ptr->stnum << endl;
        file << "--> Average Score: " << ptr->avg << endl;
        file << "\n\n";
    }

    file.close();
    cout << "--> File saved." << endl;
}

void linkedlist::openfile(char *name)
{
    string info;
    ifstream file(name);

    cout << endl;
    int count = 0;
    while(1){
        while(1) {
            while(getline(file, info))
            {
                cout << info << endl;
                count++;
            }
            break;
        }
        file.close();
        if(count == 0) { //if file does not exist
            cout << "--> File not found.\n";
            return;
        }
    }

}

linkedlist::~linkedlist() {
    node *secPtr = first;
    node *temp;
    while(secPtr) {
        temp = secPtr;
        delete temp;
        secPtr = secPtr->next;
    }
}

int menu() {
    int option;
    cout << "Enter 1 to enter new student.\n";
    cout << "Enter 2 to delete student.\n";
    cout << "Enter 3 to display student list.\n";
    cout << "Enter 4 to save file.\n";
    cout << "Enter 5 to open file.\n";
    cout << "Enter 6 to exit.\n";
    cin >> option;
    return option;
}

int main() {
    system("clear");
    linkedlist ll;

    while(1){
        switch(menu()) {
            case 1:
                ll.enter();
                break;
            case 2:
                ll.delNode();
                break;
            case 3:
                ll.display();
                break;
            case 4:
                char savename[30];
                cout << "Enter file name: ";
                cin >> savename;
                ll.savefile(savename);
                break;
            case 5:
                char openname[30];
                cout << "Enter file name: ";
                cin >> openname;
                ll.openfile(openname);
                break;
            case 6:
                exit(1);
            default:
                cout << "\n--> Invalid input.\n\n";
                continue;
        }
        cout << endl;
    }

    return 0;
}
