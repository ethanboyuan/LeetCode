#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(const char *s) {
    	enum InputType{
    		INVALID,	//0
    		SPACE,		//1 ' '
    		SIGN,		//2 '-','+'
    		DIGIT,		//3 numbers
    		DOT,		//4 '.'
    		EXPONENT,	//5 'e' 'E'

    	};
    	int TransitionTable[][6] = {
            //0INVA,1SPA,2SIG,3DI,4DO,5E  
            -1,  0,  3,  1,  2, -1,//0初始无输入或者只有space的状态  
            -1,  8, -1,  1,  4,  5,//1输入了数字之后的状态  
            -1, -1, -1,  4, -1, -1,//2前面无数字，只输入了Dot的状态  
            -1, -1, -1,  1,  2, -1,//3输入了符号状态  
            -1,  8, -1,  4, -1,  5,//4前面有数字和有dot的状态  
            -1, -1,  6,  7, -1, -1,//5'e' or 'E'输入后的状态  
            -1, -1, -1,  7, -1, -1,//6输入e之后输入Sign的状态  
            -1,  8, -1,  7, -1, -1,//7输入e后输入数字的状态  
            -1,  8, -1, -1, -1, -1,//8前面有有效数输入之后，输入space的状态  
    	};

    	int state = 0;

    	while(*s){
    		InputType inputtype = INVALID;
    		if(isspace(*s)) inputtype = SPACE;
    		else if(isdigit(*s)) inputtype = DIGIT;
    		else if(*s == '-' || *s == '+') inputtype = SIGN;
    		else if(*s == '.') inputtype = DOT;
    		else if(*s == 'e' || *s == 'E') inputtype = EXPONENT;

    		state = TransitionTable[state][inputtype];
    		++s;
    		if (state == -1) return false;
    	}
    	return state == 1 || state == 4 || state == 7 || state == 8;
        
    }
};

int main(int argc, char* argv[]){
	Solution sol;
    char s[] = "3. ";
    if(sol.isNumber(s))
        cout << s << " is digit" << endl;
    else
        cout << s << " is not digit" << endl;

	return 0;
}