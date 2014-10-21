#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
    	//vector<vector<bool>> f(s.size(),vector<bool>(s.size(),false));

		const int n = s.size();
		if(n <= 1) return s;
    	bool f[n][n];
    	memset(f,false,n);
    	//fill_n(&f[0][0], n*n, false);
    	size_t maxlen = 1, start = 0;
    	for(size_t i = 0; i < s.size(); ++i){
    		f[i][i] = true;
    		for(size_t j = 0; j < i; ++j){
    			f[j][i] = (s[j]==s[i]) && (i-j <2 || f[j+1][i-1]);
    			if(f[j][i] && maxlen < (i-j+1)){
    				maxlen = i-j+1;
					start = j;				
    			}
			}
    	}
    	//cout << start << " " << maxlen << endl;
    	return s.substr(start,maxlen);
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	string s1(1000,'a');
	clock_t begin = clock();
	cout << sol.longestPalindrome(s1) << endl;

	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << elapsed_secs << endl;

	return 0;
}