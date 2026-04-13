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
    vector<int> a;

    void helper(TreeNode* root , vector<int>& a){
        if(root == nullptr) return;

        helper(root->left,a);
        a.push_back(root->val);
        helper(root->right,a);
    }

    int minDiffInBST(TreeNode* root) {
       
        helper(root,a);

        int minv = INT_MAX;

        for(int i = 1 ; i < a.size() ; i++){
            minv = min(minv , (a[i] - a[i-1]));  
        }
        return minv;
    }
};