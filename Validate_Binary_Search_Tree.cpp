#include <vector>
#include <iostream>
#include <queue>
#include <stack>
//#include <limits.h>

using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};


class Solution {
public:
	bool isValidBSThelper(TreeNode *root, int lowwer, int higher){

		if(!root) {return 1;}

		bool lValid = isValidBSThelper(root -> left, lowwer, root -> val);
		bool rValid = isValidBSThelper(root -> right, root -> val, higher);
		
		if(root -> val < higher && root -> val > lowwer)
			return lValid && rValid;
		else 
			return 0;
	}

    bool isValidBST(TreeNode *root) {

		return isValidBSThelper(root, INT_MIN, INT_MAX);
    }
};

int main(int argc, char* argv[]){

	TreeNode *Node_A = new TreeNode(1);
	TreeNode *Node_B = new TreeNode(2);
	TreeNode *Node_C = new TreeNode(3);
	TreeNode *Node_D = new TreeNode(4);
	TreeNode *Node_E = new TreeNode(5);
	TreeNode *Node_F = new TreeNode(15);
	TreeNode *Node_G = new TreeNode(5);

//	bool absame = isSameTree(Node_A,Node_B);
	
	Node_A -> left = Node_B;
	Node_A -> right = Node_C;

	
	Node_B -> left = Node_D;
	//Node_B -> right = Node_E;
	//Node_C -> left = Node_F;
	Node_C -> right = Node_G;	

	Solution sol;
	bool Avalid = sol.isValidBSThelper(Node_A);
	cout << Avalid << endl;
	return 0;
}