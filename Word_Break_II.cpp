#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        
    	//f(i) = any_of(f(j)&&s[j + 1, i] ∈ dict), 0 ≤ j < i
    	vector<bool> f (s.size()+1, false);
       	vector<vector<bool>> prev (s.size()+1, vector<bool> (s.size(), false));

    	f[0] = true;
    	for(int i = 1; i <= s.size(); ++i){
    		for(int j = i-1; j >= 0; --j){
    			if(f[j] && dict.find(s.substr(j,i-j)) != dict.end()){
    				f[i] = true;
    				//break;
    				prev[i][j] = true;
    			}
    		}
    	}

    	vector<string> res;
    	vector<string> path;
    	gen_path(s, prev, s.length(), path, res);
    	return res;
    	// return f[s.size()];
    }



private:
	void gen_path(const string &s, const vector<vector<bool>> &prev, int cur, vector<string> &path, vector<string> &result){
		if(cur == 0){
			string tmp;
			for(auto iter = path.crbegin(); iter != path.crend(); ++iter){
				tmp += *iter + " ";
			}
			tmp.erase(tmp.end() - 1);
			result.push_back(tmp);
		}

		for(size_t i = 0; i < s.size(); ++i){
			if(prev[cur][i]){
				path.push_back(s.substr(i, cur - i));
				gen_path(s,prev,i,path,result);
				path.pop_back();
			}
		}

	}
	
};

int main(int argc, char* argv[]){
	Solution sol;
	string s ("catsanddog");
	unordered_set<string> dict;
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("and");
	dict.insert("sand");
	dict.insert("dog");

	vector<string> result = sol.wordBreak(s, dict);
	for(auto iter = result.cbegin(); iter != result.cend(); ++iter){
		cout << *iter << endl;
	}
	// if(sol.wordBreakDP(s,dict))
	// 	cout << "break successful" << endl;
	// else
	// 	cout << "break unsuccessful" << endl;

	return 0;
}