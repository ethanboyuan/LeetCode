#include <vector>
#include <iostream>
#include <sstream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp = "";
        string out = "";
        while(is >> tmp){
        	tmp += " ";
        	tmp += out;
        	out = tmp;
        }
        s = out.substr(0,out.length() - 1);
    }
};


int main(int argc, char* argv[]){
   // cout << main.get_id() <<endl;
	Solution sol;
	string t1 = "where there is no trust, there is no love";
	string str = "where there is no trust, there is no love";

	string::iterator end_pos = remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
	// str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
	cout << str << endl;
	sol.reverseWords(t1);
	cout << t1 << endl;
	return 0;
}
