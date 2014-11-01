#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited (m, vector<bool> (n,false));
        for(int i = 0; i < m; i++){
        	for(int j = 0; j < n; j++){
        		if(DFS(board,word,0,i,j,visited))
        			return true;
        	}
        }
        return false;
    }

private:
    static bool DFS(vector<vector<char>> & board, string word, int index, int x, int y, vector<vector<bool>>& visited){
    	if(index == word.size())
    		return true;

    	if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
    		return false;
    	if(visited[x][y])
    		return false;
    	if(board[x][y] != word[index])
    		return false;

    	visited[x][y] = true;

    	bool ret = DFS(board, word, index+1, x+1, y, visited) || DFS(board, word, index+1, x-1, y, visited) || DFS(board, word, index+1, x, y+1, visited) || DFS(board, word, index+1, x, y-1, visited);

    	visited[x][y] = false;

    	return ret;

    }
};


int main(int argc, char* argv[]){
	Solution sol;
	vector<vector<char>> board = {{'a','b'}};
	string word = "ba";
	if(sol.exist(board,word))
		cout << "break successful" << endl;

	return 0;

}
