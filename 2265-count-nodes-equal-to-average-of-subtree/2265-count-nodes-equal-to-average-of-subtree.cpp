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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;

        auto dfs = [&](auto& self, TreeNode* node) -> pair<int, int> {
            if (!node) return {0, 0};
            auto [l_sum, l_count] = self(self, node->left);
            auto [r_sum, r_count] = self(self, node->right);

            int sum = l_sum + r_sum + node->val, cnt = l_count + r_count + 1;
            ans += (sum / cnt == node->val);
            return {sum, cnt};
        };

        dfs(dfs, root);
        return ans;
    }
};