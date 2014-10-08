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
    vector<TreeNode *> generateTrees(int n) {
  		vector<TreeNode *> res;
  		if(n == 0) return res;
  		return res;      
    }
};


int main(int argc, char* argv[]){
   // cout << main.get_id() <<endl;
	 Solution sol;
	 return 0;
}