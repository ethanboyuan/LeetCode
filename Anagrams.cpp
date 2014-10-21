#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> group;
        for(const auto &it :strs){
        	string key = it;
        	sort(key.begin(),key.end());
        	group[key].push_back(it);
        }

        vector<string> result;
        for(auto it = group.cbegin(); it != group.cend(); ++it){
        	if(it -> second.size() > 1)	
        		result.insert(result.end(), it -> second.begin(), it -> second.end());
        }

        return result;
    }
};


int main(int argc, char* argv[]){
	Solution sol;
	vector<string> strs = {"hello", "lloeh"};
	vector<string> res = sol.anagrams(strs);
	for(const auto &it : res)
		cout << it << endl;

	return 0;
}