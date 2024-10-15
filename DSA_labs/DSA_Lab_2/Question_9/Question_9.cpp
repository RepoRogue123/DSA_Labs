#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int v = 0, node* nxt = NULL) {
        val = v;
        next = nxt;
    }
};

class LinkedList {
public:
    node* head;
    LinkedList(node* h = NULL) {
        head = h;
    }

    void insert(int val) {
        node* newNode = new node(val);
        if (head == NULL) {
            head = newNode;
        } else {
            node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    pair<int, int> findSpikes() {
        int upSpikes = 0, downSpikes = 0;
        node*temp=head;
        node*prev=NULL;
        while(temp && temp->next){
            node*front=temp->next;
            if(prev!= NULL && temp->val >front->val && temp->val>prev->val){
                upSpikes++;
            } 
            if(prev!= NULL && temp->val <front->val && temp->val<prev->val){
                downSpikes++;
            } 
            prev=temp;
            temp=front;
        }

        // Complete this function to count upSpikes and downSpikes.

        return {upSpikes, downSpikes};
    }
};

int main() {
    LinkedList list;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    pair<int, int> spikes = list.findSpikes();
    cout << spikes.first << " " << spikes.second << endl;

    return 0;
}