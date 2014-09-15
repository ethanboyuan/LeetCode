#include <vector>
#include <iostream>

using namespace std;

 struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 };

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head) {return NULL;}
	    RandomListNode *curr = head;
	// 1. 插入拷贝节点
	    while(curr != NULL){
	    	RandomListNode *tmp = new RandomListNode(curr -> label);
	    	tmp -> next = curr -> next;
	    	curr -> next = tmp;
	    	curr = tmp -> next;
	    }

	// 2. 复制random指针

	    curr = head;
	    while(curr != NULL){
	    	RandomListNode *tmp = curr -> next;
	    	if(curr -> random){
	    		tmp -> random = curr -> random -> next;
	    	}
	    	curr = tmp -> next;
	    }
	// 3.分解至两个独立列表    
	    curr = head;
	    //RandomListNode *tmp = curr -> next;
	    RandomListNode *copyres = curr -> next;
	    while(curr != NULL){
	    	RandomListNode *tmp = curr -> next;
	    	curr -> next = tmp -> next;
	    	if(tmp -> next)
	    		tmp -> next = tmp -> next -> next;
	    	curr = curr -> next;
	    }
	    return copyres;
	    }

};

int main(int argc, char* argv[]){

	return 0;
}