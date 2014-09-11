#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x),left(NULL), right(NULL) {}
};

struct TreeLinkNode{
	int val;
	TreeLinkNode *left;
	TreeLinkNode *right;
	TreeLinkNode *next;
	TreeLinkNode(int x) : val(x),left(NULL), right(NULL), next(NULL) {}
};

int ListLength(ListNode *root){
	int len = 0;
	while(root != NULL){
		root = root -> next;
		len++;
	}
	return len;
}

int reverse(int x) {
    bool neg=false;
    if (x < 0) neg = true, x = -x;
    unsigned int ret = 0;
    while (x / 10){
        ret = ret*10+ x%10;
        x = x / 10;
    }
    ret =ret*10+x;
    if (ret>0x7fffffff) return 0; //overflow check.
    if (neg) return -(int)ret;
    return (int)ret;
}


bool searchRotatedDub(int A[], int n, int target) {
	int left = 0, right = n - 1;
	while(left <= right){
		int mid = left + (right - left) / 2;
		if(A[mid] == target) {return 1;}
		if(A[left] < A[mid]) {
			if(target < A[mid] && target >= A[left]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		else if(A[left] > A[mid]){
			if(target > A[mid] && target <= A[right]){
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}
		else{
			left++;
		}

	}
	return 0;
 	       
}

bool checkqueenvalid(vector<int> cols, int rowin, int colin){
	// cout << " checking valid " << endl;
	// cout << rowin << endl;
	// cout << colin << endl;
	if(cols.size() == 0) {return true;}
	for(int row = 0; row < rowin; row++){
	//	cout << "entering loop " << endl;
		int col1 = cols[row];
		if(colin == col1) {return false;}

		int coldistance = abs(col1 - colin);
		int rowdistance = rowin - row;
		if(coldistance == rowdistance) {return false;}
	}
	return true;
}

void placeQueens(int row, vector<int> &cols, vector<vector<int>> &resmat, int grid_size){
	// cout << "row is: " << row << endl;

	if(row == grid_size) {
	//	cout << "inserting placement " << endl;
		resmat.push_back(cols);
	}
	else{
		for(int col = 0; col < grid_size; col++){
			 // printvector(cols);
			if(checkqueenvalid(cols, row, col)) {
				cols[row] = col;
				placeQueens(row + 1, cols, resmat, grid_size);
			}
		}
	}
}	

void mat2chessboard(vector<vector<int>> resmat, vector<vector<string>> &chessboard){
	
	for(int i = 0; i < resmat.size(); i++){
		vector<string> sol;
		for(int j = 0; j < resmat[0].size(); j++){
			string line (resmat[0].size(),'.');
			line[resmat[i][j]] = 'Q';
			// cout << line << endl;
			sol.push_back(line);
		}
		chessboard.push_back(sol);
		sol.clear();
		
	}
}

void printchessboard(vector<vector<string>> chessboard){
	for(int i = 0; i < chessboard.size(); i++){
		for(int j = 0; j < chessboard[0].size();j++){
			cout << chessboard[i][j] << endl;
		}
		cout << endl;
	}
}

vector<vector<string>> solveNQueens(int n) {
//	string chessline (10,'.');


	vector<vector<int>> resmat;
	vector<int> cols (n,0);
//	cout << chessline << endl;

	placeQueens(0, cols, resmat, n);

//	printmatrix(resmat);
//	cout << chessline << endl;

	vector<vector<string>> chessboard;
	mat2chessboard(resmat,chessboard);
	printchessboard(chessboard);
	return chessboard;
}

string countAndSay(int n) {
    string res;
    if(n < 1) {return res;}
    res = "1";
    for(int i = 1; i < n; i++){
    	string curr;
    	int length = res.size();
    	char l = res[0];
    	int count = 1;
    	for(int j = 1; j <= length; j++){
    		if(res[j] == l) {count ++;}
    		else{
    			curr.push_back((char)(((int)'0')+count));
    			curr.push_back(l);
    			l = res[j]; 
    			count = 1; }
    	}
    	res = curr;
    	curr.clear();
    //	cout << length << endl;
    }
    return res;
}


void connect1(TreeLinkNode *root){
	if(!root) {return;}
	TreeLinkNode *lasthead = root;
	TreeLinkNode *currhead = NULL;
	TreeLinkNode *prev = NULL;
	while(lasthead != NULL){
		TreeLinkNode *vqueue = lasthead;
		// currhead = lasthead;
		while(vqueue != NULL){
			if(vqueue -> left) {
				if(!currhead) {
					currhead = vqueue -> left;
					prev = currhead;
				}
				else{
					prev -> next = vqueue -> left;
					prev = prev -> next;
				}
			}

			if(vqueue -> right) {
				if(!currhead){
					currhead = vqueue -> right;
					prev = currhead;
				}
				else{
					prev -> next = vqueue -> right;
					prev = prev -> next;
				}
			}
			vqueue = vqueue -> next;
		}
		lasthead = currhead;
		currhead = NULL;
	}	

}

void connect(TreeLinkNode *root) {
	if(!root) {return;}
	TreeLinkNode *lasthead = root;
	TreeLinkNode *currhead = NULL;
	TreeLinkNode *prev = NULL;
	while(lasthead != NULL){
		TreeLinkNode *vqueue = lasthead;
		// currhead = lasthead;
		while(vqueue != NULL){
			if(vqueue -> left) {
				if(!currhead) {
					currhead = vqueue -> left;
					prev = currhead;
				}
				else{
					prev -> next = vqueue -> left;
					prev = prev -> next;
				}
			}

			if(vqueue -> right) {
				if(!currhead){
					currhead = vqueue -> right;
					prev = currhead;
				}
				else{
					prev -> next = vqueue -> right;
					prev = prev -> next;
				}
			}
			vqueue = vqueue -> next;
		}
		lasthead = currhead;
		currhead = NULL;
	}	
}

ListNode *partition(ListNode *head, int x) {
	if(!head) return head;
	ListNode *small = new ListNode (0);
	ListNode *s = small;
	ListNode *great = new ListNode (0);
	ListNode *g = great;
	ListNode *h = head;
	while(h != NULL){
		//cout << "partitioning one integer" << endl;
		if(h -> val < x) {
			s -> next = h; 
			s = s -> next;
		}
		else {
			g -> next = h;
			g = g -> next;
		}
		h = h -> next;
	}
	g -> next = NULL;
	s -> next = great -> next;
	return small -> next;
	// return small;
}

vector<vector<int>> generateMatrix(int n) {
	vector<vector<int>> matr (n, vector<int> (n));
	int count = 1;
	int row = 0;
	int col = 0;

	for(int cycle = 0; cycle < n; cycle ++){

		for(col = cycle; col < n - cycle; col ++){
			matr[cycle][col] = count++; 
		}
		for(row = cycle+1; row < n - cycle; row ++){
			matr[row][n - cycle -1] = count++;
		}
		for(col = n - cycle - 2; col >= cycle; col--){
			matr[n - cycle - 1][col] = count++;
		}
		for(row = n - cycle - 2; row > cycle; row--){
			matr[row][cycle] = count++;
		}


	}
	return matr;
}

int minimumTotal(vector<vector<int> > &triangle) {
	int level = triangle.size();
	if(level == 0) {return 0;}
	if(level == 1) {return triangle[0][0];}
	for(int i = level-2; i >= 0; i--){
		int length = triangle[i].size();
		for(int j = 0; j < length; j++){
			triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
		}
	}	
	return triangle[0][0];    
}


int minDistance(string word1, string word2) {
    int length1 = word1.size();
    int length2 = word2.size();
    if(length1 == 0 && length2 == 0) {return 0;}
    else if(length1 == 0){ return length2;}
    else if(length2 == 0){ return length1;}
    
    vector<vector<int>> dist (length1+1, vector<int> (length2+1));

    for(int i = 0; i <= length1; i++){dist[i][0] = i;}
    for(int i = 0; i <= length2; i++){dist[0][i] = i;}

    for(int i = 1; i <= length1; i++){
    	for(int j = 1; j <= length2; j++){
    		int insert1 = dist[i][j-1] + 1;
    		int insert2 = dist[i-1][j] + 1;
    		int replace = word1[i-1] == word2[j-1] ? dist[i-1][j-1] : (dist[i-1][j-1] + 1);
    		//if(word1[i] == word2[j]) {

    		//}
    		//int replace = dist[i-1][j-1] + (word1[i] == word2[j]);
    		dist[i][j] = min(insert1, min(insert2,replace));	
    	}
    }

    return dist[length1][length2];

}


int threeSumClosest(vector<int> &num, int target) {
	sort(num.begin(), num.end());
	int n = num.size();
	if(n < 3) {return 0;}
	int closest = target;
	int sum = num[0] + num[1] + num[2];
	for(int i = 0; i <  n - 2; i++){
		int a = num[i];
		int k = i + 1;
		int l = n - 1;
		while(k < l){
			int b = num[k];
			int c = num[l];
			if(abs(a + b + c  - target) <= abs(closest)) {closest = ( a + b + c ) - target; sum = a + b + c;}
			
			if(a + b + c == target) {return target;}
			else if(a + b + c > target) {l--;}
			else {k++;}
			//cout << "a = " << a << "b = " << b << "c = " << c  << " closest = " << closest << endl;
		}
	}
	return sum;
}

bool canJump(int A[], int n) {
	int canReach = 0;
	for(int i = 0; i <= canReach && i < n; i++){
		if(A[i] + i > canReach) {canReach = A[i] + i;}
		if(canReach >= n - 1) {return 1;}
	} 
	return (canReach >= n - 1);

}


TreeNode* sortedListToBSThelper(ListNode *& list, int start, int end) {
  if (start > end) return NULL;
  // same as (start+end)/2, avoids overflow
  int mid = start + (end - start) / 2;
  TreeNode *leftChild = sortedListToBSThelper(list, start, mid-1);
  TreeNode *parent = new TreeNode(list->val);
  //cout << "Current node being added: " << list -> val << endl;
  parent->left = leftChild;
  list = list->next;
  parent->right = sortedListToBSThelper(list, mid+1, end);
  return parent;
}

TreeNode *sortedListToBST(ListNode *head) {
	return sortedListToBSThelper(head, 0, ListLength(head) - 1);
}


TreeNode *ipostordertoTree(vector<int> &inorder, vector<int> &postorder, int inend, int instart, int postend, int poststart){
	if(instart + 1 > inend || poststart + 1 > postend) {return NULL;}



	//cout << "building node " << postorder[postend - 1] << endl;

	// if(instart == inend) {
	// 	TreeNode * root = new TreeNode(postorder[postend]);
	// 	//cout << "instart is " << instart << " inend is " << inend << endl;
	// 	return root; 
	// }

	TreeNode *root = new TreeNode(postorder[postend - 1]);
	
	int index = instart; 
	while(inorder[index] != postorder[postend - 1]) {
		index++;
	}
//	cout << "instart is " << instart << " index is " << index << " inend is " << inend << endl;
	root -> left = ipostordertoTree(inorder,postorder, index, instart, poststart + index - instart, poststart);
	root -> right = ipostordertoTree(inorder, postorder, inend , index + 1, postend - 1, poststart + index  - instart);

	return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
	int length = postorder.size();
	//TreeNode *root = new TreeNode(postorder[length -1]);
	return ipostordertoTree(inorder,postorder,length, 0, length , 0);    
}

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    if(matrix.size() == 0) {return 0;}
    if(target < matrix[0][0]) {return 0;}
    int row = 0;
    
    for (int i = 0; i< matrix.size(); i++){
        if(matrix[i][0] == target) {return 1;}
        if(target > matrix[i][0]) {row = i;}
    }

    if (row == matrix.size()) {return 0;}
    for (int j = 0; j < matrix[row].size(); j++){
        if(target == matrix[row][j]) {return 1;}
    }
    return 0;
}


ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if(!l1) {return l2;}
    else if(!l2) {return l1;}
    else if(!l1 && !l2) {return NULL;}  //test edge cases
    ListNode *merge = new ListNode(-1);
	ListNode *curr; 
	curr = merge; //merge to track the nitial pointer
	
    while(l1 != NULL && l2 != NULL){
        if(l1-> val < l2-> val){
            curr -> next =  l1; 
            l1 = l1 -> next;
        }
        else {
            curr -> next = l2;
            l2 = l2 -> next;
        }
	    curr = curr -> next;
    }//repeat to add nodes until one list is done
    if(l1 != NULL) {
        curr -> next =  l1; 
    }
    else{
        curr -> next =  l2; 
    }
    return merge->next;
}



string intToRoman(int num) {
/*
I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;*/
	string roman;
    string symbol[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
    int value[]=    {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
	int i;
	for(i = 0; i < 13; i++){
		while(num >= value[i]){
			num -= value[i];
			roman += symbol[i];
		}
	}
	return roman;
}

int c2i(char c){
/*	switch (c) {
  	case 'M': return 1000;
  	case 'D': return 500;
  	case 'C': return 100;
  	case 'L': return 50;
  	case 'X': return 10;
  	case 'V': return 5;
  	case 'I': return 1;
    default: return 0;
    	
  }
  return 0;*/
    char symbol[]="MDCLXVI";    
    int value[]=    {1000,500,100, 50, 10, 5,  1}; 
    for(int i = 0; i < 7; i++){
    	if (c == symbol[i]) {return value[i];}

    }
    return 0;

}

int romanToInt(string s) {
	if(s.size() == 0) {return 0;}
	int i; 
	int result = 0;

    for(i = 0; i < s.size(); i++){
    	if(i == 0) {result += c2i(s[i]);}
    	else if(c2i(s[i]) > c2i(s[i-1])) {result = result - 2* c2i(s[i-1]) + c2i(s[i]); }
    	else {result += c2i(s[i]);}

    }

    return result;
}
	

int maxDepth(TreeNode *root){
	if(!root) return 0;
	int leftDepth = maxDepth(root -> left);
	int rightDepth = maxDepth(root -> right);
	return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(TreeNode *root) {
    if(!root) {return 1;}
    bool left_balance = isBalanced(root-> left);
    bool right_balance = isBalanced(root -> right);
      
    if(left_balance && right_balance && abs(maxDepth(root -> left) - maxDepth(root -> right))<=1) {return 1;}
    else {return 0;}
}

TreeNode *sortedArrayToBST(vector<int> &num) {
	if(num.size() == 0) {return NULL;}	
    TreeNode *BBST = new TreeNode(num[num.size()/2]);
    vector<int> numleft;//left half of the input string
	numleft.assign(num.begin(),num.begin()+num.size()/2);
	vector<int> numright;//right half of the input string
	numright.assign(num.begin()+num.size()/2+1,num.end());
    TreeNode *BBST_left = sortedArrayToBST(numleft);
	TreeNode *BBST_right = sortedArrayToBST(numright);
	BBST->left = BBST_left;
	BBST->right = BBST_right;
	return BBST;

}

vector<int> grayCode(int n) {
	vector<int> code; 
	if(n == 0) {code.push_back(0); return code;}
	if(n == 1) {code.push_back(0);code.push_back(1);return code;}
	vector<int> codeprev = grayCode(n-1);
	code = codeprev;
	int i=0;
	vector<int>::reverse_iterator rit = codeprev.rbegin();
    for (rit = codeprev.rbegin(); rit!= codeprev.rend(); ++rit)
		{	int temp=1;
			for(i = 0;i<n-1;i++){temp*=2;}
			code.push_back(*rit+temp);
	}
	return code;
        
}

void pathTravel(TreeNode *root, int start, int sum, vector<vector<int>> &res, vector<int> &arry){
	arry.push_back(root -> val); start += root -> val;
	if(start == sum && root -> left == NULL && root -> right == NULL){
		res.push_back(arry);
	}
	if(root -> left != NULL){
		pathTravel(root -> left, start, sum, res, arry);
		arry.pop_back();
	}
	if(root -> right != NULL){
		pathTravel(root -> right, start, sum, res, arry);
		arry.pop_back();
	}
}

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> v;
	if(!root) {return v;}
	v = postorderTraversal (root -> left);

	vector<int> r = postorderTraversal (root -> right);
	v.insert(v.end(),r.begin(),r.end());
	v.push_back(root -> val); //cout << root-> val << endl;
    return v;      
}

void rotate(vector<vector<int> > &matrix) {

	
	int msize = matrix.size();
	if(msize == 1) return;
	vector<vector<int>> m2(msize,vector<int>(msize));

	int j,k;
	for (j = 0;j < msize;j++){
		for(k = 0; k < msize; k++){
	//		cout<<matrix[j][k];
			m2[k][msize-j-1] = matrix[j][k];
		}
	//	cout<<endl;
	}
	matrix = m2;
	return;

}

int climbStairs(int n) {
	int *sarray;
	sarray = (int*) malloc((n+1)* sizeof(int));
	sarray[0] = 0; sarray[1] = 1; sarray[2] = 2;
	if(n <= 2) return sarray[n];
	int i;
	for (i = 3; i <= n ; i++){
		sarray[i] = sarray[i-1] + sarray [i-2];
	}
	int vars = sarray[n];
	free(sarray);
	return vars;
	

}



vector<int> preorderTraversal(TreeNode *root) {
	vector<int> v;

	if(!root) {return v;}
	v.push_back(root -> val); //cout << root-> val << endl;
	vector<int> l = preorderTraversal (root -> left);
	v.insert(v.end(),l.begin(),l.end());
	vector<int> r = preorderTraversal (root -> right);
	v.insert(v.end(),r.begin(),r.end());

    return v; 
}

vector<vector<int> > generate(int numRows) {
	vector<vector<int>> parsTri;
	if(numRows == 0) {return parsTri;}
	vector<int> ot;ot.push_back(1);parsTri.push_back(ot);
	if(numRows == 1) {return parsTri;}
	ot.push_back(1);
	parsTri.push_back(ot);
	if(numRows == 2) {return parsTri;}
	for(int i = 2;i < numRows; i++){
		vector<int> line(i+1,1);
		for(int j = 1; j < i; j++){
			line[j] = parsTri[i-1][j-1]+ parsTri[i-1][j];
		}
		parsTri.push_back(line);	
		line.clear();
			
	}
	
	return parsTri;

}

void sortColors(int A[], int n) {
	if(n<=1) {return;}
	/*int small,temp,count;
	for(int i = 0; i < n-1; i++){
		small = A[i];count = i;
		for(int j = i+1; j < n; j++){
			if(small > A[j]) {
				small = A[j];
				count = j;
			}
		}
		temp = A[i];
		A[i] = A[count];
		A[count] = temp;
	}*/  // O(n^2) algrithms
	int red = 0; 
	int blue = n-1;

	int i = 0;
	while (i < blue+1 ){
		if(A[i] == 0) {swap(A[i],A[red]);red++;i++;continue;}
		if (A[i] == 2) {swap(A[i],A[blue]); blue--;continue;}
		//else if (i < red){i ++;}
		i ++;
	}
		
	

}

bool isSym(TreeNode *l, TreeNode *r){
	if(l == NULL) {return r == NULL;}
	if(r == NULL) {return l == NULL;}
	if(l -> val != r -> val) {return false;}
	if (!isSym(l ->left, r -> right)) {return false;} 
	if (!isSym(l -> right, r -> left)) {return false;}
	return true;
}

bool isSymmetric(TreeNode *root) {
	if(!root) {return true;}
	else {return isSym(root -> left, root ->right);}
 }



vector<int> plusOne(vector<int> &digits) {
    int numlength = digits.size();
	int carry = 0;
		digits[numlength - 1] = digits[numlength - 1] + 1;
	for(int i = numlength-1; i >= 0; i--){
		digits[i] += carry;
		if(digits[i] >= 10){digits[i] %= 10;carry = 1;} 
		else{carry = 0;}
		if(i == 0 && carry == 1) {vector<int>::iterator it; it = digits.begin();digits.insert(it,1);}
	}        
	return digits;
}

void CombinationPar(vector<string>& result, string& sample, int deep, int n, int leftNum, int rightNum){  
	if(deep == 2*n) {
		result.push_back(sample);
		return;
	}
	if(leftNum < n) {
		sample.push_back('(');
		CombinationPar(result,sample,deep+1,n,leftNum+1,rightNum);
		sample.resize(sample.size()-1);
	}
	if(rightNum < leftNum){
		sample.push_back(')');
		CombinationPar(result,sample,deep+1,n,leftNum,rightNum+1);
		sample.resize(sample.size()-1);
	}

}  

bool isValid(string s) {
	int length = s.size();
	stack<char> pstack;
	if(length % 2) {return 0;}
	for(int i = 0; i < length; i++){
		if(pstack.empty()){
			if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
				return 0;
			}
			else {
				pstack.push(s[i]);
			}
		}
		else{
			char c1 = pstack.top();
			if(c1 == '(' && s[i] == ')') {pstack.pop();}
			else if(c1 == '{' && s[i] == '}') {pstack.pop();}
			else if(c1 == '[' && s[i] == ']') {pstack.pop();}
			else {pstack.push(s[i]);}
		}
	}
	
	
	if(pstack.empty()) {return 1;}
	else{return 0;}
}

	
bool isValidSudoku(vector<vector<char>> &board) {

	int row = board.size();
	int col = board[0].size();
	unordered_set<char> shudu;


	// Check column & rows first

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(board[i][j] != '.') {
				if(shudu.find(board[i][j]) != shudu.end()){
					return 0;
				}
				else{
					shudu.insert(board[i][j]);
				}
			}
		}
		shudu.clear();
	}

	for(int j = 0; j < col; j++){
		for(int i = 0; i < row; i++){
			if(board[i][j] != '.') {
				if(shudu.find(board[i][j]) != shudu.end()){
					return 0;
				}
				else{
					shudu.insert(board[i][j]);
				}
			}
		}
		shudu.clear();
	}
 	   
	for(int i = 0; i < row; i+= 3){
		for(int j = 0; j < col; j+= 3){
			for(int k = i; k < i + 3; k ++){
				for(int l = j; l < j + 3; l++){
					if(board[k][l] != '.') {
						if(shudu.find(board[k][l]) != shudu.end()){
							return 0;
						}
						else{
							shudu.insert(board[k][l]);
						}
					}
				}
			}
			shudu.clear();

		}
	}


    return 1;
}


