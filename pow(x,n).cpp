#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

	double pow(double x, int n){
		if(n < 1.0)
			return 1.0/power(x, -n);
		else return power(x,n);
	}

private:
	double power(double x, int n){
		if(n== 0)
			return 1;
		double v = power(x, n/2);
		if(n % 2 == 0)
			return v*v;
		else 
			return v*v*x;
	}

};



int main(int argc, char* argv[]){
	Solution sol;
	cout << sol.pow(3,-5) << endl;
	return 0;

}
