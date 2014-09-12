
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class solution{
public:

unordered_map<char, string> dig2char;
Solution(){
	dig2char['2'] = "abc";
	dig2char['3'] = "def";
	dig2char['4'] = "ghi";
	dig2char['5'] = "jkl";
	dig2char['6'] = "mno";
	dig2char['7'] = "pqrs";
	dig2char['8'] = "tuv";
	dig2char['9'] = "wxyz";
}

vector<string> letterCombinations(string digits) {
	vector<string> res; 
	if(digits.size() == 0) {
		res.push_back("");
		return res;
	}

	vector<string> temp = letterCombinations(digits.substr(1));
	for(int i = 0; i < temp.size(); i++){
		for(int j = 0; j < dig2char[digits[0]].size(); j++){
			res.push_back(dig2char[digits[0]][j] + temp[i]);
		}
	}

	return res;    
}



};
	  
int main(int argc, char* argv[]){
	Solution s1;

	vector<string> letterCombRes = s1.letterCombinations("3");
	for(int i = 0; i < letterCombRes.size(); i ++){
	 	cout << letterCombRes[i] << endl;
	}
	return 0;
}

	
