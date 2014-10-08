#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int total = 0;
        int total_cost = 0;
        int start_index = -1;
        for(int i = 0; i < gas.size(); i++){
        	total += gas[i] - cost[i];
        	total_cost += gas[i] - cost[i]; 
        	if(total < 0){
        		total = 0;
        		start_index = i;
        	}
        }
        if(total_cost >= 0)
        	return start_index+1;
        else 
        	return -1;
    }
};

int main(int argc, char* argv[]){
	Solution sol;

	return 0;
}