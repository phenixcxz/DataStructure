#include "iostream"
#include "vector"
#include "queue"
#include"Node.h"

using namespace std;


class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > nums;
        if(!root)
            return nums;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp(n);
            for(int i = 0; i <n; ++i){
                TreeNode * cur = q.front();
                temp[i] = cur->val;
                q.pop();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            nums.push_back(temp);
        }

        return nums;

    }
};