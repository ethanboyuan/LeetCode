#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode* dummy = new ListNode (0);
		ListNode* curr = dummy;
		int carry = 0;
		while(l1 && l2){
			ListNode* tmp = new ListNode((l1->val+l2->val+carry)%10);
			carry = (l1->val + l2->val + carry)/10;
			curr -> next = tmp;
			curr = curr -> next;
			l1 = l1 -> next;
			l2 = l2 -> next;
		}

		if(l1){
			while(l1){
				ListNode* tmp = new ListNode((l1->val+carry)%10);
				carry = (l1->val + carry)/10;
				curr -> next = tmp;
				curr = curr -> next;
				l1 = l1 -> next;
			}
			if(carry){
				ListNode* tmp = new ListNode(1);
				curr -> next = tmp;
			}
		}
		else if(l2){
			while(l2){
				ListNode* tmp = new ListNode((l2->val+carry)%10);
				carry = (l2->val + carry)/10;
				curr -> next = tmp;
				curr = curr -> next;
				l2 = l2 -> next;
			}
			if(carry){
				ListNode* tmp = new ListNode(1);
				curr -> next = tmp;
			}
		}
		else if(carry){
			ListNode* tmp = new ListNode(1);
			curr -> next = tmp;
		}
		return dummy -> next;            
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
	ListNode *l1 = Array2List({0});
	ListNode *l2 = Array2List({7,3});
	ListNode *res = sol.addTwoNumbers(l1,l2);
	printList(res);


	return 0;
}