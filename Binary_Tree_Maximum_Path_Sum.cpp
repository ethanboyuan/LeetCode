#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

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

/*	
	unordered_map<TreeNode*, int> depth;

	int maxDepth(TreeNode *root){
		if(!root)
			return 0;
	
		int currdepth = max(maxDepth(root -> left), maxDepth(root -> right)) + root -> val;
		depth.insert({root, currdepth});
		return currdepth;
	}


    int maxPathSumHelper(TreeNode *root) {
  		if(!root) 
  			return 0;

  		int ldepth, rdepth;

  		if(root -> left){
  			unordered_map<TreeNode*, int>::const_iterator gotleft = depth.find(root -> left);
  			ldepth = gotleft -> second;}
  		else{
  			ldepth = 0;
  			}
  		if(root -> right){
			unordered_map<TreeNode*, int>::const_iterator gotright = depth.find(root -> right);	
			rdepth = gotright -> second;
		}
		else {
			rdepth = 0;
		}
  		
  		int currPathSum = ldepth + rdepth + root -> val;

  		int lPath = maxPathSum(root -> left);
  		int rPath = maxPathSum(root -> right);
  		return max(max(lPath, rPath), currPathSum);
    }

    int maxPathSum(TreeNode *root){
    	maxDepth(root);
    	return maxPathSumHelper(root);
    }
    */
/*
    public class Solution {
    class Res {int max = Integer.MIN_VALUE;}
    public int maxPathSum(TreeNode root) {
        Res res = new Res();
        return solve(root, res);
    }
    
    public int solve(TreeNode node, Res res) {
        if (node == null) return 0;
        int left = solve(node.left, res);
        int right = solve(node.right, res);
        res.max = Math.max(left + node.val, Math.max(node.val, Math.max(res.max, right + node.val)));
        return Math.max(res.max,left + right + node.val);
    }
}*/
	int solve(TreeNode* root, int &maxDepth){
		if(!root)
			return 0;
		
		int left = solve(root -> left, maxDepth);
		int right = solve(root -> right, maxDepth);

		int tmp, res;

		tmp = left > right ? 
			  (left > 0 ? root -> val + left : root -> val) :
			  (right > 0 ? root -> val + right : root -> val);

		res = max(tmp, root -> val + left + right);

		if(maxDepth < res) {maxDepth = res;}
		return tmp;
	}

	int maxPathSum(TreeNode * root){

		int maxDepth = INT_MIN;

		solve(root, maxDepth);
		return maxDepth;
	}
};



int main(int argc, char* argv[]){

	TreeNode *Node_A = new TreeNode(-2);
	TreeNode *Node_B = new TreeNode(1);
	TreeNode *Node_C = new TreeNode(3);

	Node_A -> left = Node_B;
	// Node_A -> right = Node_C;

	Solution sol;
	cout << sol.maxPathSum(Node_A) << endl;
	//cout << sol.maxPathSum(Node_A) << endl;

	return 0;
}