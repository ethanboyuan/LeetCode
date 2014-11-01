#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
		stack<string> s;
		for(auto token: tokens){
			if(!isOperator(token))
				s.push(token);
			else{
				int y = stoi(s.top());s.pop();
				int x = stoi(s.top());s.pop();
				if(token == "*") x *= y;
				else if(token == "/") x/= y;
				else if(token == "-") x-= y;
				else x += y;
				s.push(to_string(x));
			}
		}
		return stoi(s.top());
    }

    bool isOperator(string op){
    	return op.size() == 1 && string("+-*/").find(op) != string::npos;
    }
};


int main(int argc, char* argv[]){
	Solution sol;
	vector<string> tokens = {"2", "1", "+", "3", "*"};
	cout << sol.evalRPN(tokens) << endl;
	return 0;
}
