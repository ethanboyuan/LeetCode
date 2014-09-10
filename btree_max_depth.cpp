// btree_max_depth.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>
#include "my_leetcode.h"

using namespace std;


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

TreeNode *ipreordertoTree(vector<int> &preorder, vector<int> &inorder, int instart, int inend, int prestart, int preend){
	if(instart + 1 > inend || prestart + 1 > preend) {return NULL;}
	TreeNode *root = new TreeNode(preorder[prestart]);
	cout << "building node " << preorder[prestart] << endl;

	int index = instart; 
	while(inorder[index] != preorder[prestart]) {
		index++;
	}

	root -> left = ipreordertoTree(preorder, inorder, instart, index, prestart + 1, prestart + index - instart + 1);
	root -> right = ipreordertoTree(preorder, inorder, index + 1, inend, prestart + index - instart + 1, preend);



	return root;

}
TreeNode *buildTreeIPre(vector<int> &preorder, vector<int> &inorder) {
	int length = preorder.size();
	return ipreordertoTree(preorder, inorder, 0, length, 0, length);    
}

int main(int argc, char* argv[])
{
	vector<int> postorder = {1,3,5,4,2,8,9,7,6};
	vector<int> preorder = {6,2,1,4,3,5,7,9,8};
	vector<int> inorder = {1,2,3,4,5,6,7,8,9};
	TreeNode *newTree = buildTree(inorder, postorder);
	TreeNode *newTree2 = buildTreeIPre(preorder, inorder);

 //	solveNQueens(4);
	vector<vector<int>> matr = generateMatrix(5);
	printmatrix(matr);
	string cat = "caa";
	string caf = "cab";
	cout << minDistance(cat,caf) << endl;
	string s0 = countAndSay(3);
	cout << s0 << endl;
	string s1 = "abcdef";
	string s2 = "ad";
	string s3 = "ab";
	string s4 = "ac";
	vector<string> prestring; 
	prestring.push_back(s1);prestring.push_back(s2);
	prestring.push_back(s3);prestring.push_back(s4);
	string s5 = longestCommonPrefix(prestring);
	cout << s5 << endl;
	
	
	int rangearry[] = {0,0,2,3,4,4,4,5};
	vector<int> arryrange = searchRange(rangearry, 8, 5);
	printvector(arryrange);
	vector<int> threesumtest = {1,1,1,0};
	int three = threeSumClosest(threesumtest, 100);
	cout << "3 sum resut is: " << three << endl;
	vector<vector<char>> board;
	vector<char> line1 = {'.','.','5','.','.','.','.','.','6'};board.push_back(line1);
	vector<char> line2 = {'.','.','.','.','1','4','.','.','.'};board.push_back(line2);
	vector<char> line3 = {'.','.','.','.','.','.','.','.','.'};board.push_back(line3);
	vector<char> line4 = {'.','.','.','.','.','9','2','.','.'};board.push_back(line4);
	vector<char> line5 = {'5','.','.','.','.','2','.','.','.'};board.push_back(line5);
	vector<char> line6 = {'.','.','.','.','.','.','.','3','.'};board.push_back(line6);
	vector<char> line7 = {'.','.','.','5','4','.','.','.','.'};board.push_back(line7);
	vector<char> line8 = {'3','.','.','.','.','.','.','4','2'};board.push_back(line8);
	vector<char> line9 = {'.','.','.','2','7','.','6','.','.'};board.push_back(line9);


	 // {"..5.....6","....14...",".........",".....92..","5....2...",".......3.","...54....","3.....42.","...27.6.."};
	
	bool vldsudo = 	isValidSudoku(board);
	cout << "Sudo board is valid: " << vldsudo << endl;

	vector<int> sub1 = {2,3,3};
	vector<vector<int>> subres1 = subsets(sub1);

	vector<vector<int>> subres2 = subsetsWithDup(sub1);
	//printvector(sub1);
	//cout << subres1.size() << endl;
	//printmatrix(subres1);

	//	printmatrix(subres2);

	//vector<int> parsrow = getRow(5);

	//printvector(parsrow);
	//cout << "Plindrome" << endl;
	//cout << isPalindrome(-2147447412) << endl;
	TreeNode *Node_A = new TreeNode(1);
	TreeNode *Node_B = new TreeNode(2);
	TreeNode *Node_C = new TreeNode(3);
	TreeNode *Node_D = new TreeNode(3);
	TreeNode *Node_E = new TreeNode(2);
	TreeNode *Node_F = new TreeNode(15);
	TreeNode *Node_G = new TreeNode(17);

//	bool absame = isSameTree(Node_A,Node_B);
	
	Node_A -> left = Node_B;
	Node_A -> right = Node_C;

	
	Node_B -> left = Node_D;
	Node_B -> right = Node_E;
	Node_C -> left = Node_F;
	Node_C -> right = Node_G;

	flatten(Node_A);
	vector<vector<int>> flattenm = levelOrderBottom(Node_A);
	//printmatrix(flattenm);

//	vector<vector<int>> levels = levelOrderBottom(Node_A);
//	printmatrix(levels);
	//vector<vector<int>> comb42 = combine(4,3);
	//printmatrix(comb42);
	cout << minDepth(Node_A) << endl;
	vector<vector<int>> pathsum1 =  pathSum(Node_A, 12);
	printmatrix(pathsum1);

	cout << sumNumbers(Node_A) << endl;

	char hello[] = "i have a dick";
	int count = lengthOfLastWord(hello);



	//count = strlen("abcd");

	cout << count << endl;


	int raintank[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int rain = trap(raintank, 12);

	cout << "Amount of rain :";
	cout << rain << endl;
	//int rotatearry[] = {3,4,5,1,2};
	int rotatearry[] = {1,1,3,1,1,1,1};
	cout << "rotated arry search with dub: " << searchRotatedDub(rotatearry, 7, 3) << endl;
	//cout << isSymmetric(Node_A) << endl;
	
	stack<char> pstack;
	string s = "((([]))";
	cout << "string s is valid: " << isValid(s) << endl;
//	int maxd = maxDepth(Node_A);
//	bool aasame = isSameTree(Node_A,Node_C);
	
//	printf("%d,%d\n",maxd,aasame);	
//	printf("%i \n", reverse(-100));
//	printf("%i \n", numTrees(4));
//	printf("End of program\n");
	ListNode *lNode_1 = new ListNode(1);
	ListNode *lNode_2 = new ListNode(4);
	ListNode *lNode_3 = new ListNode(3);
	ListNode *lNode_4 = new ListNode(2);
	ListNode *lNode_5 = new ListNode(5);
	ListNode *lNode_6 = new ListNode(2);

	lNode_1 -> next = lNode_2;
	lNode_2 -> next = lNode_3;
	lNode_3 -> next = lNode_4;
	lNode_4 -> next = lNode_5;
	lNode_5 -> next = lNode_6;

	printList(lNode_1);
	ListNode *t2 = partition(lNode_1,3);
	printList(t2);
	//vector<int> t2res = preorderTraversal(t2);
	//printvector(t2res);


	TreeNode *t1 = sortedListToBST(lNode_1);
	vector<int> t1res = preorderTraversal(t1);
	printvector(t1res);


	cout << "List length is: " << ListLength(lNode_1) << endl;
	ListNode *lNodeT = detectCycle(lNode_1);
	if(lNodeT == NULL) {cout << " NO cycle detected! " << endl;}
	else {cout << lNodeT -> val << endl;}

	lNodeT = removeNthFromEnd(lNode_1, 1);
	//printList(lNodeT);
	//if(lNodeT) {cout << lNodeT -> val << endl;}

	//input array [-1, 1, 3 ,-1 , 5, 6]
	//vector<int> water = {-1,1,3,-10,5,6};
	vector<int> water = {1, 2};
	//cout << maxArea(water) << endl;


	
	//ListNode *res = ListPlusOne(lNode_1);
	//printList(res);

	//int stockprice[] = {3,2,6,5,0,3};
	//cout << maxProfit(stockprice) << endl;


//	vector<int> a;
//	a.push_back(1);
//	a.push_back(2);
//	a.push_back(3);
	//a.push_back(4);
//	permute(a);



/*	vector<int> a = inorderTraversal(Node_A);
    vector<int>::const_iterator i;
    
    for(i=a.begin(); i!=a.end(); ++i){
        cout<<(*i)<<endl;
    }
	int a[] = {0,0,1,1,2};
	sortColors(a,5);
	for(int i = 0;i < 5; i++){
		cout<<a[i]<<endl;
	}
	
	
	vector<int> a = grayCode(5);

    vector<int>::const_iterator i;
    
    for(i=a.begin(); i!=a.end(); ++i){
        cout<<(*i)<<endl;
    }*/

/*	vector<vector<int>> m1(6,vector<int>(5));
	int j,k;
	for (j = 1;j < 7;j++){
		for(k = 1; k < 6; k++){
			m1[j-1][k-1] = (j*k);
		}
	}
	printmatrix(m1);
	m1[5][4] = 0;*/
	//m1[2][2] = 0;
	//m1[0][2] = 0;


	//m1.clear();
//	vector<vector<int>> m1;
//	m1 = {{0,0,0,5},{4,3,1,4},{0,1,1,4},{1,2,1,3},{0,0,1,1}};

	//printmatrix(m1);
	
//	cout << endl;
//	setZeroes(m1);

//	printmatrix(m1);
/*
	vector<vector<int>> m2(1,vector<int>(1));
	m2[0][0] = 1;

	cout << searchMatrix(m2,2) << endl;

	vector<string> pGen = generateParenthesis(3);
	string rom3999 = intToRoman(5999);
	int rom3 = romanToInt(rom3999);
	cout << rom3999 << endl;
	cout << rom3 << endl;

	cout << uniquePaths(12, 12) << endl;
	
	//cout << c2i('C') << endl;
	int a[] = {3,1,4,5};
	for (j=0;j<4;j++){
		cout << *a << endl;
		
		
	}

	rotate (m1);
	int steps = climbStairs(4);
	cout << steps << endl;*/
	
	return 0;
	
}
