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
    vector<vector<string>> findLadders(string start, string end,  unordered_set<string> &dict) {
    	vector<vector<string>> ladders;
  		unordered_set<string> current, next;
  		unordered_set<string> visited;
      unordered_map<string,vector<string>> father;

  		bool found = false;

  		auto state_is_target = [&](const string &s) {return s == end;};
  		auto state_extend = [&](const string &s){
  			unordered_set<string> result;

  			for(size_t i = 0; i < s.size(); ++i){
  				string new_word(s);
  				for(char c = 'a'; c<= 'z'; c++){
  					if(c == new_word[i])
  						continue;
  					swap(c,new_word[i]);
  					if((dict.count(new_word) > 0 || state_is_target(new_word)) && !visited.count(new_word)) {
              //cout << "inserting " << new_word << endl;
  						//visited.insert(new_word);
  						result.insert(new_word);
  					}

  					swap(c,new_word[i]);
  				}

  			}
  			return result;

  		};
  		current.insert(start);

  		while(!current.empty() && !found){
    			for(const auto &word :current){
            visited.insert(word);
          }

  				for(const auto &word: current){
            const auto& new_states = state_extend(word);
            for(const auto &state: new_states){
//              cout << "state is " << state << endl;
              if(state_is_target(state)){
                  found = true;}
              next.insert(state);

              father[state].push_back(word);
              
            }
  			}
        current.clear();
  			swap(next,current);

  		}
      if(found){
        vector<string> path;
        gen_path(father,path,start,end,ladders);
      }
      return ladders;

    }

private:
    void gen_path(unordered_map<string,vector<string>> &father, vector<string> &path, const string &start, const string &word, vector<vector<string>> &result){
      path.push_back(word);
      if(word == start){
        result.push_back(path);
        reverse(result.back().begin(),result.back().end());
      } else{
        for(const auto &f : father[word]){
          gen_path(father,path,start,f,result);
        }
      }
      path.pop_back();
    }

};



int main(int argc, char* argv[]){
	Solution sol;
	string start = "hit", end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","log","lot"};
	vector<vector<string>> result = sol.findLadders(start,end,dict);
  for(size_t ii = 0; ii < result.size(); ++ii){
    for(size_t jj = 0; jj < result[ii].size(); ++jj){
      cout << result[ii][jj] << " ";
    }
    cout << endl;
  }
	return 0;
}