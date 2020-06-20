/*************************************************************************
    > File Name: 创建二叉树.cpp
    > Author: cxz
    > Mail: phenixcxz@163.com 
    > Created Time: 六  6/20 15:32:33 2020
 ************************************************************************/

#include<iostream>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode * left;
	TreeNode * right;
	TreeNode(int v = 0,TreeNode * l = NULL,TreeNode *r = NULL):val(v),left(l),right(r){}
};

TreeNode * createTree(int left,int right);

TreeNode * createTree(const int n){
	return createTree(0,n);
}


//递归创建二叉树
TreeNode * createTree(int left,int right){
	if(left == right)
		return NULL;
	int middle = (left+right)/2;
	TreeNode * root = new TreeNode(middle,NULL,NULL);
	root->left = createTree(left,middle);
	root->right = createTree(middle+1,right);
	return root;
}


//先序遍历递归版
void travPre_R(TreeNode * root){
	if(!root)
		return ;
	cout << root->val << endl;
	travPre_R(root->left);
	travPre_R(root->right);
}
//中序遍历递归版
void travIn_R(TreeNode * root){
	if(!root)
		return ;
	travIn_R(root->left);
	cout << root->val << endl;
	travIn_R(root->right);
}
//后序遍历递归版
void travPost_R(TreeNode * root){
	if(!root)
		return ;
	travPost_R(root->left);
	travPost_R(root->right);
	cout << root->val << "  ";
}



int main(void){

	TreeNode * root = createTree(10);
	travIn_R(root);
	return 0;
}
