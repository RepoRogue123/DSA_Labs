#include <iostream>
using namespace std;

// Node structure for the linked list
class Node {
public:
    int data;
    Node* next;

    Node(int val=0,Node* NXT=NULL){
        data=val;
        next=NXT;
    }
};

// Class to represent a linked list
class LinkedList {
public:
    Node* head;
    LinkedList(Node*h=NULL){
        head=h;
    }

    void insert(int num){
        Node*temp=new Node(num,NULL);
        if(head==NULL){
            head=temp;
            return;          
        }
        Node*curr=head;
        while(curr->next){
            curr=curr->next;
        }
        curr->next=temp;
    }

    // Function to add two linked lists representing numbers
    LinkedList add_two_numbers(Node* l2) {
        LinkedList result;
        Node* l1 = this->head;
        int carry = 0;
        
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x,y;
            if(l1 != NULL){
                 x=l1->data;
            }
            else{
                x=0;
            }
            if(l2 != NULL){
                 y=l2->data;
            }
            else{
                y=0;
            }
            int sum = carry + x + y;
            carry = sum / 10;
            result.insert(sum % 10);
            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }
        
        return result;
    }

    // Function to display the linked list
    void print_list() {
        Node* curr = head;
        while (curr) {
            cout << curr->data;
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    int num1, num2;

    // Input for two numbers
    cin >> num1 >> num2;

    // Creating linked lists for the input numbers
    LinkedList list1, list2;
    while (num1 > 0) {
        list1.insert(num1 % 10);
        num1 /= 10;
    }
    while (num2 > 0) {
        list2.insert(num2 % 10);
        num2 /= 10;
    }

    // Adding the linked lists
    LinkedList result = list1.add_two_numbers(list2.head);

    // Displaying the result
    result.print_list();

    return 0;
}