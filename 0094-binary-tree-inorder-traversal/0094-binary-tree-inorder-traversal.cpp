class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur  = root;
        vector<int> ans;

        while(cur != NULL){

            if(cur->left == NULL){
                ans.push_back(cur->val); 
                cur = cur->right;
            }
            else{
                TreeNode* IP = cur->left;
                
                while(IP->right != NULL && IP->right != cur){
                    IP = IP->right;
                }

                if(IP->right == NULL){
                    IP->right = cur;
                    cur = cur->left;
                }
                else{
                    IP->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }

        }
        return ans;
    }
};