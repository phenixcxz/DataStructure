/*************************************************************************
    > File Name: 创建二叉树.cpp
    > Author: cxz
    > Mail: phenixcxz@163.com 
    > Created Time: 六  6/20 15:32:33 2020
 ************************************************************************/

#include<iostream>
#include"queue"
#include "stack"
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
	cout << root->val << "  ";
	travPre_R(root->left);
	travPre_R(root->right);
}
//中序遍历递归版
void travIn_R(TreeNode * root){
	if(!root)
		return ;
	travIn_R(root->left);
	cout << root->val << "  ";
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

// //先序遍历迭代版
// void travPre_I(TreeNode *root){
// 	stack<TreeNode *> S;
// 	while(1){
// 		while(root){
// 			cout << root->val << "  ";
// 			if(root->right)
// 				S.push(root->right);
// 			root = root->left;
// 		}
// 		if(S.empty())
// 			break;
// 		root = S.top();
// 		S.pop();
// 	}
// }

//先序遍历迭代版
void travPre_I(TreeNode * root){
	stack<TreeNode *> S;
	while(1){
		while(root){
			cout << root->val << "  ";
			if(root->right)
				S.push(root->right);
			root = root->left;
		}
		if(S.empty())
			break;
		root = S.top();
		S.pop();
	}
}

//中序遍历迭代版
void travIn_I(TreeNode * root){
	stack<TreeNode *> S;
	while(1){
		while(root){
			S.push(root);
			root = root->left;
		}
		if(S.empty())
			break;
		root = S.top();
		cout << root->val << "  ";
		root = root->right;
		S.pop();
	}
}


//层序遍历迭代版
void travLevel_I(TreeNode* root){
	queue<TreeNode *> Q;
	Q.push(root);
	while(Q.size()){
		TreeNode * temp = Q.front();
		Q.pop();
		cout << temp->val << "  ";
		if(temp->left)
			Q.push(temp->left);
		if(temp->right)
			Q.push(temp->right);
	}
}



int main(void){

	TreeNode * root = createTree(10);
	cout <<endl << "先序遍历递归版："  << endl;
	travPre_R(root);
	cout << endl << "中序遍历递归版：" << endl;
	travIn_R(root);
	cout << endl << "后序遍历递归版" << endl;
	travPost_R(root);

	cout << endl<<"先序遍历迭代版" << endl;
	travPre_I(root);

	cout << endl << "层序遍历迭代版" << endl;
	travIn_I(root) ;
	
	cout << endl<< "层序遍历迭代版" << endl;
	travLevel_I(root);
	cout << endl;
	return 0;
}
