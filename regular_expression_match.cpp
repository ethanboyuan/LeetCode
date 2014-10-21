#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0') return *s == '\0';
        if( *(p+1) != '*'){
        	if(*s == *p || (*p == '.' && *s != '\0'))
        		return isMatch(s+1,p+1);
        	else 
        		return false;
        }else{
        	while(*s == *p || (*p == '.' && *s != '\0')){
				if(isMatch(s,p+2)) return true;
        		++s;
        	}
        	return isMatch(s,p+2);
        }

    }
};

void print_res(Solution sol, const char* s, const char* p){
	if(sol.isMatch(s,p))
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

int main(int argc, char* argv[]){
	Solution sol;
	print_res(sol,"aa","a");
	print_res(sol,"aa","aa");
	print_res(sol,"aaa","aa");
	print_res(sol,"aa","a*");
	print_res(sol,"aa",".*");
	print_res(sol,"ab",".*");
	print_res(sol,"aab", "c*a*b");




	return 0;
}