#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* link;
  Node(int val) : val(val), link(NULL) {}
};

Node* XOR(Node* prev, Node* next) {
  return (Node*) ((uintptr_t)prev ^ (uintptr_t)next); 
}

Node* insertEnd(Node* head, int val) {
  if (!head) 
    return new Node(val);
  Node* prev = NULL, *curr = head, *next = XOR(prev, curr->link);
  while (next) {
    prev = curr;
    curr = next;
    next = XOR(prev, curr->link);
  }
  next = new Node(val);
  next->link = XOR(curr, NULL);
  curr->link = XOR(curr->link, next);
  return head;
}

Node* insertBeg(Node* head, int val) {
  if (!head) 
    return new Node(val);
  Node* node = new Node(val);
  head->link = XOR(head->link, node);
  node->link = XOR(NULL, head);
  return node;
}

Node* deleteBeg(Node* head){
    if(!head){
        cout<<"The List is Empty";
        return head;
    }
    else
    {
        Node* curr = head;
        head = XOR(curr->link, NULL);
        return head;
    }   
}

Node* deleteEnd(Node* head){
    if(!head){
        cout<<"The List is Empty";
        return head;
    }
    else{

    }
}
void printList(Node* curr) {
  Node* prev = NULL;
  while (curr) {
    cout << curr->val << ' ';
    Node* next = XOR(curr->link, prev);
    prev = curr, curr = next;
  } 
  cout << endl;
}

int main() {
  Node* head = NULL;
  int n, val, choice; 
  do{
        cout<<"\n1)Insert Beginning\n2)Insert End\n3)Exit\nEnter your choice:";
        cin>>choice;
        switch(choice){
            case 1: cout<<"Enter a Element:";
                    cin>>val;  
                    head = insertEnd(head, val);
                    printList(head);
                    break;
            case 2: cout<<"Enter a Element:";
                    cin>>val; 
                    head = insertBeg(head, val);
                    printList(head);
                    break;
            case 3: exit(0);
                    break;
            case 4:head = deleteBeg(head);
                break;
        }
    }while(1);
    return 0;
}
