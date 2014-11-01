#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> current, next;
		unordered_set<string> visited;

		int level = 0;
		bool found = false;

		auto state_is_target = [&](const string &s) {return s == end;};
		auto state_extend = [&](const string &s) {
			vector<string> result;

			for(size_t i = 0; i < s.size(); ++i){
				string new_word(s);
				for(char c = 'a'; c <= 'z'; c++){
					if(c == new_word[i])
						continue;
					swap(c, new_word[i]);

					if((dict.count(new_word) || state_is_target(new_word)) > 0 && !visited.count(new_word)){
						// cout << "going to " << new_word << endl;
						// for(auto & ii: visited){
						// 	cout << ii << endl;
						// }
						result.push_back(new_word);
						visited.insert(new_word);
					}

					swap(c, new_word[i]);
				}
			}

			return result;
		};

		current.push(start);

		while(!current.empty() && !found){
			++level;
			while(!current.empty() && !found){
				const string str = current.front();
				current.pop();

				const auto& new_states = state_extend(str);
				for(const auto& state: new_states){
					next.push(state);											
					//cout <<"state is " << state << endl;

					if(state_is_target(state)){
						found = true;
						break;
					}
				}
			}
			swap(next,current);
		}

		if(found) 
			return level + 1;
		else
			return 0;

    }
};


int main(int argc, char* argv[]){
	Solution sol;
	string start = "hit", end = "cog";
	unordered_set<string> dict = {"hot","dot","dog","log","lot"};
	cout << sol.ladderLength(start,end,dict) << endl;
	return 0;
}