#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:

	void printvector(vector<int> &num){

	    vector<int>::const_iterator i;
	    
	    for(i=num.begin(); i!=num.end(); ++i){
	        cout<<(*i);
	        cout<<" ";
	    }
	    cout<<endl;    
	}
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
 		vector<int> res;
 		if(matrix.size() == 0) 
 			return res;
 		int row = matrix.size();
 		int col = matrix[0].size();
 		int count = 0;
 		int n = 0;
 		if(col == 1){
 			for(int i = 0; i < row; i++){
 				res.push_back(matrix[i][0]);
 				
 			}
 			return res;
 		}
 		while(count < row * col){
 			for(int i = n; i < col - n; i++){
 				res.push_back(matrix[n][i]);
 				count++;
 			}
 			if(count >= row*col)
 				break;
 			for(int i = n+1; i < row-n; i++){
 				res.push_back(matrix[i][col-n-1]);
 				count++;
 			}
			if(count >= row*col)
 				break;
 			for(int i = col-n-2; i > n; i--){
 				res.push_back(matrix[row-n-1][i]);
 				count++;
 			}
			if(count >= row*col)
 				break;
 			for(int i = row-n-1; i > n; i--){
 				res.push_back(matrix[i][n]);
 				count++;
 			}
 			if(count >= row*col)
 				break;
 			n++;

 		}       

 		return res;

    }
};

int main(int argc, char* argv[]){
	vector<int> l1 = {1};
	//vector<int> l2 = {2};
	vector<int> l2 = {4};
	vector<int> l3 = {7};
	vector<vector<int> > m;
	m.push_back(l1);
	m.push_back(l2);
	// m.push_back(l3);
	Solution sol;
	vector<int> res = sol.spiralOrder(m);
	sol.printvector(res);

 	return 0;
}