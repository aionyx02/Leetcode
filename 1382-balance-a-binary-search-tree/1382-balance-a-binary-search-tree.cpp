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
    vector<TreeNode*> nodes;
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return build(0, nodes.size() - 1);
    }
private:
    void inorder(TreeNode* node) {
        if (node == NULL) return;
        inorder(node->left);
        nodes.push_back(node);
        inorder(node->right);
    }
    TreeNode* build(int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left)/2;

        TreeNode* curr = nodes[mid];

        curr -> left = build(left, mid - 1);
        curr -> right = build(mid + 1, right);

        return curr;
    }
};