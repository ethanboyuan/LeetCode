#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
    	vector<vector<int>> result;
    	sort(num.begin(),num.end());
        vector<int> path;
    	dfs(num,path,result);
    	return result;
        
    }
private:
    void dfs(const vector<int>& num, vector<int> &path, vector<vector<int>> &result){
        if(path.size() == num.size()){
            result.push_back(path);
            return;
        }
        for(auto i: num){
            auto pos = find(path.begin(), path.end(), i);
            if(pos == path.end()){
                path.push_back(i);
                dfs(num,path,result);
                path.pop_back();
            }
        }

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
	//printvector(num);
	vector<vector<int>> res = sol.permute(num);

	printmatrix(res);
	//sol.next_permutation(num);
	return 0;
}