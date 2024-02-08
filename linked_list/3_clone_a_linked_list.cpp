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

LinkedList mergeTwoSortedLinkedList(Node* head1, Node* head2) {
	Node *cur1, *cur2, *cur3;
	cur1 = head1;
	cur2 = head2;

	Node* dummyNode = new Node(-1);
	cur3 = dummyNode;
	while(cur1 || cur2) {
		if (cur1 == nullptr) {
			cur3->next = cur2;
			break;
		}
		if(cur2 == nullptr) {
			cur3->next = cur1;
			break;
		}
		if (cur1->value <= cur2->value) {
			cur3->next = cur1;
			cur1 = cur1->next;
		} else {
			cur3->next = cur2;
			cur2 = cur2->next;
		}

		cur3 = cur3->next;
	}

	LinkedList mergeList = LinkedList();
	mergeList.setHead(dummyNode->next);
	return mergeList;
}

int main() {
	vector<int> v1 = {1,4,7,10,100};
	vector<int> v2 = {2,3,11,20};
	LinkedList L1,L2,L3;
	L1 = LinkedList(v1);
	L2 = LinkedList(v2);

	L3 = mergeTwoSortedLinkedList(L1.getHead(), L2.getHead());
	L3.printLinkedList();
    return 0;
}