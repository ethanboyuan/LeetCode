#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
    	for(int x = 0; x < 9; x++){
    		for(int y = 0; y < 9; y++){
    			if(board[x][y] == '.'){
    				for(int k = 0; k < 9; k++){
    					board[x][y] = '1' + k;
    					if(isValid(board,x,y) && solveSudoku(board))
    						return true;
    					board[x][y] = '.';
    				}
    				return false;
    			}

    		}
    	}
    	return true;
        
    }

    bool isValid(const vector<vector<char>> & board, int x, int y){
    	for(int i = 0; i < 9; i++){
    		if(i != x && board[i][y] == board[x][y])
    			return false;
    	}
    	for(int i = 0; i < 9; i++){
    		if(i != y && board[x][i] == board[x][y])
    			return false;
    	}

    	int box_x = x/3;
    	int box_y = y/3;

    	for(int i = box_x*3; i < box_x*3 + 3; i++){
    		for(int j = box_y*3; j < box_y*3 + 3; j++){
    			if((i != x || j != y) && board[i][j] == board[x][y])
    				return false;
    		}
    	}

    	return true;
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	vector<string> b1 =  {"..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."};
	vector<vector<char>> board;

	for(auto &s : b1){
		vector<char> temp (s.begin(),s.end());
		board.push_back(temp);
	}
	sol.solveSudoku(board);
	for(auto &l : board){
		string temp (l.begin(),l.end());
		cout << temp << endl;
	}
	return 0;

}
