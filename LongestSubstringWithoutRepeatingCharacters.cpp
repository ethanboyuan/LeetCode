#include <vector>
#include <iostream>
#include <algorithm>    // std::max
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //int last[26];
        
        unordered_map<char, int> last_ocr;

        int start = 0;
       // fill(last,last+26,-1);
        int max_len = 0;
        for(int i = 0; i < s.size(); ++i){
        	if(last_ocr.find(s[i]) != last_ocr.end()){
        		if(last_ocr[s[i]] >= start){
	        		max_len = max(max_len,i-start);
	        		start = last_ocr[s[i]] + 1;

        		}
        	}

        	last_ocr[s[i]] = i;
        	// if(last[s[i] - 'a'] > start){
        	// 	last[s[i]- 'a'] = start + 1;
        	// 	max_len = max(max_len,i - start);
        	// }
        	// last[s[i] - 'a'] = i;
        }

        // for(auto ele = last_ocr.begin();  ele != last_ocr.end(); ++ele){
        // 	cout << ele -> first << " " << ele -> second << endl;
        // }
        //return max_len;
        return max(max_len, (int)s.size() - start);
    }
};


int main(int argc, char* argv[]){
	Solution sol;
	cout << sol.lengthOfLongestSubstring("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco") << endl;


	return 0;
}