class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return NULL;
        queue<Node*> q;

        q.push(root);

        while(q.size() > 0){

            int size = q.size();
            Node* prev = NULL;

            for(int i = 0 ; i<size ; i++){
                Node* cur = q.front();
                q.pop();

                if(prev){
                    prev->next  = cur;
                }
                prev = cur;

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

        }

        return root;
    }
};