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
class bstiterator{
    private:
    stack<TreeNode*> st;
    bool isreverse = true;

    public:
    bstiterator(TreeNode* root , bool flag){
        isreverse = flag;
        push_all(root);
    }

    int next(){
        auto it = st.top();
        st.pop();

        if(isreverse) push_all(it -> left);
        else push_all(it -> right); 

        return it -> val;
    }

    bool hasnext(){
        if(st.empty()) return false;
        else return true;
    }

    void push_all(TreeNode* root)
    {
        while(root != NULL){

            st.push(root);

            if(isreverse) root = root -> right;
            else root = root -> left;
        }
    }
};
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        bstiterator l(root , false);
        bstiterator r(root , true);
        
        int i = l.next();
        int j = r.next();
        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};