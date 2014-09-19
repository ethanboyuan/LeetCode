
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:

	int uniquePaths(int m, int n) {
	/*	if (m == 0 || n == 0) {return 0;}
		if (m == 1) return 1;
		if (n == 1) return 1;
		int upath = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		return upath;  */
		vector<vector<int> > table(m, vector<int>(n, 1)); 
		for(int i = 1; i < m; i++){
			for(int j = 1; j < n; j++){
				table[i][j] = table[i-1][j] + table[i][j-1];
			}
		}
		return table[m-1][n-1];

	}

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int row = obstacleGrid.size();
    	if(row == 0) return 0;
    	int col = obstacleGrid[0].size();
    	if(col == 0) return 0;

    	if(obstacleGrid[0][0])
    		return 0;

    	if(row == 1){
    		for(int i = 0; i < col; i++){
    			if(obstacleGrid[0][i])
    				return 0;
    		}
    		return 1;
    	}
    	if(col == 1){
    		for(int i = 0; i < row; i++){
    			if(obstacleGrid[i][0])
    				return 0;
    		}
    		return 1;
    	}

    	for(int i = 0; i < row; i++){
    		if(obstacleGrid[i][0]){
    			while(i < row){
	    			obstacleGrid[i][0] = 0;
	    			i++;
    			}
    		}
    		else 
    			obstacleGrid[i][0] = 1;
    	}

    	for(int i = 1; i < col; i++){
    		if(obstacleGrid[0][i]){
    			while(i < col){
    				obstacleGrid[0][i] = 0;
    				i++;
    			}
    		}
    		else 
    			obstacleGrid[0][i] = 1;
    	}
    	

		for(int i = 1; i < row; i++){
			for(int j = 1; j< col; j++){
				if(obstacleGrid[i][j])
					obstacleGrid[i][j] = 0;
				else 
					obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
			}
		}
    	return obstacleGrid[row-1][col-1];    
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	vector<vector<int>> m;
	vector<int> l1 = {0,0,0};
	vector<int> l2 = {0,1,0};
	vector<int> l3 = {0,0,0};

	m.push_back(l1);
	m.push_back(l2);
	m.push_back(l3);

	cout << sol.uniquePathsWithObstacles(m) << endl;
	return 0;
}