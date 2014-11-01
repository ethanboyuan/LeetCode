#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isMatch_Recursive(const char *s, const char *p) {
        if(*p == '*'){
        	while(*p == '*') ++p;
        	if(*p == '\0') return true;
        	while(*s != '\0' && !isMatch_Recursive(s,p)) ++s;
        	return *s != '\0'; 
        } else if(*p == '\0' || *s == '\0') return *p == *s;
        else if(*p == *s || *p == '?') return isMatch_Recursive(++s,++p);
        else return false;


    }
    bool isMatch(const char *s, const char *p) {
    	const char* star = NULL;
    	const char* ss = s;
    	while(*s){
    		if((*p == '?') || (*p == *s)) {
    			++s;++p;
    			continue;
    		}
    		if(*p == '*') { 
    			star = p++;
    			ss = s;
    			continue;
    		}
    		if(star){
    			p = star + 1;
    			s = ++ss;
    			continue;
    		}
    		return false;
    	}
    	while (*p == '*') {++p;}
    	return !*p;
    }

};

void print_res(Solution sol, const char* s, const char* p){
	if(sol.isMatch(s,p))
		cout << s << "  " << p << " True" << endl;
	else
		cout << s << "  " << p << " False" << endl;
}

int main(int argc, char* argv[]){
	Solution sol;
	print_res(sol, "aa", "a*");


	return 0;
}
