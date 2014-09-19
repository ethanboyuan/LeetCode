// Given this linked list: 1->2->3->4->5

// For k = 2, you should return: 2->1->4->3->5

// For k = 3, you should return: 3->2->1->4->5
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

	ListNode *reverse(ListNode* head, int k){
		if(!head) return NULL;
		if(!head -> next) return head;
		ListNode* prev = NULL;
		ListNode* curr = head;
		ListNode* next;
		while(curr != NULL && k > 0){
			next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;
			k--;
		}
		if (k == 0) 
			head -> next = curr;

		return prev;

	}

    ListNode *reverseKGroup(ListNode *head, int k) {
  		if(!head) 
  			return NULL;
  		ListNode* dummy = new ListNode(-1);
  		dummy -> next = head;
  		ListNode* curr = head;
  		int len = 0;
  		while(curr != NULL){
  			len++;
  			curr = curr -> next;
  		}
  		curr = dummy;

  		for(int j = 0; j < len /k; j ++)

  		//while(curr != NULL)
  		{
  			// int i = 0;
  			// ListNode *tmp = curr -> next;
  			// cout << "tmp " << tmp -> val << endl;
  			// // while(tmp != NULL && i < k){
  			// 	if(tmp -> next)
  			// 		tmp = tmp -> next;
  			// 	i++;
  			// }
  			// if(i == k-1 && tmp != NULL){
	  			// cout << i << endl;
	  			curr -> next = reverse(curr -> next, k);
	  			//printList(dummy);
	  			for(int i = 0; i < k && curr != NULL; i++){
	  				curr = curr -> next;
	  			}
  			// if(curr){
	  		// 	cout << curr -> val << endl;
  			// }
  			// }
  		}

  		//printList(dummy -> next);
  		return dummy -> next;

    }
};

int main(int argc, char* argv[]){

	Solution sol;
    vector<int> arry1 = {1,2,3,4,5,6,7,8};
    ListNode *l1 = sol.Array2List(arry1);
    //sol.printList(l1);
    //ListNode *l2 = sol.reverse(l1,2);
    ListNode *l2 = sol.reverseKGroup(l1,3);
    sol.printList(l2);

	return 0;
}