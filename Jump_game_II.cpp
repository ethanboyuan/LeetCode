#include <vector>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int jump(int A[], int n) {
        if(n == 1) return 0;
        int step = 0;
        int left = 0, right = 0;
        while(left <= right){
        	++step;
        	const int old_right = right;
        	for(int i = left; i <= old_right; ++i){
        		int new_right = A[i] + i;
        		if(new_right >= n-1) return step;
        		if(new_right > right) right = new_right;

        	}
        	left = old_right + 1;
        }
        return 0;
    }
};


int main(){
	int A[] = {2,3,1,1,4};
	Solution sol;
	cout << sol.jump(A,5) << endl;
	return 0;
}
