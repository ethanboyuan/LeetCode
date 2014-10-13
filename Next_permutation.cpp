#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
    //1. From right to left, find the first digit which violates the increasing trend call it pivot
		auto pivot = prev(num.end(),1);
		while(pivot != num.begin() && *(prev(pivot)) >= *(pivot)){
			--pivot;
		} 
		//cout << *pivot << endl;
		if(pivot == num.begin()) {
			//cout << "no such element " << endl;

			reverse(num.begin(),num.end());
			return;
		}

		pivot = prev(pivot);
		//cout << *pivot << endl;
	//2. From right to left, find the frst digit that is greater than the pivot call it change
		auto change = prev(num.end());
		while(change >= pivot && *change <= *pivot){
			--change;
		}

		//cout << *change << endl;

		swap(*pivot, *change);
		reverse(next(pivot),num.end());

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

int main(int argc, char* argv[]){
	Solution sol;
	vector<int> num {6,8,7,4,3,2};
	//reverse(num.begin(),num.end());
	//printvector(num);
	//vector<int> num {2,1};

	sol.nextPermutation(num);
	printvector(num);
	return 0;
}
