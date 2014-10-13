#include <vector>
#include <iostream>

using namespace std;

 
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode *head) {
    	if(!head || !head -> next)	return;

     	ListNode * fast = head;
     	ListNode * slow = head;
     	ListNode  * prev;
     	while(fast != NULL && fast -> next != NULL){
     		prev = slow;
     		slow = slow -> next;
     	    fast = fast -> next -> next;
     	}
     	prev -> next = NULL;
     	ListNode * first = head;
     	ListNode * second = reverse(slow);

     	while(first -> next != NULL){
     		ListNode * tmp = first -> next;
     		first -> next = second;
     		second = second	-> next;
     		first -> next -> next = tmp;
     		first = tmp;
     	}
     	first -> next = second;

    }

private:
	ListNode* reverse(ListNode *head){
		if(!head)
			return head;
		ListNode * curr = head;
		ListNode * next;
		ListNode * prev = NULL;
		while(curr != NULL){
			next = curr -> next;
			curr -> next = prev;
			prev = curr;
			curr = next;

		}

		return prev;



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



int main(int argc, char* argv[]){
	Solution sol;
	ListNode *l1 = Array2List({2,1,3,4});
	sol.reorderList(l1);

	return 0;
}
