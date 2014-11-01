#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int sqrt(int x){
		int left = 1, right = x/2;
		int last_mid;

		if(x < 2)
			return x;

		while(left <= right){
			const int mid = left + (right - left)/2;
			if(x/mid > mid){
				left = mid + 1;
				last_mid = mid;
			}
			else if(x / mid < mid){
				right = mid - 1;
			}
			else {
				return mid;
			}


		}
		return last_mid;
	}

};


int main(int argc, char* argv[]){
	Solution sol;
	cout << sol.sqrt(5) << endl;

	return 0;

}
