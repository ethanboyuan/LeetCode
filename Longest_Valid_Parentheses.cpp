#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int max_len = 0, lefts = -1;
        stack<int> left;
        for(int i = 0; i < s.size(); ++i){
        	if(s[i] == '('){
        		left.push(i);
        	}
        	else{
        		if(left.empty()){
        			lefts = i;
        		}
        		else{
        			left.pop();
        			if(left.empty()){
        				max_len = max(max_len, i - lefts);
        			} else{
        				max_len = max(max_len, i - left.top());
        			}

        		}
        	}
        }
        return max_len;
    }
};



int main(int argc, char* argv[]){
	Solution sol;
	cout << sol.longestValidParentheses(")()())") << endl;
	return 0;
}
