#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
    	vector<vector<string>> result;
    	vector<string> path;
    	DFS(s,path,result,0);
    	return result;	    
    }

    void DFS(string &s, vector<string> &path, vector<vector<string>> & result, int start){
    	if(start == s.size()){
    		result.push_back(path);
    		return;
    	}

    	for(int i = start; i < s.size(); ++i){
    		if(isPalindrome(s,start,i)){
    			path.push_back(s.substr(start,i-start+1));
    			DFS(s,path,result,i+1);
    			path.pop_back();
    		}
    	}
    }

    bool isPalindrome(const string &s, int start, int end){
    	while(start < end && s[start] == s[end]){
    		++start;
    		--end;
    	}
    	return start >= end;
    }

};


int main(int argc, char* argv[]){
	Solution sol;
	string s = "aab";
	vector<vector<string>>  res = sol.partition(s);
	for(auto &l : res){
		for(auto & w: l){
			cout << w << " ";
		}
		cout << endl;
	}

	return 0;
}