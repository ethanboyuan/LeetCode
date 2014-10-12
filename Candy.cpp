#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        int length = ratings.size();
    //    cout << length << endl;
        if(length == 0)
        	return 0;
        if(length == 1)
            return 1;
        vector<int> res (length,1);
        for(int i = 1; i < length; i++){
        	if(ratings[i] > ratings[i-1]){
			res[i]= res[i-1]+1;        	
			}
        	// cout << "finished first scan" << endl;
        }
        for(int i = length - 2; i >= 0; i--){
        	if(ratings[i] > ratings[i+1] && res[i] <= res[i+1]){
			res[i] = res[i+1]+1;        	
			}
        	// cout << "finished second scan" << endl;
        }
        int sum_of_elems = 0;
        for(vector<int>::iterator j=res.begin();j!=res.end();++j)
    		sum_of_elems += *j;
    	return sum_of_elems;
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	vector<int> ratings = {1,3,2,2};

	cout << sol.candy(ratings) << endl;

	return 0;
}