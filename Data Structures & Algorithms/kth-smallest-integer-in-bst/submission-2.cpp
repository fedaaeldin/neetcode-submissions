class Solution {
public:
    int cnt = 0;
    int res = 0;

    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        inorder(root, k);
        return res;
    }

private:
    void inorder(TreeNode* root, int k) {
        if (!root || cnt >= k) {
            return;
        }

        inorder(root->left, k);

        if (cnt >= k) {
            return;
        }

        if (++cnt == k) {
            res = root->val;
            return;
        }

        inorder(root->right, k);
    }
};