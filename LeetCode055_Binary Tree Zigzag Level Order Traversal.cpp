/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode *last = root, *final = root;
        bool tag = true;
        vector< vector<int> > answer;
        if (!root) return answer;
        answer.push_back(vector<int>());
        vector< vector<int> >::iterator iter = --answer.end();
        while (!que.empty()){
        	TreeNode *p = que.front();
        	que.pop();
        	if (tag)
        		iter->push_back(p->val);
        	else
        		iter->insert(iter->begin(), p->val);
        	if (p->left) {
        		que.push(p->left); last = p->left;
        	}
        	if (p->right) {
        		que.push(p->right); last = p->right;
        	}
        	if (p == final) {
        		tag = !tag;
        		answer.push_back(vector<int>());
        		iter = --answer.end();
        		final = last;
        	}
        }
        answer.erase(--answer.end());
        return answer;
    }
};