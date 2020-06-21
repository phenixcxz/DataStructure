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



void travPre_I(TreeNode * root){
	stack<TreeNode *> S;
	S.push(root);
	while(!S.empty()){
		TreeNode * temp = S.top();		//输出节点
		S.pop();
		cout << temp->val << "  ";
		if(temp->right != NULL)			//如果有右节点则入栈，等待左子树输出后再输出
			S.push(temp->right)	;
		if(temp->left != NULL) 			//如果有左节点则入栈，等待输出
			S.push(temp->left);

	}
}

//先序遍历迭代版
void travPre_I2(TreeNode * root){
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
void travIn_I(TreeNode *root){
	stack<TreeNode*> S;
	S.push(root);
	while(!S.empty()){
		while(S.top()->left)		//入栈到左底节点
			S.push(S.top()->left);
		while(!S.empty()){
			TreeNode * temp = S.top();
			S.pop();
			cout << temp->val << "  ";		//输出节点
			if(temp->right){
				S.push(temp->right);		//如果有右子节点，入栈，返回重新入栈到左底节点
				break;
			}

		}
	}
}

//中序遍历迭代版
void travIn_I2(TreeNode * root){
	stack<TreeNode *> S;
	while(1){
		if(root){
			S.push(root);
			root = root->left;
		}
		else if(!S.empty()){
			root = S.top();
			cout << root->val << "  ";
			root = root->right;
			S.pop();
		}
		else
			break;

	}
	cout << endl;
}




// //后序遍历迭代版
// void travPost_I(TreeNode * root){
// 	stack<TreeNode *> S;
// 	if(root)
// 		S.push(root);
// 	while(S.size()){
// 		if(S.top()->left != root && S.top()->right != root){
// 			while(TreeNode* x = S.top()){
// 				if(x->left){
// 					if(x->right)
// 						S.push(x->right);
// 					S.push(x->left);
// 				}
// 					S.push(x->right);
// 			}
// 			S.pop();
// 		}
// 		root = S.top();
// 		S.pop();
// 		cout << root->val << "  ";
// 	}	
// }

//后序遍历迭代版
void travPost_I(TreeNode * root){
	stack<TreeNode *> S;
	S.push(root);
	TreeNode * lastNode = nullptr;
	while(S.size()){
		while(S.top()->left)
			S.push(S.top()->left);
		while(S.size()){
			if( lastNode == S.top()->right ||  S.top()->right == NULL){
				TreeNode * temp = S.top();
				S.pop();
				cout << temp->val << "  ";
				lastNode = temp;		
			}
			else if(S.top()->right){
				S.push(S.top()->right);
				break;
			}
		}
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

	cout << endl << "中序遍历迭代版" << endl;
	travIn_I(root) ;

	cout << endl << "后序遍历迭代版" << endl;
	travPost_I(root);
	
	cout << endl<< "层序遍历迭代版" << endl;
	travLevel_I(root);
	cout << endl;
	return 0;
}
