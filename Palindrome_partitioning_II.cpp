#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
    	const int n = s.size();
    	bool P[n][n];
    	int f[n+1];
    	fill_n(&P[0][0],n*n,false);

    	for(int i = 0; i < n+1; i++)
    		f[i] = n - (i+1);

    	for(int i = n-1; i >= 0; i--){
    		for(int j = i; j < n; j++){
    			if(s[i] == s[j] && (j - i < 2 || P[i+1][j-1])){
    				P[i][j] = true;
    				f[i] = min(f[j+1]+1, f[i]);
    			}
    		}

    	}

    
    	return f[0];
        
    }
};

int main(int argc, char* argv[]){
	Solution sol;

	cout << sol.minCut("ab") << endl;

	return 0;
}