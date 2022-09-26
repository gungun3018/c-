/* Q1 we can use do while loop when the temp reaches back to head address it stops the do while loop
and do while loop first do the work and then move to the condition
*/
#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
      int data;
      Node * next;

};

void takeInput(Node *& head,Node*& tail) {
   int daa;
   cin >> daa;
   while (daa != -1)

      Node * ptr = new Node();
      Node * temp =  head;
      ptr -> next =  head;
      ptr -> data = daa;
      if(head == NULL){
          ptr->next = ptr;
          head = ptr;
          tail = ptr;
      }else{
          tail->next = ptr;
          tail = ptr;
      }
      cin >> daa;
   }
}

void deleteNode(Node*& head, int key) {
    if (head == NULL) return;

    if(head->data==key && head->next==head)
    {
        free(head);
        head=NULL;
        return;
    }

    Node *last=head,*d;
    if(head->data==key){
        while(last->next!=head) last=last->next;
        last->next=(head)->next;
        free(head);
        head=last->next;
        return;
    }
    while(last->next!=head&&last->next->data!=key)  last=last->next;

    if(last->next->data==key) {
        d=last->next;
        last->next=d->next;
        free(d);
    }
    else cout<<"no such keyfound";
}


void dis(Node * head) {
   Node * temp = head;
   if (head != NULL) {
      do {
         cout << temp -> data << " ";
         temp = temp -> next;
      }
      while (temp != head);
      cout << endl;
   }

}

int main() {
   Node * head = NULL;
   Node * tail = NULL;
   takeInput(head,tail);
   cout << "Display of Circular queue: ";
   dis(head);
   deleteNode(head,74);
   deleteNode(head,1);
   deleteNode(head,6);
   cout << "Display of Circular queue: ";
   dis(head);
}


/*
Q2 -> Applications
1. Circular Linked Lists can be used to manage the computing resources of the computer.
2. Data structures such as stacks and queues are implemented with the help of the circular linked lists.
3. Circular Linked list is used in Audio/video streaming.
4. Circular LInked list is used in Circular Escalators.
5. Circular Linked list is used as Undo functionality in Photoshop or Word.
6.
*/
