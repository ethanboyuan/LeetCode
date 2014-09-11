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

TreeNode *ipreordertoTree(vector<int> &preorder, vector<int> &inorder, int instart, int inend, int prestart, int preend){
	if(instart + 1 > inend || prestart + 1 > preend) {return NULL;}
	TreeNode *root = new TreeNode(preorder[prestart]);
//	cout << "building node " << preorder[prestart] << endl;

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

void combsumhelper(int k, vector<vector<int>> & res, vector<int> & arry, int start, vector<int> candidates){
	if(k < 0) 
		return;

	else if(k == 0) {
		res.push_back(arry);
		return;
	}
	else{
		for(int i = start; i < candidates.size(); i++){
			if(i>0 && candidates[i]==candidates[i-1])  
            	continue;  
			arry.push_back(candidates[i]);
			//combsumhelper(k - candidates[i],res,arry,i+1,candidates);
			combsumhelper(k - candidates[i],res,arry,i,candidates);
			arry.pop_back();
		}
	}
}

 vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
 	vector<vector<int>> comres;
 	vector<int> arry;
 	sort(candidates.begin(),candidates.end());
 	combsumhelper(target,comres,arry,0,candidates);

 	return comres;      
 }

void combsum2helper(int k, vector<vector<int>> & res, vector<int> & arry, int start, vector<int> candidates){
	if(k < 0) 
		return;

	else if(k == 0) {
		res.push_back(arry);
		return;
	}
	else{
		for(int i = start; i < candidates.size(); i++){
			if(i>0 && candidates[i]==candidates[i-1])  
            	continue;  
			arry.push_back(candidates[i]);
			//combsumhelper(k - candidates[i],res,arry,i+1,candidates);
			combsumhelper(k - candidates[i],res,arry,i,candidates);
			arry.pop_back();
		}
	}
}

 vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
 	vector<vector<int>> comres;
 	vector<int> arry;
 	sort(candidates.begin(),candidates.end());
 	combsum2helper(target,comres,arry,0,candidates);

 	return comres;      
 }
string addBinary(string a, string b) {
	int alen = a.size();
	int blen = b.size();
	int carry = 0;
	string res = "";
	int maxlen = max(alen,blen);
	for(int i = 0; i < maxlen; i++){
		int ac = i < alen ? a[alen - 1 - i] - '0' : 0;
		int bc = i < blen ? b[blen - 1 - i] - '0' : 0;
		int sum = ac + bc + carry;
		carry = sum / 2;
		res = to_string(sum % 2) + res;
	}

	return (carry == 0) ? res : "1" + res ;

}


string addDaShu(string a, string b){
    string res = "";
    int alen = a.size();
    int blen = b.size();
    int carry = 0;
    int maxlen = max(alen, blen);
    for(int i = 0; i < maxlen; i++){
        int ac = i < alen ? a[alen - i - 1] - '0' : 0;
        int bc = i < blen ? b[blen - i - 1] - '0' : 0;
        int sum = ac + bc + carry;
        carry = sum / 10;
        res = to_string(sum % 10) + res;
    }
    return carry == 0 ? res : "1" + res;
    
}


string shortestseq(string chars, string set){
	string res;


	return res;

}



int main(int argc, char* argv[]){

	string badda = "1001";
	string baddb = "101";
	string dashusum = addDaShu(badda,baddb);
	cout << badda << " + " << baddb << " = " << dashusum << endl;

	string baddsum = addBinary(badda,baddb);
	cout << badda << " + " << baddb << " = " << baddsum << endl;


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
	vector<int> candidates = {2,2,3,7};
	vector<vector<int>> comb42 = combinationSum(candidates, 7);

	cout << "combination sum result: " << endl;
	printmatrix(comb42);

	cout << endl << endl;

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
