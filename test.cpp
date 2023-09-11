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

    void dfs(TreeNode *root, vector<int> &ans) {
        if (root == nullptr) return;

        std::stack < TreeNode * > my_stack;

        while (root != nullptr || !my_stack.empty()) {
            while (root != nullptr) {
                my_stack.push(root);
                root = root->left;
            }
            root = my_stack.top();
            my_stack.pop();

            ans.push_back(root->val);

            root = root->right;
        }
    }

    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }
};