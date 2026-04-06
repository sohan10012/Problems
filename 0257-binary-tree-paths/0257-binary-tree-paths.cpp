class Solution {
public:

    void solve(TreeNode* root, string path, vector<string>& res) {
        if (!root) return;

        
        if (!root->left && !root->right) {
            res.push_back(path + to_string(root->val));
            return;
        }

       
        path += to_string(root->val) + "->";

        solve(root->left, path, res);
        solve(root->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        solve(root, "", res);
        return res;
    }
};