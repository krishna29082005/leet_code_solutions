class Solution {
public:
    TreeNode *first = NULL, *middle = NULL;
    TreeNode *last = NULL, *prev = NULL;

    void inorderTraversal(TreeNode* root) {

        TreeNode* cur = root;

        while (cur) {

            if (cur->left == NULL) {

                if (prev && cur->val < prev->val) {
                    if (first == NULL) {
                        first = prev;
                        middle = cur;
                    } else {
                        last = cur;
                    }
                }

                prev = cur;
                cur = cur->right;
            }
            else {

                TreeNode* pred = cur->left;

                while (pred->right && pred->right != cur)
                    pred = pred->right;

                if (pred->right == NULL) {
                    pred->right = cur;
                    cur = cur->left;
                }
                else {

                    pred->right = NULL;

                    if (prev && cur->val < prev->val) {
                        if (first == NULL) {
                            first = prev;
                            middle = cur;
                        } else {
                            last = cur;
                        }
                    }

                    prev = cur;
                    cur = cur->right;
                }
            }
        }
    }

    void recoverTree(TreeNode* root) {

        inorderTraversal(root);

        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};