#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;

        for(auto i = path.begin(); i != path.end();){
        	++i;
        	auto j = find(i,path.end(), '/');
        	auto dir = string(i,j);

        	if(!dir.empty() && dir != "."){
        		if(dir == ".."){
        			if(!dirs.empty())
        				dirs.pop_back();
        		} else{
        			dirs.push_back(dir);
        		}

        	}
        	i = j;

        }
        	
        string res;
        if(dirs.empty())
        	res = "/";
        else{
        	for(auto dir: dirs)
        		res += "/" + dir;
        }
        return res;
    }
};


int main(int argc, char* argv[]){
	Solution sol;
	cout << sol.simplifyPath("/a/./b/../../c/") << endl;
	return 0;
}
