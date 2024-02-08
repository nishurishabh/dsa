// Merge two linked list.

#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int value;
    Node* next;
    Node(int x) {
        value = x;
        next = nullptr;
    }
};
class LinkedList {
	Node* head = nullptr;
    public:

        Node* getHead() {
        	return head;
        }

        void setHead(Node* assignedHead) {
        	head = assignedHead;
        }
        // Create a LinkedList from a Vector
        LinkedList() {

        }
        LinkedList(vector<int> vec) {
        	Node * curr;
            for(auto x : vec) {
                if(head == nullptr) {
                    Node* tempNode = new Node(x);
                    head = tempNode;
                    curr = head;
                    continue;
                }
                Node* tempNode = new Node(x);
                curr->next = tempNode;
                curr = curr->next;
            }
        }

         void printLinkedList() {
            cout << "\nPrinting the LinkedList: " << endl;
            Node* itr = head;
            while(itr) {
                cout << itr->value << " -> ";
                itr = itr->next;
            }
        }
};

void removeNthNodeFromLast(LinkedList &LL, int n) {
	Node* head = LL.getHead();
    Node *slow = head, *fast = head;

    // edge case handling.
    if(head == nullptr || (head->next == nullptr && n != 0)) {
    	return;
    }

    if (head->next == nullptr && n == 1) {
    	delete head;
    	head = nullptr;
    	LL.setHead(head);
    	return;
    }

    while(fast && n--) {
    	fast = fast->next;
    	// cout << "A";
    }

    if(!fast) {
    	cout << "B";
    	Node* temp = head;
    	head = head->next;
    	delete temp;
    	LL.setHead(head);
    	return;
    }

    while(fast->next) {
    	fast = fast->next;
    	slow = slow->next;
    }

    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
    return;
}

int main() {
	vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
	LinkedList LL = LinkedList(vec);
	LL.printLinkedList();
	removeNthNodeFromLast(LL, 5);
	LL.printLinkedList();
    return 0;
}