/*************************************************************************
    > File Name: 二叉树的最大深度.cpp
    > Author: cxz
    > Mail: phenixcxz@163.com 
    > Created Time: 日  6/21 13:09:58 2020
 ************************************************************************/

#include<iostream>
#include"Node.h"
#include "queue"
using namespace std;

class Solution{
public:

    //迭代版，通过层序遍历树，记录遍历层数
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        queue<TreeNode * > q;
        q.push(root);
        int num = 0;
        while(!q.empty()){
            int n = q.size();
            for(int i = 0 ; i < n; i ++){
                TreeNode * temp = q.front();
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
                q.pop();
            }
            num++;
        } 
        return num;
    }

    // //递归版,树的高度为：max(左子树，右子树)+1
    // int maxDepth(TreeNode * root){
    //     if(!root)
    //         return 0;
    //     return 1+max(maxDepth(root->left),maxDepth(root->right));
    // }

};

int main(void){
    Solution solution;

}



