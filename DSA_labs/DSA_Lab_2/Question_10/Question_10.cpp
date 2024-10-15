#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int id;
    node* next;

    node(int ai) {
        id = ai;
        next = NULL;
    }
} node;

class LinkedList {
public:
    node* head;
    node* last;

    LinkedList(node* h) {
        head = h;
        last = h;
    }

    void insert(node* ln) {
        last->next = ln;
        last = last->next;
    }

    bool find(node* n) {
        for (node* c = head; c; c = c->next)
            if (c == n) return true;
        return false;
    }

    // Returns true if n is reachable from the head of this list.
    bool isReachableFromHead(node* n) {
        for (node* c = head; c; c = c->next)
            if (c == n) return true;
        return false;
    }
};

void printHitForkApart(vector<LinkedList>& L) {
    int n = L.size();
    int hit = 0, fork = 0, apart = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if either head of L[i] is reachable from the other head
            bool h1_to_h2 = L[i].isReachableFromHead(L[j].head);
            bool h2_to_h1 = L[j].isReachableFromHead(L[i].head);

            if (h1_to_h2 || h2_to_h1) {
                hit++;
            } else {
                // Check if they lead to a fork
                node* c1 = L[i].head->next;
                int isFork = 0;

                while (c1 && !isFork) {
                    node* c2 = L[j].head->next;
                    while (c2) {
                        if (c1 == c2) {
                            fork++;
                            isFork = 1;
                            break;
                        }
                        c2 = c2->next;
                    }
                    c1 = c1->next;
                }

                if (!isFork) apart++;
            }
        }
    }

    // Output the results
    cout << hit << '\n' << fork << '\n' << apart << '\n';
}

int main() {
    int n;
    cin >> n;

    vector<LinkedList> LL;
    map<int, node*> mp;

    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int hid;
        cin >> hid;
        m--;

        if (mp.find(hid) == mp.end())
            mp[hid] = new node(hid);

        LL.push_back(LinkedList(mp[hid]));

        while (m--) {
            int ai;
            cin >> ai;
            if (mp.find(ai) == mp.end())
                mp[ai] = new node(ai);
            LL[i].insert(mp[ai]);
        }
    }

    printHitForkApart(LL);
    return 0;
}
