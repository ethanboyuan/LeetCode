#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
	int getkth(int s[], int m, int l[], int n, int k){
		if(m > n) 
			return getkth(l,n,s,m,k);
		if(m == 0)
			return l[k - 1];
		if(k == 1)
			return min(s[0], l[0]);

		int i = min(m,k / 2), j = min(n, k / 2);
		
		if(s[i - 1] > l[j - 1])
			return getkth(s,m,l+j,n-j,k-j);
		else
			return getkth(s+i, m-i, l, n, k-i);
		return 0;
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int l = (m + n + 1) / 2;
        int r = (m + n + 2) / 2;
        cout << l << r << endl;
        return (getkth(A,m,B,n,l) + getkth(A,m,B,n,r)) / 2.0;
    }
};


int main(int argc, char* argv[]){
	int A[] = {1};
	//int B[] = {6,7,8,9,10};
	int B[] ={};
	Solution sol;
	cout << sol.findMedianSortedArrays(A, 1, B, 0) << endl;
	return 0;
}