int longestConsecutive(vector<int> &num) {

	unordered_set<int>::const_iterator it;
	unordered_set<int> set;
	for(int i = 0; i < num.size(); i++){
		if(set.find(num[i]) == set.end()){
			set.insert(num[i]);
		}
	}
	int maxc = 0;
	for(int i = 0;i < num.size();i++){
		int c = 1;
		if(set.find(num[i]) != set.end()){
			int cur = num[i] + 1;
			while(set.find(cur) != set.end()){
				set.erase(cur);
				c++;
				cur++;
			}
			cur = num[i] - 1;
			while(set.find(cur) != set.end()){
				set.erase(cur);
				c++;
				cur--;
			}
			if(maxc < c) 
				{maxc = c;}
		}
		

	}
	return maxc;
}


int lengthOfLastWord(const char *s) {
	//cout << strlen(hello) << endl;
	
	int count = 0;
	int length = strlen(s) - 1;
	while(s[length] == ' ' && length >= 0){
		length--;
	}
	while(s[length] != ' ' && length >=0){
		length--;
		count++;
	}

	return count;
}
int trap(int A[], int n) {
	if(n == 0) {return 0;}
	int l = 0;
	int r = n - 1; // scan from two side;
	int curr = 0; // current water level is 0;
	int all = 0; // tank is empty
	int block = 0; // blocks is empty

	while(l < r){
		if(min(A[l],A[r]) > curr){
			all += (min(A[l],A[r]) - curr) * (r - l + 1);
			curr = min(A[l],A[r]);
		}
		if(A[l] < A[r]){
			block += A[l++];
		}
		else{
			block += A[r--];
		}

	} 

	return all - block;	

        
}

