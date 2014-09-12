
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


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if(!root) {return res;}
        vector<int> currlvl;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *curr;
        bool righttoleft = 0;
        while(!s.empty()){
        	stack<TreeNode*> t;

        	int currsize = s.size();
        	for(int i = 0; i < currsize; i++){
        		curr = s.top();s.pop();
        		currlvl.push_back(curr -> val);
        		if(righttoleft){
	        		if(curr -> right != NULL) {t.push(curr -> right);}
	        		if(curr -> left != NULL) {t.push(curr -> left);}
	        	}
	        	else{
	        		if(curr -> left != NULL) {t.push(curr -> left);}
	        		if(curr -> right != NULL) {t.push(curr -> right);}

	        		}
        	}
        	righttoleft = !righttoleft;
        	s = t;
        	//t.erase();
        	res.push_back(currlvl);
        	currlvl.clear();
        }
        return res;
    }
};

void printvector(vector<int> &num){

    vector<int>::const_iterator i;
    
    for(i=num.begin(); i!=num.end(); ++i){
        cout<<(*i);
        cout<<" ";
    }
    cout<<endl;    
}

void printmatrix(vector<vector<int>> &matrix){
	int row = matrix.size();
	for (int i = 0; i < row; i++){
		printvector(matrix[i]);
	}

}

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
	vector<vector<int>> res = sol.zigzagLevelOrder(Node_A);
	printmatrix(res);

	return 0;
}