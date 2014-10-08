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
	vector<TreeNode *> *TreeGenHelper(int l, int r){
		vector<TreeNode*> *subtree = new vector<TreeNode*> ();

		if(l > r){
			subtree -> push_back(NULL);
			return NULL;

		}
		for(int i = l; i <= r; i++){
			vector<TreeNode*> *lsubtree = TreeGenHelper(l, i-1);
			vector<TreeNode*> *rsubtree = TreeGenHelper(i+1, r);
			for(int j = l; j <= i - 1; j++){
				for(int k = i+1; k < r; k++){
					TreeNode *node = new TreeNode(i);
					node -> left = (*lsubtree)[j];
					node -> right = (*rsubtree)[k];
					subtree -> push_back(node);
				}
			}
		}
		return subtree;


	}

    vector<TreeNode *> generateTrees(int n) {

  		return *TreeGenHelper(1,n);      
    }
};


int main(int argc, char* argv[]){
   // cout << main.get_id() <<endl;
	 Solution sol;
	 return 0;
}