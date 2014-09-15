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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
      if(!l1) return l2;
      else if(!l2) return l1;
      else if(!l1 && !l2) return NULL;

      ListNode *dummy = new ListNode(-1);
      ListNode *curr = dummy;
      while(l1 != NULL && l2 != NULL){
        if(l1 -> val < l2 -> val){
            curr -> next = l1; 
            l1 = l1 -> next;
        }
        else{
          curr -> next = l2;
          l2 = l2 -> next;
        }
          curr = curr -> next;
      }

      if(l1 != NULL){
        curr -> next = l1;
      }
      else{
        curr -> next = l2;
      }

      return dummy -> next;

    }

    ListNode *mergeHelper(vector<ListNode *> &lists, int l, int r){
      if(l == r){
     //   cout << l << endl;
        return lists[l];
      }

      int m = l + (r - l)/2;
      ListNode *left = mergeHelper(lists, l, m);
      ListNode *right = mergeHelper(lists, m+1, r);
      return mergeTwoLists(left, right);
    }

    ListNode *mergeKLists(vector<ListNode *> &lists) {
  		int k = lists.size();
  		if(k == 0) 
  			return NULL;
  		if(k == 1)
  			return lists[0];
      return mergeHelper(lists, 0, k-1);

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

   //ListNode *l3 = NULL;
   ListNode *Res = sol.mergeKLists(v1);

   printList(Res);
	 return 0;	
}