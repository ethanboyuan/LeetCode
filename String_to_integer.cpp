#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int atoi(const char *str) {
  		int num = 0, sign = 1, i = 0;
  		const int n = strlen(str);
  		while(str[i] == ' '){++i;}
  		if(str[i] == '-'){
  			sign = -1;
  			++i;
  		}
  		else if(str[i] == '+') {
  			++i;
  		}
  		for(; i < n; ++i){
  			if(str[i] < '0' || str[i] > '9')
  				break;
  			if(num > INT_MAX/10 || (num == INT_MAX/10 && (str[i] - '0' ) > INT_MAX % 10)){
  				return sign == -1 ?INT_MIN:INT_MAX;
  			}
  			else{
  				num = num * 10 + (str[i] - '0');
  			}
  		}
  		return sign*num;

    }
};

int main(int argc, char* argv[]){
	Solution sol;
	//string num ("135");
	cout << sol.atoi("135") << endl;
	return 0;
}