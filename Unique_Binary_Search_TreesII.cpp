#include <vector>
#include <iostream>
#include <queue>
#include <stack>
//#include <thread>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<TreeNode *> TreeGenHelper(int l, int r){
		vector<TreeNode*> subTree;
		if(l > r){
			subTree.push_back(NULL);
			return subTree;
		}
		for(int i = l; i <= r; i ++){
			vector<TreeNode*> leftSub = TreeGenHelper(l, i-1);
			vector<TreeNode*> rightSub = TreeGenHelper(i+1, r);
			for(int j = 0; j < leftSub.size(); j++){
				for(int k = 0; k < rightSub.size(); k++){
					TreeNode * node = new TreeNode(i);
					node -> left = leftSub[j];
					node -> right = rightSub[k];
					subTree.push_back(node);
				}
			}
		}
		return subTree;
	}

    vector<TreeNode *> generateTrees(int n) {

  		return TreeGenHelper(1,n);      
    }
};


int main(int argc, char* argv[]){
   // cout << main.get_id() <<endl;
	 Solution sol;
	 return 0;
}