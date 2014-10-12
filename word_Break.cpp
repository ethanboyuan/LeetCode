#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        return dfs(s, dict, 0, 0);
    }
    bool wordBreakDP(string s, unordered_set<string> &dict) {
    	//f(i) = any_of(f(j)&&s[j + 1, i] ∈ dict), 0 ≤ j < i
    	vector<bool> f (s.size()+1, false);
    	f[0] = true;
    	for(int i = 1; i <= s.size(); ++i){
    		for(int j = i-1; j >= 0; --j){
    			if(f[j] && dict.find(s.substr(j,i-j)) != dict.end()){
    				f[i] = true;
    				break;
    			}
    		}
    	}
    	return f.back();
    	// return f[s.size()];
    }


private:
	static bool dfs(string &s, unordered_set<string> &dict, size_t start, size_t cur){
		if(cur == s.size())
			return dict.find(s.substr(start,cur-start+1)) != dict.end();
		if(dfs(s, dict, start, cur+1)) return true;
		if(dict.find(s.substr(start, cur-start+1)) != dict.end()){
			if(dfs(s,dict,cur+1,cur+1))
				return true;
		}
		return false;

	}
};

int main(int argc, char* argv[]){
	Solution sol;
	string s ("leetcode");
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");

	if(sol.wordBreakDP(s,dict))
		cout << "break successful" << endl;
	else
		cout << "break unsuccessful" << endl;

	return 0;
}