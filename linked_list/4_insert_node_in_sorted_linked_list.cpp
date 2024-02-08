
// Insert a node at corrected position in a sorted array. 

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
    public:
        Node* head = nullptr;

		void insertNodeInSortedLL(int num) {
			Node* temp = new Node(num);
			// case 1: when head is null
			if (head == nullptr) {
				head = temp;
				return;
			}

			// case 2: num < head's value
			if (num < head->value) {
				temp->next = head;
				head = temp;
				return;
			}

			// case 3: when head.value <= num <= tail.value
			Node* itr = head;
			Node* prev = head;
			while(itr) {
				if(num < itr->value) {
					temp->next = prev->next;
					prev->next = temp;
					return;
				}
				prev = itr;
				itr = itr->next;
			}

			// case 4: num > tails value
			prev->next = temp;
		}

        // Create a LinkedList from a sorted Vector
        void createSortedLinkedListFromArray(vector<int> &vec) {
        	sort(vec.begin(), vec.end());
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

LinkedList resetLinkedList() {
	vector<int> inputVec = {1, 7, 3, 10};
    LinkedList LL = LinkedList();
    LL.createSortedLinkedListFromArray(inputVec);
    return LL;
}

int main() {
   LinkedList LL1 = resetLinkedList();
   LL1.insertNodeInSortedLL(0);
   LL1.printLinkedList();

   LinkedList LL2 = resetLinkedList();
   LL2.insertNodeInSortedLL(4);
   LL2.printLinkedList();

   LinkedList LL3 = resetLinkedList();
   LL3.insertNodeInSortedLL(11);
   LL3.printLinkedList();

   LinkedList LL4 = LinkedList();
   LL4.insertNodeInSortedLL(1);
   LL4.printLinkedList();
}