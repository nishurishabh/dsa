#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node {
	public:
	int value;
	Node* next;

	Node(int v) {
		value = v;
		next = nullptr;
	}

};

class LinkedList {
	public:
	Node* head;

		void pushStart(Node* n) {
			if (head == nullptr) {
				head = n;
				return;
			}
			n->next = head;
			head = n;
		}

		void printList() {
			Node* itr = head;
			while(itr) {
				cout << itr -> value << " ";
				itr = itr->next;
			}
		}
};

int main() {
	LinkedList list = LinkedList();
	list.pushStart(new Node(3));
	list.pushStart(new Node(2));
	list.pushStart(new Node(1));
	list.printList();

	return 0;
}