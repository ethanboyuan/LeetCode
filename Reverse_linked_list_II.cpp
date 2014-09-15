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

  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if(!head) {return 0;}
    if(m == n) {return head;}
    ListNode *dummy = new ListNode(-1);
    dummy -> next = head;
    ListNode *curr = dummy;
    while(m > 1){
      curr = curr -> next;
      m--;
      n--;
    }
    ListNode *next = curr -> next;
    // cout << curr -> val << endl;      
    ListNode *sec = curr -> next;
    while(n > 1){
      sec = sec -> next;
      n--;
    }
    // cout << sec -> val << endl;
    // cout << next -> val << endl;
    ListNode *thr = sec -> next;
    sec -> next = NULL;

    curr -> next = reverse(next);
    next -> next = thr;
    

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
   	vector<int> arry1 = {1,2,3,4,5};
   	ListNode *l1 = Array2List(arry1);

   	ListNode *res = sol.reverseBetween(l1,1,5);

   	printList(res);
   // cout << l1-> val << endl;
	return 0;	
}