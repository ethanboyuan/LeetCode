#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
  		string cache (n, '0');
  		for(int i = 0; i < cache.size(); ++i){
  			cache[i] += 1+i;
  		}

  		int base = factorial(n - 1);

  		string res;
  		int newk = k -1;
  		for(int i = 0; i < n-1; ++i){
  			auto c = next(cache.begin(), newk/base);
  			res.push_back(*c);

			newk = newk % base;
			base /= (n - i - 1);
			cache.erase(c);
			//cout << base << endl;
  		}
  		res.push_back(cache[0]);
  		return res;
    }
private:
	int factorial(int n){
		int res = 1;
		for(int i = 1; i <= n; ++i){
			res *= i;
		}
		return res;
	}
};

int main(int argc, char* argv[]){
	Solution sol;
	string res = sol.getPermutation(9,250);
	cout << res << endl;
	return 0;	
}
