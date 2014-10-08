#include <vector>
#include <iostream>
#include <string>

using namespace std;
//using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        //for(auto &c : s)
        //	c = tolower(c);
    	transform(s.begin(),s.end(),s.begin(), ::tolower);
        auto l = s.begin();
        auto r = s.end();
        while(l < r){
        	if(!isalnum(*l)){
        		l++;
        	}
        	else if(!isalnum(*r)){
        		r--;
        	}
        	else{
        		if(*l == *r) {
        			l++;
        			r--;
        		}
        		else{
        			return false;
        		}
        	}
        }

        return true;

    }
};

int main(int argc, char* argv[]){
	Solution sol;

	string s("A man, a plan, a canal: Panama");
	// string s("race a car");

	if(sol.isPalindrome(s)){
		cout << s << " is Palindrome" << endl;
	}

	else 
		cout << s << " is not a Palindrome" << endl;


	return 0;
}