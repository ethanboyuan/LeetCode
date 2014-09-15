#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};

/*****************************

      10
     /  \
    5    12
   / \     \
  2   8     15
           / \
          13  20 

*****************************/

/*  
 * Write a function that returns the nth element from a binary search tree
 * using inorder traversal. It should take the root of the tree and an int as
 * parameters. It can take other parameters as well if needed.
 * 
 * It should return an int (the value of the nth node).
 * 
 * If n is greater than the size of the tree you may return 0.
 * From the example above, 
 *   if n=0, return 2
 *   if n=2, return 8
 *
 * Assume each node has a left pointer, right pointer, value and nothing else.
 * Also assume that n is less than the size of the tree
 * 
 * 
 */
class Solution {
public:
	void TreeIndexSearchHelper(TreeNode *root, int index, int &count, int &res){
		if(!root) return;
		TreeIndexSearchHelper(root -> left, index, count, res);
		if(index == count){
			res = root -> val;
		}
		count ++;
		TreeIndexSearchHelper(root -> right, index, count, res);
	}

	int TreeIndexSearch(TreeNode *root, int index){
		int res = 0, count = 0;
		TreeIndexSearchHelper(root, index, count, res);
		return res;
	}


};

int main(int argc, char* argv[]){
	TreeNode *Node_A = new TreeNode(10);
	TreeNode *Node_B = new TreeNode(5);
	TreeNode *Node_C = new TreeNode(12);
	TreeNode *Node_D = new TreeNode(2);
	TreeNode *Node_E = new TreeNode(8);
	TreeNode *Node_F = new TreeNode(15);
	TreeNode *Node_G = new TreeNode(13);
	TreeNode *Node_H = new TreeNode(20);

	Node_A -> left = Node_B;
	Node_A -> right = Node_C;
	Node_B -> left = Node_D;
	Node_B -> right = Node_E;
	Node_C -> right = Node_F;	
	Node_F -> left = Node_G;
    Node_F -> right = Node_H;



	Solution sol;
	for(int i = 0; i < 9; i++){
	cout << sol.TreeIndexSearch(Node_A, i) << endl;
	}
	return 0;
}


