#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverse(ListNode* root){
		if(!root) {return NULL;}
		ListNode *curr = root;
		ListNode *prev = NULL;
		ListNode *next;
		while(curr != NULL){
			next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;
		}

		return prev;
	}
};


ListNode* Array2List(vector<int> arry){
  ListNode* dummy = new ListNode(-1);
  ListNode* curr = dummy;
  for(int i = 0; i < arry.size(); i++){
    ListNode* tmp = new ListNode(arry[i]);
    curr -> next = tmp;
    curr = curr -> next;
  }
  return dummy -> next;
}

void printList(ListNode *root){
  if(!root) {
    cout << "List is empty!" << endl;
    return;
  }
  while(root != NULL){
    cout << root -> val;
    cout << " -> ";
    root = root -> next;
  }
  cout << "NULL";
  cout << endl;
  return ;
}

int main(int argc, char* argv[]){

	Solution sol;
   	vector<int> arry1 = {1,2,3,4,5};
   	ListNode *l1 = Array2List(arry1);
   	ListNode *res = sol.reverse(l1);
   	printList(res);
	return 0;	
}