int searchrotated(int A[], int n, int target) {

	int mid,left = 0,right = n - 1;
	while(left <= right){
		mid = (left + right) / 2;
		if(A[mid] == target) {return mid;}
		if(A[left] <= A[mid]){	
			if(target < A[mid] && target > A[left]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		else{
			if(target < A[mid] || target > A[left]){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}	
		}
	}
	
	//return intsearchrotated(A, target, 0, n - 1);
	return -1;
}

bool isPalindrome(int x) {
	if(x < 0) return 0;
	int rev = reverse(x);

	return rev == x;
        
}

int minDepth(TreeNode *root) {
	if(root == NULL) {return 0;}
	if(root -> left == NULL && root -> right == NULL) {return 1;}
	int leftDepth = INT_MAX;
	int rightDepth = INT_MAX;
	if(root -> left) {
		//cout<< "Going left leaf" << endl;
		leftDepth = min(minDepth(root -> left) + 1, leftDepth);}
	if(root -> right) {
		//cout<< "Going right leaf" << endl;
		rightDepth = min(minDepth(root -> right) + 1, rightDepth);}
	//cout << min(leftDepth,rightDepth) << endl; 
	return min(leftDepth,rightDepth);

	    
}


vector<vector<int>> pathSum(TreeNode *root, int sum) {
	vector<vector<int>> res;
	if(!root) return res;
	vector<int> arry;
	pathTravel(root, 0, sum, res, arry);
	return res;
}

int numTravel(TreeNode *root, int res){
	if(root -> left == NULL && root -> right == NULL) {return res * 10 + root -> val;}
	res = res * 10 + root -> val;	
	int val = 0;
	if (root -> left) val += numTravel(root -> left, res);
	if (root -> right) val += numTravel(root -> right, res);
	return val;
}

int sumNumbers(TreeNode *root) {
	int val = numTravel(root, 0);
	return val;
}

void perm(vector<int> num, int k, int n, vector<vector<int>> &res){
	if(k == n){
		res.push_back(num);
		//printvector(num);
	}
	else{
		for(int i=k; i <= n; i++){
			swap(num[i],num[k]);

			perm(num,k+1,n,res);
			swap(num[i],num[k]);
		}
	}
}

vector<vector<int> > permute(vector<int> &num) {
	vector<vector<int>> res;
	perm(num,0,(num.size()-1),res);
	return res;	    
}

vector<int> getRow(int rowIndex){
	vector<int> res;
	if(rowIndex >= 0) {
		res.push_back(1);
	} 

	//(n,j) = (n, j-1) * (n-j+1) / j
	for(int i = 1;i <= rowIndex; i++){
		res.push_back((double) res.back() * (double)(rowIndex - i +1) /(double) i);
	}
	return res;

}

void combhelper(int n, int k, vector<vector<int>> &res,vector<int> &arry, int start){
	if(arry.size() == k){
		res.push_back(arry);
		return;
	}
	else{
		for(int i = start; i <= n; i++){
			arry.push_back(i);
			combhelper(n,k,res,arry,i+1);
			arry.pop_back();
		}
	}
}


vector<vector<int> > combine(int n, int k) {
	vector<vector<int>> res;
	if(n < k) return res;
	vector<int> arry;
	combhelper(n,k,res, arry,1);
	return res;	    
}


 void setZeroes(vector<vector<int> > &matrix) {
 	/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
	Did you use extra space?
	A straight forward solution using O(mn) space is probably a bad idea.
	A simple improvement uses O(m + n) space, but still not the best solution.
	Could you devise a constant space solution?       */
	int row = matrix.size();
	int col = matrix[0].size();

	int markrow = 0;
	int markcol = 0;

	for(int i = 0; i < row; i++){
		if(matrix[i][0] == 0) {markrow = 1;
		//cout << "zero detected" << endl;
		}
	}

	for(int i = 0; i < col; i++){
		if(matrix[0][i] == 0) {markcol = 1;
			//cout << "zero detected" << endl;
		}
	}

	for(int i = 1; i < row; i++){
		for(int j = 1; j < col; j++){
			if(matrix[i][j] == 0) {
				//cout << "zero detected not first" << endl;
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	//printmatrix(matrix);
	//cout << endl;
	for(int i = 1; i < row; i++){
		//scan first row and set the corresponding col to 0
		if(matrix[i][0] == 0) {
			for(int j = 0; j < col; j++){
				matrix[i][j] = 0;
			}
		}
	}

	for(int i = 1; i < col; i++){
		//scan first col and set the corresponding row to 0
		if(matrix[0][i] == 0){
			//cout << " trying to set row to 0" << endl;
			for(int j = 0; j < row; j++){
				matrix[j][i] = 0;
			//	cout << j ;
			}
			//cout << endl;
		}
	}
//	cout << markrow << endl;
//	cout << markcol << endl;
	if(markrow){
		//set the first row to 0 if marked
		for(int i = 0; i < row; i++){
			matrix[i][0] = 0;
		}
	}

	if(markcol){
		//set the first col to 0 if marked
		for(int i = 0; i < col; i++){
			matrix[0][i] = 0;
		}
	}

 }

bool hasPathSum(TreeNode *root, int sum) {
	//Given a binary tree and a sum, determine if the tree has a root-to-leaf path 
	//such that adding up all the values along the path equals the given sum.
	//if(root == NULL && sum == 0) {return 1;}
	if(root == NULL) {return 0;}
	if(root -> val == sum && root -> left == NULL && root -> right == NULL) {return 1;}
	bool leftp = hasPathSum(root -> left, sum - root -> val);
	bool rightp = hasPathSum(root -> right, sum - root -> val);
	if(leftp || rightp) {return 1;}
	else {return 0;}
	return 0;
}



vector<vector<int> > levelOrderBottom(TreeNode *root) {
	vector<vector<int >> res;
	if(!root) {return res;}
	vector<int> currlvl;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode *curr;
	while(!q.empty()){
		int currsize = q.size();
		for(int i = 0; i < currsize; i++){
			curr = q.front();q.pop();
			currlvl.push_back(curr -> val);
			if (curr -> left != NULL) {q.push(curr -> left);}
			if (curr -> right != NULL) {q.push(curr -> right);}

		}
		res.push_back(currlvl);
		currlvl.clear();
	}

	vector<vector<int >> resrev;
	for(int i = res.size() -1; i >= 0; i--){
		resrev.push_back(res[i]);
	}
	return resrev;   
}

ListNode *removeNthFromEnd(ListNode *head, int n) {
    if(!head) {return NULL;}
    ListNode *dummyhead = new ListNode(0);
    dummyhead -> next = head;
    ListNode *fast;fast = dummyhead;
	ListNode *slow;slow = dummyhead;

	while(n){
		fast = fast -> next;
		n--;
	}


    while(fast != NULL && fast -> next != NULL){
    	fast = fast -> next;
    	slow = slow -> next;
    }

    slow -> next = slow -> next -> next;
	

    return dummyhead-> next;
}

int maxArea(vector<int> &height) {
//
//	Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
//  n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
//	Find two lines, which together with x-axis forms a container, such that the container contains the most water.
//
	if(height.size() == 0) {return 0;}
	int low = 0; int high = height.size() - 1;
	//int curr = height[0];
	//int area = 0;
	int res = 0;

	while (low < high){
		res = max( res, (high - low) * min(height[low],height[high]));
		if(height[low] < height[high]){
			low++;
		}
		else{
			high--;
		}
	}
	
		
	  
	return res;
}



bool hasCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;

    if(head == NULL)
        return 0;

    if(head->next == NULL)
        return 0;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            return 1;
    }

    return 0;
}

ListNode *detectCycle(ListNode *head) {
	ListNode *fast = head;
	ListNode *slow = head;

	if(!head) {return NULL;}

    while(fast != NULL){
	    slow = slow->next;
    	fast = fast->next;
    	if(fast) {fast = fast -> next;}
    	else {return NULL;}
    	if(!fast) {return NULL;}
    	if(slow == fast) {break;}
    }

   
    slow = head;
    while(slow != fast){
    	slow = slow -> next;
    	fast = fast -> next;
    }

    return slow;
     
}



bool isSameTree(TreeNode *p, TreeNode *q){
	if(!p && !q) {return 1;} 
	else if (!p && q) {return 0;}
	else if (p && !q) {return 0;}
	if (p -> val == q -> val){
	bool leftSame = isSameTree(p -> left, q -> left);
	bool rightSame = isSameTree(p -> right, q -> right);
	return leftSame && rightSame;}
	else {return 0;}
}
/*
int reverse(int x) {
	int rx = 0;
	int tempx = x > 0 ? x : (-x) ;
	while(tempx>0){
		rx = rx * 10 + tempx%10;
		tempx = tempx/10;
		}
	return x > 0 ? rx:(-rx);

}*/

int numTrees(int n) {
	if (n == 1) {return 1;}
	if (n == 0) {return 1;}
	int i;
	int unique = 0;
	for(i = 0; i< n; i++)
	{	
		 unique += numTrees(i) * numTrees(n-i-1);
	}
	return unique;
}

vector<int> inorderTraversal(TreeNode *root) {
	vector<int> v;
	if(!root) {
	//	v.push_back(-1);
		return v;}
	v = inorderTraversal (root -> left);
	v.push_back(root -> val); //cout << root-> val << endl;
	vector<int> r = inorderTraversal (root -> right);
	v.insert(v.end(),r.begin(),r.end());
    return v;    
}


void printList(ListNode *root){
	if(!root) {
		cout << "List is empty!" << endl;
		return;
	}
	while(root != NULL){
		cout << root -> val;
		cout << " -> ";
		root = root -> next;
	}
	cout << "NULL";
	cout << endl;
	return ;
}

vector<string> generateParenthesis(int n) {  
   // Start typing your C/C++ solution below  
   // DO NOT write int main() function  
   vector<string> result;  
   string sample;  
   if(n!= 0)  
       CombinationPar(result, sample, 0, n, 0, 0);  
   return result;  
}  

ListNode *ListPlusOne(ListNode *root){
	if(!root) {return NULL;}
//	ListNode *prev = root;
	ListNode *curr = root;
//	if(root -> next != NULL) {curr = prev -> next;}
	
	ListNode *carry_p = root;
	
	while(curr != NULL ){
		if(curr -> val != 9) {
			carry_p = curr;
		}

		curr = curr -> next;
	}



	if(carry_p == root && root -> val  == 9) {
		ListNode *newRoot = new ListNode(1);

		
		newRoot -> next = root;
		while(root != NULL)
			{root -> val = 0; root = root -> next;}
		return newRoot;
	} 
	else if(carry_p == curr) {curr -> val = curr -> val + 1; return root;}
	else {
		carry_p -> val = carry_p -> val + 1;
		carry_p = carry_p -> next;
		while( carry_p != NULL){
			carry_p -> val = 0;
			carry_p = carry_p -> next;
		}
	}
	


	 
	return root;


}

int uniquePaths(int m, int n) {
/*	if (m == 0 || n == 0) {return 0;}
	if (m == 1) return 1;
	if (n == 1) return 1;
	int upath = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	return upath;  */
	vector<vector<int> > table(m, vector<int>(n, 1)); 
	for(int i = 1; i < m; i++){
		for(int j = 1; j < n; j++){
			table[i][j] = table[i-1][j] + table[i][j-1];
		}
	}
	return table[m-1][n-1];

}

int maxProfit(vector<int> &prices) {
	if(prices.size() == 0) {return 0;}
	int maxpro = 0;
	int currmin = prices[0];
	for(int i = 1; i < prices.size(); i++){
		if(prices[i] - currmin > maxpro) {maxpro = prices[i] - currmin;}
		if(currmin > prices[i]) {currmin = prices[i];}

	}
	return maxpro;

}

int minPathSum(vector<vector<int> > &grid) {
    if(grid.size() == 0) {return 0;}
    int row = grid.size();
    int col = grid[0].size();
    int sum[row][col];
    sum[0][0] = grid[0][0];
    for(int i = 1; i < row; i++){
    	sum[i][0] = sum[i-1][0] + grid[i][0];
    }
    for(int i = 1; i < col; i++){
    	sum[0][i] = sum[0][i-1] + grid[0][i];
    }
    for(int i = 1; i< row; i++){
    	for(int j = 1; j< col; j++){
    		sum[i][j] = min(sum[i-1][j],sum[i][j-1]) + grid[i][j];
    	}
    }
    return sum[row-1][col-1];
    

}

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

int factorial(int n){
	int res = 1;
	for(int i = 2; i <= n; i++){
		res *= i;}
	return res;
}



vector<vector<int>> levelOrder(TreeNode *root) {
	vector<vector<int >> res;
	if(!root) {return res;}
	vector<int> currlvl;
	queue<TreeNode*> q;
	q.push(root);
	TreeNode *curr;
	while(!q.empty()){
		int currsize = q.size();
		for(int i = 0; i < currsize; i++){
			curr = q.front();q.pop();
			currlvl.push_back(curr -> val);
			if (curr -> left != NULL) {q.push(curr -> left);}
			if (curr -> right != NULL) {q.push(curr -> right);}

		}
		res.push_back(currlvl);
		currlvl.clear();
	}
	return res;
        
}





void flatten(TreeNode *root) {
    // Base Case
    if (root == NULL) {return;}

    while ( root ) {
	    if ( root->left ) {
	        TreeNode *ptr = root->left;
	        while ( ptr->right ) ptr = ptr->right;
	        ptr->right = root->right;
	        root->right = root->left;
	        root->left = NULL;
	    }
    	root = root->right;
	}
	
}
void subsetshelper(vector<vector<int>> &res, vector<int> s, vector<int> &arry, int large){
	// if(large == s.size()) {return;}
	for(int i = large; i < s.size(); i++){
	
		arry.push_back(s[i]);
		res.push_back(arry);
		// cout << " arry inserted " << endl;
		subsetshelper(res, s, arry, i + 1);
		arry.pop_back();
	}
}


vector<vector<int>> subsets(vector<int> &S) {
	vector<vector<int>> res;
	if(S.size() == 0) {return res;}
	sort(S.begin(),S.end());
	vector<int> arry;
	res.push_back(arry);
	subsetshelper(res, S, arry, 0);
	return res;
}

void subsetsduphelper(vector<vector<int>> &res, vector<int> s, vector<int> &arry, int large){
	// if(large == s.size()) {return;}
	for(int i = large; i < s.size(); i++){
	
		arry.push_back(s[i]);
		res.push_back(arry);
		// cout << " arry inserted " << endl;
		subsetsduphelper(res, s, arry, i + 1);
		arry.pop_back();
		
		while(i < s.size() && s[i] == s[i + 1]){i++;}
	}
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
	vector<vector<int>> res;
	if(S.size() == 0) {return res;}
	sort(S.begin(),S.end());
	vector<int> arry;
	res.push_back(arry);
	subsetsduphelper(res, S, arry, 0);
	return res;
    
}

string longestCommonPrefix(vector<string> &strs) {
	string res;
	if(strs.size() == 0) {return res;}
	string comp = strs[0];
	res = strs[0];
	if(strs.size() > 1){
		for(int i = 1; i < strs.size(); i++){
			//string temp = strs[i];
			int index = 0;

			while(strs[i][index] ==  comp[index] && index < strs[i].size() && comp.size()){
				index++;
			}
			if(index < res.size()) {
				res.clear();
				res.append(strs[i], 0, index);

			}
			//cout << index << endl;
			comp = strs[i];
		}
	}
	return res;
}


vector<int> searchRange(int A[], int n, int target) {
	int l = 0, r = n - 1, mid;
	vector<int> res;

	while(l <= r) {
		mid = (l + r) / 2;
		if(A[mid] == target) {break;}
		else if(A[mid] < target) {l = mid + 1;}
		else {r = mid - 1;}
		
	}
	if(A[mid] != target) {res.push_back(-1);res.push_back(-1); return res;}
	else {
		r = mid; l = mid;
		while(r < n && A[r] == A[r + 1]) {r++;} if (r == n) {r = n - 1;}
		while(l >= 0 && A[l] == A[l - 1]) {l--;} if (l < 0) {l = 0;}
		res.push_back(l);
		res.push_back(r);
		return res;
	}
	return res;


}
