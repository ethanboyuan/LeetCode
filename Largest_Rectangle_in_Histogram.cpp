#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
    	int length = height.size();
    	//vector<int> res;
   		int area = 0;

    	for(int i = 0; i < length; i++){
    		int currArea;
    		while(height[i+1] >= height[i] && (i + 1) < length){
    			i++;
    		}
    		int locallow = height[i];

//    		cout << height[i] << endl;


    		for(int j = i; j >= 0; j--){
    			if(height[j] < locallow) {
    				locallow = height[j];
    			}
    			currArea = (i - j + 1) * locallow;
    			if(currArea > area) {
    			area = currArea;
    		    }
    		}
    		
    	}
		return area;        
    }
    int largestRectangleAreaStack(vector<int> &height){
        int area = 0;
        stack<int> s;
        for(int i = 0; i < height.size(); i++){
            cout << "index is " << i << endl;
            if(s.empty() || height[s.top()] < height[i]) {
                s.push(i);
            }
            else{
                int start = s.top();s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                area = max(area, height[start] * width);
                i--;
            }
        }
        
        while(!s.empty()){
            int start = s.top();s.pop();
            cout << start << endl;
            int width = s.empty() ? height.size() : height.size() - s.top() - 1;
            area = max(area, height[start] * width);
        }
        return area;
    }
};

int main(int argc, char* argv[]){
	vector<int> height = {2,1,5,6,2,3};
	Solution sol;
	cout << sol.largestRectangleArea(height) << endl;
    cout << sol.largestRectangleAreaStack(height) << endl;
	return 0;
}