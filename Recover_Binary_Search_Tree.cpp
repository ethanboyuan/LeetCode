#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};


class Solution {
public:
    void recoverTree(TreeNode *root) {
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while(cur != nullptr){
        	if(cur -> left == nullptr){
        		//cout << cur -> val << endl;
        		detect(broken, prev, cur);
        		prev = cur;
        		cur = cur -> right;
        	} else {
        		TreeNode* node = cur -> left;

        		while(node -> right != nullptr && node -> right != cur)
        			node = node -> right;

        		if(node -> right == nullptr){
        			node -> right = cur;
        			//prev = cur;
        			cur = cur -> left;
        		} else {
        			//cout << cur -> val << endl;
        			detect(broken, prev, cur);
        			node -> right = nullptr;
        			prev = cur;
        			cur = cur -> right;
        		}
        	}
        }

        swap(broken.first->val, broken.second->val);

    }

    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* curr){
    	if(prev != nullptr && prev -> val > curr -> val){
    		if(broken.first == nullptr){
    			broken.first = prev;
				cout << "first set to " << prev -> val << endl;    			
    		}
	    	broken.second = curr;

    	}
    }
};



int main(int argc, char* argv[]){
	Solution sol;
	TreeNode* root = new TreeNode(1);
	TreeNode* left = new TreeNode(2);
	TreeNode* right = new TreeNode(3);
	root -> left = left;
	root -> right = right;

	sol.recoverTree(root);
	cout << root -> val << endl;
	cout << root -> left -> val << endl;
	cout << root -> right -> val << endl;


	return 0;
}
