// LCA of a binary tree

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

TreeNode* LCA(TreeNode* root, int p, int q) {
    if(root == nullptr) return root;

    if(root -> val == p || root->val == q) return root;

    auto leftLCA = LCA(root->left,p,q);
    auto rightLCA = LCA(root->right,p,q);

    if(leftLCA && rightLCA) return root;
    if(leftLCA || rightLCA) return leftLCA?leftLCA:rightLCA;

    return nullptr;
}

void preorderTraversal(TreeNode* root) {
		if(root == nullptr) return;
		preorderTraversal(root->left);
		cout << root->val << " ";
		preorderTraversal(root->right);
}

int main() {
	vector<int> treeVec = {6,2,1,4,7,-INT_MAX,10,11};
	Tree tree = Tree();
	tree.root = createTree(treeVec);
	TreeNode* lca;
	// TC1
	lca = LCA(tree.root,2,1);
	cout << "LCA of 2,1 is: " << lca->val;
	// TC2
	lca = LCA(tree.root,11,7);
    cout << "\nLCA of 11,7 is: " << lca->val;
    // TC3
    lca = LCA(tree.root,10,1);
    cout << "\nLCA of 10,1 is: " << lca->val;
    // TC3
    lca = LCA(tree.root,11,6);
    cout << "\nLCA of 11,6 is: " << lca->val;
}



/*

- Lowest Common ancestor node t of two nodes p and q in a tree,
is the lowest node (near to leaf node) which has both p and q as common descents. A node can be considered descent of itself.

- Hint: For a node to be LCA of p and q, p should lie in left subtree and q should lie in right subtree.


*/