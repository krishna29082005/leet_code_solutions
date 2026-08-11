class Solution {
private:
TreeNode* first = NULL;
TreeNode* middle = NULL;
TreeNode* last = NULL;
TreeNode* prev = NULL;
    
    void inorder(TreeNode* root){
        stack<TreeNode*>st;
        while(true){

            if(root != NULL){
               st.push(root);
               root = root -> left;
            }
            else{
                if(st.empty()) break;
                root = st.top();
                st.pop();
                
                if(prev && root -> val < prev -> val){
                    if(first == NULL){
                        first = prev;
                        middle = root;
                    }else{
                        last = root;
                    }
                }
                prev = root;
                root = root -> right;
            }
        }

    }
public:
    
    void recoverTree(TreeNode* root) {

        inorder(root);
        
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};