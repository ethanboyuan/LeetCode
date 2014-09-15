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

	ListNode *mergeSorted(ListNode *l1, ListNode *l2){
		if(!l1 && !l2) {return NULL;}
		else if(!l1) {return l2;}
		else if(!l2) {return l1;}

		ListNode *dummy = new ListNode(-1);
		ListNode *curr = dummy;
		while(l1 != NULL && l2 != NULL){
			if(l1 -> val > l2 -> val){
				curr -> next = l2;
				l2 = l2 -> next;
			}
			else{
				curr -> next = l1;
				l1 = l1 -> next;
			}
			curr = curr -> next;
		}
		if(l1){
			curr -> next = l1;
		}
		else{
			curr -> next = l2;
		}
		return dummy -> next;
	}

    ListNode *sortList(ListNode *head) {
    	if(!head) {return NULL;}
    	if(head -> next == NULL) {return head;}
// (1) Split the list (slow fast pointers)
    	ListNode* slow = head;
    	ListNode* lend;
    	ListNode* fast = head;
    	while(fast != NULL && fast -> next != NULL){
    		lend = slow;
    		slow = slow -> next;

    		//if(fast -> next)
    			fast = fast -> next -> next;
    	}
    	// cout << "find end" << endl;
    	ListNode *l = head;

    	ListNode *r = lend -> next; 
    	lend -> next = NULL;
    	// printList(l);
    	// printList(r);
// (2) sort the first part (merge sort)
    	ListNode *sortedl = sortList(l);

// (3) sort the second part (merge sort)
    	ListNode *sortedr = sortList(r);

// (4) merge the two parts (merge two sorted lists)
    	ListNode *res = mergeSorted(sortedl,sortedr);
        return res;
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
    vector<int> arry1 = {5,3,2,1,4,7,8};
    ListNode *l1 = Array2List(arry1);
   
    vector<int> arry2 = {6,7,8,9,10};
    ListNode *l2 = Array2List(arry2);
   	//ListNode *l3 = sol.mergeSorted(l1,l2);

   	ListNode *l3 = sol.sortList(l1);
   	printList(l3);
	return 0;
}