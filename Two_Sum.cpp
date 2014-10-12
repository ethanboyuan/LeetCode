#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
    	unordered_map <int, int> path;
		vector<int> result;

    	for(int ii = 0; ii < numbers.size(); ++ii){
    		path[numbers[ii]] = ii;
    	}
    	for(int ii = 0; ii < numbers.size(); ++ii){
    		const int gap = target - numbers[ii];
    		if(path.find(gap) != path.end() && path[gap] > ii){
    			result.push_back(ii+1);

    			result.push_back(path[gap]+1);
    			break;
    		}
    	}
		return result;        
    }
};


int main(int argc, char* argv[]){
	Solution sol;
	vector<int> numbers {2,7,11,15};
	vector<int> res = sol.twoSum(numbers,9);
	for(auto ii = res.cbegin(); ii != res.cend(); ++ii){
		cout << *ii << " ";
	}

	cout << endl;
	return 0;
}