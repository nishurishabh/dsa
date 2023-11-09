// create a linked list from an array of numbers
// make a utility func which deletes a node with a given key.
// The utility func should return 1 if deleted otherwise return -1.

#include<bits/stdc++.h>
#define nil nullptr
using namespace std;

class Node {
    public:
	int value;
	Node* next;
	Node(int x) {
			value = x;
			next = nil;
		}

};

class LinkedList {
    public:
	Node* head;
	Node* tail;
	void createLinkedList(vector<int> vec) {
		for(auto x: vec) {
			Node *node = new Node(x);
			if(head == nullptr) {
				head = node;
				tail = node;
				continue;
			}
			tail->next = node;
			tail = node;
		}
	}

	void printList() {
		Node* itr = head;
		cout << "START OF LL : ";
		while(itr) {
			cout << itr->value << " ->  ";
			itr = itr->next;
		}
		cout << "END OF LL" <<endl;
	}
};

int deleteNodeFromLL(LinkedList &list, int key) {
    // empty LL check
    if (list.head == nullptr) {
        cout << "The Linked list is empty" << endl;
        return -1;
    }
    Node* curr = list.head;
    Node* prev = nullptr;

    // if the key == headNode
    if (curr->value == key) {
        cout << "The head node " << key << " will be deleted!" << endl;
        list.head = list.head->next;
        return 1;
    }
    prev = curr;
    curr = curr->next;
    while(curr) {
        if (curr->value == key) {
            prev->next = curr->next;
            cout << "The node with " << key << " will be deleted!" << endl;
            delete curr;
            return 1;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "The node with " << key << " not found in the Linked List" << endl;
    return -1;
}

int main() {
	vector<int> vec = {1,2,3,4,5,6,7};
	LinkedList list = LinkedList();
	list.createLinkedList(vec);
	list.printList();
	deleteNodeFromLL(list, 3);
	list.printList();
	deleteNodeFromLL(list, 7);
	list.printList();
	deleteNodeFromLL(list, 1);
	list.printList();
	deleteNodeFromLL(list, -1);
	list.printList();

}