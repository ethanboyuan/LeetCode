#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
 		vector<vector<int>> result;
 		if(num.size() < 4) return result;
 		sort(num.begin(),num.end());
 		//const int target = 0;
 		auto last = num.end();
 		for (auto ii = num.begin(); ii < prev(last,3); ++ii){
 			for(auto jj = ii+1; jj < prev(last,2); ++jj){
	 			auto ll = next(ii);
	 			auto rr = prev(last);
	 			while(ll < rr){
	 				if(*ll + *rr + *ii + *jj < target){
	 					ll++;
	 				}
	 				else if(*ll + *rr + *ii + *jj> target){
	 					rr--;
	 				}
	 				else{
	 					result.push_back({*ii, *jj, *ll,*rr});
	 					ll++;
	 					rr--;
	 				}
	 			}
			    while (*ii == *(ii+1)) {   // skip duplicate elsments 
	                ++ii;
		        }

	    	}
 		}
 		
 		sort(result.begin(),result.end());
 		result.erase(unique(result.begin(),result.end()),result.end());

 		return result;       
    }

    vector<vector<int> > fourSumHashMap(vector<int> &num, int target) {
 		vector<vector<int>> result;
 		if(num.size() < 4) return result;
 		sort(num.begin(),num.end());
 		//const int target = 0;
 		auto last = num.end();
 		unordered_map <int, vector<pair<int, int>>> cache;

 		for(size_t ii = 0; ii < num.size()-1; ++ii){
 			for(size_t jj = ii+1; jj < num.size(); ++jj){
 				cache[num[ii]+num[jj]].push_back(pair<int,int> (ii,jj));
 			} 
 			while (num[ii] == num[ii+1]){
 				++ii;
 			}

 		}
 		for(size_t ii = 0; ii < num.size(); ++ii){
 			for(size_t jj = ii+1; jj< num.size(); ++jj){
 				const int key = target - num[ii] - num[jj];
 				if(cache.find(key) == cache.end()) 
 					continue;
 				const auto& vec = cache[key];
 				for(size_t kk = 0; kk < vec.size(); ++kk){
 					if (ii <= vec[kk].second) 
 						continue;
 					result.push_back({num[vec[kk].first],num[vec[kk].second],num[ii],num[jj]});

 				}
 			}
 			
 		}
 		sort(result.begin(),result.end());
 		result.erase(unique(result.begin(),result.end()),result.end());

 		return result;
 

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

void printmatrix(vector<vector<int>> &matrix){
	int row = matrix.size();
	for (int i = 0; i < row; i++){
		printvector(matrix[i]);
	}

}

int main(int argc, char* argv[]){
	Solution sol;

	clock_t begin = clock();

//	vector<int> num {-1, 0, 1, 2, -1, -4};
	vector<int> num {0,0,0,0};
//	vector<int> num {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};

	vector<vector<int>> result = sol.fourSumHashMap(num, 0);
	printmatrix(result);

	clock_t end = clock();
  	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	
	cout << elapsed_secs << endl;
	return 0;
}