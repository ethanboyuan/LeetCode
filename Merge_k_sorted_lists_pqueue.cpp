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
private:
	struct cmp{
		bool operator()(const ListNode*l1, const ListNode*l2){
			return l1 ->val > l2 -> val;
		}
	};
public:
	
    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	int n = lists.size();
    	if(n == 0) return NULL;
    	ListNode node(0), *res = &node;
    	priority_queue<ListNode*, vector<ListNode*>, cmp> que;

    	for(int i = 0; i< n; i++){
    		if(lists[i]) 
    			que.push(lists[i]);
    	}

    	while(!que.empty()){

    		ListNode*p = que.top();
    		que.pop();

    		res -> next = p;
    		res = p;

    		if(p -> next)
    			que.push(p->next);

    	}
    	return node.next;
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
   // cout << std::thread::hardware_concurrency() << endl;
   //cout << get_id(main) << endl;
   vector<int> arry1 = {1,2,3,4,5};
   ListNode *l1 = Array2List(arry1);
   
   vector<int> arry2 = {6,7,8,9,10};
   ListNode *l2 = Array2List(arry2);
   
   vector<int> arry3 = {6,7,8,9,10};
   ListNode *l3 = Array2List(arry3);

   vector<int> arry4 = {2,27,28,29,210};
   ListNode *l4 = Array2List(arry4);

   vector<ListNode *> v1;
   v1.push_back(l1);
   v1.push_back(l2);
   v1.push_back(l3);
   v1.push_back(l4);

   ListNode *Res = sol.mergeKLists(v1);

   printList(Res);

	return 0;
}
