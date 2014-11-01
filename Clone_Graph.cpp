/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
 	UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr)
        	return nullptr;
        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        clone(node, copied);
        return copied[node];
    }

    UndirectedGraphNode *cloneGraphBFS(UndirectedGraphNode *node) {
    	if(node == nullptr)
        	return nullptr;

        unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> copied;
        queue<const UndirectedGraphNode *> q;

        copied[node] = new UndirectedGraphNode(node -> label);

        q.push(node);
        while(!q.empty()){
        	const UndirectedGraphNode *cur = q.front();
        	q.pop();
        	for(auto & nbr: cur -> neighbors){
        		if(copied.find(nbr) != copied.end()){
        			copied[cur] -> neighbors.push_back(copied[nbr]);
        		} else{
        			UndirectedGraphNode *new_node = new UndirectedGraphNode(nbr -> label);
        			copied[nbr] = new_node;
        			copied[nbr] -> neighbors.push_back(new_node);
        			q.push(nbr);
        		}
        	}
        }

        return copied[node];



    }


private:
	static UndirectedGraphNode *clone(const UndirectedGraphNode *node, unordered_map<const UndirectedGraphNode *, UndirectedGraphNode *> &copied){
		if(copied.find(node) != copied.end())
			return copied[node];
		UndirectedGraphNode * new_node = new UndirectedGraphNode(node -> label);
		copied[node] = new_node;
		for(auto nbr : node -> neighbors){
			new_node -> neighbors.push_back(clone(nbr,copied));
		}
		return copied[node];
	}
};


int main(int argc, char* argv[]){
	Solution sol;


	return 0;
}