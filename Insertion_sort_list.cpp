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


    ListNode *insertionSortList(ListNode *head) {
        if(!head || !head -> next)
        	return head;

        ListNode *dummy = new ListNode(-1);
        ListNode *curr = head;
        while(curr != NULL){
       // 	cout << "inserting: " << curr -> val << endl;

        	ListNode *tmp = dummy;
        	while(tmp -> next != NULL&& tmp -> next -> val < curr -> val) { 
        		tmp = tmp -> next;
        	}
        	if(!tmp -> next){
        		tmp -> next = curr;
        		curr = curr -> next;
	        	tmp -> next -> next = NULL;
        	}
        	else{
        		ListNode *next = curr -> next;
        		curr -> next = tmp -> next;
        		tmp -> next = curr;
        		curr = next;
        	} 
        	//curr = curr -> next;
        	//tmp -> next -> next = NULL;
        //	printList(dummy);
        }
        return dummy -> next;
    }
};

int main(int argc, char* argv[]){
	Solution sol;
    vector<int> arry1 = {4,3,1};
    ListNode *l1 = sol.Array2List(arry1);
    sol.printList(l1);
    ListNode *res = sol.insertionSortList(l1);
    sol.printList(res);
	return 0;
}