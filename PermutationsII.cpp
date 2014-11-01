#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int>> result;
    	sort(num.begin(),num.end());
    	do{
    		result.push_back(num);
    	}while(next_permutation(num));

    	return result;
        
    }

    bool next_permutation(vector<int> &num){
    	vector<int>:: iterator part = prev(num.end(),1);
    	while(part != num.begin() && *(prev(part)) >= *(part)) {--part;}
    	if(part == num.begin()){
    		reverse(num.begin(),num.end());
    		return false;
    	}

    	part = prev(part);

    	vector<int>:: iterator change = prev(num.end());
    	while(change >= part && *(change) <= *part){--change;}
    	swap(*part,*change);
    	reverse(next(part), num.end());
    	return true;
    }

};

void printvector(vector<int> &num){

    vector<int>::const_iterator i;
    
    for(i=num.begin(); i!=num.end(); ++i){
        cout<<(*i);
        cout<<" ";
    }
    cout<<endl;    
}

void printmatrix(vector<vector<int>> &matrix){
	int row = matrix.size();
	for (int i = 0; i < row; i++){
		printvector(matrix[i]);
	}

}

int main(int argc, char* argv[]){
	Solution sol;
	//vector<int> num {6,8,7,4,3,2};
	//reverse(num.begin(),num.end());
	//printvector(num);
	vector<int> num {1,1};
	sol.next_permutation(num);
	printvector(num);
	vector<vector<int>> res = sol.permuteUnique(num);

	printmatrix(res);
	//sol.next_permutation(num);
	return 0;
}