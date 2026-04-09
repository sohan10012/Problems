/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair< TreeNode* , unsigned long long >> q;
        q.push({root,0});
        int mw = 0;

        while(q.size() > 0){
            unsigned long long si = q.front().second;
            unsigned long long ei = q.back().second;
            int cs = q.size();

            mw = max(mw, (int)(ei - si + 1));

            for(int i = 0 ; i < cs ; i++){
                auto n  = q.front();
                q.pop();

                if(n.first->left) {
                    q.push({n.first->left, 2 * n.second + 1});
                }

                if(n.first->right){
                    q.push({n.first->right, 2 * n.second + 2});
                }
            }

        }

        return mw;
    }
};