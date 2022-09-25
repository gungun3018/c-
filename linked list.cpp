#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        string name;
        int age;
        Node* prev;
        Node* next;
        Node (string str,int a){
            name = str;
            age = a;
        }
};

bool searchName(Node* head,string name){
    Node* curr = head;
    while(curr != NULL){
        if(curr->name == name) return true;
        curr = curr->next;
    }
    return false;
}

bool searchAge(Node* head,int age){
    Node* curr = head;
    while(curr != NULL){
        if(curr->age == age) return true;
        curr = curr->next;
    }
    return false;
}

void insertAtHead(Node* & head,Node*& tail,string str,int age){
    Node* newNode = new Node(str,age);
    newNode->next = head;
    if(head != NULL){
        head->prev = newNode;
    }
    head = newNode;
}

void insertAtTail(Node* & head,Node*& tail,string str,int age){
    Node* newNode = new Node(str,age);
    newNode->next = NULL;
    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    return;
}
void deleteNode(Node* & head,Node*& curr){
    if(head == NULL || curr == NULL) return;
    if(head == curr) head->next = curr->next;
    if(curr->next != NULL) curr->next->prev = curr->prev;
    if(curr->prev != NULL) curr->prev->next = curr->next;
    free(curr);
}

void deleteNodeAtGivenPosition(Node*& head, int n){
    if(head == NULL || n <= 0){
        cout << "The position to be deleted is not Valid" << endl;
        return;
    } 
    Node* curr = head;
    int i;
    for(int i = 1;curr != NULL && i < n;i++) curr = curr->next;
    if(curr == NULL){
        cout << "The position to be deleted is not Valid" << endl;
        return;
    } 
    deleteNode(head,curr);
}

void deleteNodeFromEnd(Node*& tail){
    if(tail == NULL) return;
    Node* curr = tail->prev;
    tail->prev->next = NULL;
    tail = curr;
}
void display(Node* head){
    Node* curr = head;
    while(curr != NULL) {
        cout << "Name: " <<  curr->name << ", age: " << curr->age << endl;
        curr = curr->next;
    }
    
}

void displayInReverse(Node* tail){
    Node* curr = tail;
    while(curr != NULL){
        cout << "Name: " << curr->name << ", age: " << curr->age << endl;
        curr = curr->prev;
    }
}

int main() {
	Node* head = NULL;
	Node* tail = head;
	string str;
	int age;
	cin >> str >> age;
	while(str != "-1"){
	    insertAtTail(head,tail,str,age);
	    cin >> str >> age;
	}
	deleteNodeAtGivenPosition(head,6);
	deleteNodeFromEnd(tail);
	
	display(head);
	deleteNodeAtGivenPosition(head,2);
	cout<< "Display in Reverse" << endl;
	displayInReverse(tail);
	
	
	if(searchAge(head,19)) cout << "The age is present in the List." << endl;
	else cout << "The age is not present in the List" << endl;
	
	if(searchName(head,"Father")) cout << "The Name is present in the List." << endl;
	else cout << "The Name is not present in the List" << endl;
	
	return 0;
}