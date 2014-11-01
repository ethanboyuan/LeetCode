#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
    	const int m = board.size();
    	if(m == 0) return;
    	const int n = board[0].size();
    	if(n == 0) return;
    	for(int i = 0; i < n; i++){
    		bfs(board, 0, i);
    		bfs(board, m-1, i);
    	}    
    	for(int i = 0; i < m; i++){
    		bfs(board, i, 0);
    		bfs(board, i, n-1);
    	}

    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(board[i][j] == 'O')
    				board[i][j] = 'X';
    			else if(board[i][j] == '+')
    				board[i][j] = 'O';
    		}
    	}


    }

    void bfs(vector<vector<char>> &board, int i, int j){
    	typedef pair<int,int> state_t;
    	queue<state_t> q;
    	const int m = board.size();
    	const int n = board[0].size();

    	auto is_valid = [&](const state_t &s){
    		vector<state_t> result;
    		const int x = s.first;
    		const int y = s.second;
    		if(x < 0 || x >=m || y < 0 || y >= n || board[x][y] != 'O')
    			return false;
    		return true;
    	};

    	auto state_extend = [&] (const state_t &s){
    		vector<state_t> result;
    		const int x = s.first;
    		const int y = s.second;
    		const state_t new_states[4] = {{x-1,y},{x+1,y},{x,y-1},{x,y+1}};
    		for(auto &state : new_states){
    			if(is_valid(state)){
    				board[state.first][state.second] = '+';
    				result.push_back(state);
    			}
    		}
    		cout << x << " " << y << endl;
    		for(auto l : result){
    			cout << l.first  << "*" << l.second << endl;
    		}
    		return result;
    	};

    	state_t start = {i,j};
    	if(is_valid(start)) {
    		board[i][j] = '+';
    		q.push(start);
    	}
    	while(!q.empty()){
    		auto curr = q.front(); q.pop();
    		auto new_states = state_extend(curr);
    		for(const auto &s:new_states)
    			q.push(s);
    	}
    }


};


int main(int argc, char* argv[]){
	Solution sol;
	//vector<vector<char>> board = {{'x','x','x','x'},{'x','O','O','x'},{'x','x','O','x'},{'x','O','x','x'}};
	vector<vector<char>> board = {{'X','O','x','O','x','O'},{'O','x','O','x','O','x'},{'X','O','x','O','x','O'},{'O','x','O','x','O','x'}};
	sol.solve(board);
	for(const auto &l : board){
		for(const auto &c :l){
			cout << c << " ";
		}
		cout << endl;
	}


	return 0;
}