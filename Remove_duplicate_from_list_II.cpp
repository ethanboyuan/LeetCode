#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
    	if (!head || !head -> next) 
    		return head;
    	if(head -> val != head -> next -> val){
    		head -> next = deleteDuplicates(head -> next);
    		return head;
    	}
    	ListNode *p = head -> next;
    	while(p && p -> val == head -> val){
    		ListNode *tmp = p;
    		p = p -> next;
    		delete tmp;
    	}
    	delete head;
    	return deleteDuplicates(p);
    }

    ListNode *array2list(vector<int> arry){
    	ListNode *dummy = new ListNode(0);
    	ListNode *curr = dummy;
    	for(auto ii = arry.cbegin(); ii != arry.cend(); ++ii){
    		ListNode *tmp = new ListNode(*ii);
    		curr -> next = tmp;
    		curr = curr -> next;
    	}

    	ListNode *tmp = dummy;
    	tmp = tmp -> next;
    	delete dummy;
    	return tmp;
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


int main(int argc, char* argv[]){
	Solution sol;
	// vector<int> arry {1,2,3,3,4,4,5,6};
	vector<int> arry {1,1,1,2,3,3,4,4,5,6};

	ListNode *l1 = sol.array2list(arry);

	sol.printList(l1);

	ListNode *l2 = sol.deleteDuplicates(l1);
	sol.printList(l2);


	return 0;
}
