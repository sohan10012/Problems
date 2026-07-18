class Solution {
public:

    int dfs(TreeNode* root, int currMin, int currMax) {

        if (root == nullptr) {
            return currMax - currMin;
        }

        currMin = min(currMin, root->val);
        currMax = max(currMax, root->val);

        int left = dfs(root->left, currMin, currMax);
        int right = dfs(root->right, currMin, currMax);

        return max(left, right);
    }

    int maxAncestorDiff(TreeNode* root) {

        return dfs(root, root->val, root->val);
    }
};