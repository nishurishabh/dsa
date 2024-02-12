#include <bits/stdc++.h>

using namespace std;

class TreeNode {
	public:
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int num) {
			val = num;
			left = nullptr;
			right = nullptr;
		}
};

class Tree {
	public:
		TreeNode* root;

		Tree() {
			root = nullptr;
		}

		Tree(TreeNode* rootptr) {
			root = rootptr;
		}
};

// vector representation of a tree is where iterating the vector gives level order traversal of the tree.
// -INT_MAX represents a null node
// func to create a tree from vector and return the tree's root
TreeNode* createTree(vector<int> &vec) {
	if(vec.size() == 0) return nullptr;
	TreeNode* root = new TreeNode(vec[0]);
	map<int, TreeNode*> lookup; //map of index of node in arr to actual node
	lookup[0] = root;
	for(int i=1; i < vec.size(); i++) {
		if(vec[i] == -INT_MAX) continue;
		TreeNode* currNode = new TreeNode(vec[i]);
		lookup[i] = currNode;
		int headIdx;
		if(i%2 != 0) {
			headIdx = i/2;
			TreeNode* headPtr = lookup[headIdx];
			headPtr->left = currNode;
		} else {
			headIdx = i/2 - 1;
			TreeNode* headPtr = lookup[headIdx];
			headPtr->right = currNode;
		}
	}

	return root;
}

void preorderTraversal(TreeNode* root) {
		if(root == nullptr) return;
		preorderTraversal(root->left);
		cout << root->val << " ";
		preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root) {
		if(root == nullptr) return;
		cout << root->val << " ";
		inorderTraversal(root->left);
		inorderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
		if(root == nullptr) return;
		postOrderTraversal(root->left);
		postOrderTraversal(root->right);
		cout << root->val << " ";
}

void levelOrderTraversal(TreeNode* root) {
	queue<TreeNode*> q;
	q.push(root);
	int level = 1;
	while(!q.empty()) {
		cout << "\nLevel: " << level++ << " -> ";
		int len = q.size();
		for(int i=0; i<len; i++) {
			TreeNode* currNode = q.front();
			q.pop();
			cout << currNode-> val <<" ";
			if(currNode->left) q.push(currNode->left);
			if(currNode->right) q.push(currNode->right);
		}
	}
}

void treeTraversals(TreeNode* root) {
	cout << "\nPreorder Traversal of the tree: ";
	preorderTraversal(root);
	cout << "\nInorder Traversal of the tree: ";
	inorderTraversal(root);
	cout << "\nPostorder Traversal of the tree: ";
	postOrderTraversal(root);
	cout << "\nLevel order Traversal of the tree: ";
	levelOrderTraversal(root);
}

int main() {
	vector<int> treeVec = {6,2,1,4,7,-INT_MAX,10,11};
	Tree tree = Tree();
	tree.root = createTree(treeVec);
	treeTraversals(tree.root);
}