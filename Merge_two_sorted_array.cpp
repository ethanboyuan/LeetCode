#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> merge(vector<int> arr1, vector<int> arr2){
		vector<int>:: const_iterator i1 = arr1.begin();
		vector<int>:: const_iterator i2 = arr2.begin();
		vector<int> res;
		while(i1 != arr1.end() && i2 != arr2.end()){
			int temp;
			if((*i1 < *i2)){
				temp = *i1;
				++i1;
			}
			else if(*i1 > *i2){
				temp = *i2;
				++i2;
			}

			else{
				temp = *i2;
				++i2; ++i1;
			}

			res.push_back(temp);
			// if(res.empty())
			// 	res.push_back(temp);
			// else{
			// 	//need to handle the duplicate input case
			// 	if(res.back() == temp){
			// 		continue;
			// 	}
			// 	else{
			// 		res.push_back(temp);
			// 	}
			// }

		}

		//cout << "here" << endl;
		if(i1 == arr1.end()){
			while(i2 != arr2.end()){
				res.push_back(*i2);
				++i2;
			}
		}
		else{
			while(i1 != arr1.end()){
				res.push_back(*i1);
				++i1;
			}
		}
		//res.erase(unique(res.begin(),res.end()),res.end());
		return res;
	}

	void printvector(vector<int> &num){

	    vector<int>::const_iterator i;
	    
	    for(i=num.begin(); i!=num.end(); ++i){
	        cout<<(*i);
	        cout<<" ";
	    }

	    cout<<endl;    
	}



};

int main(int argc, char* argv[]){
	Solution sol;
	vector<int> a1 {1,2,3,4,5,6};
	vector<int> a2 {1,2,3,4};
	vector<int> mergeed = sol.merge(a2,a1);
	sol.printvector(mergeed);

	return 0;
}