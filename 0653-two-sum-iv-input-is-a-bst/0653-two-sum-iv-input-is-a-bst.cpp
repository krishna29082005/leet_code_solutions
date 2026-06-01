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
class BSTiterator{
    public:

    stack<TreeNode*> st;
    bool reverse = true;

    
    BSTiterator(TreeNode* root , bool isreverse){
        reverse = isreverse;
        push_all(root);
    }
    
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(reverse == true)
            push_all(temp -> left);
        else
            push_all(temp -> right);
        
        return temp -> val;
    }


private: 
    void push_all(TreeNode* root){
        while(root != NULL){
        st.push(root);
        if(reverse == true) root = root -> right;
        else root = root -> left;
        }
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;
        BSTiterator  l (root , false);
        BSTiterator  r (root , true);
        int i = l.next();
        int j = r.next();  
        while(i < j)  {
        if(i + j == k) return true;
        else if(i + j < k) i =  l.next();
        else j = r.next();
        }  
        return false; 
    }
};