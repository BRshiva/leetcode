class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int& ans) {
        if (root == nullptr)
            return {0, 0};

        auto left = dfs(root->left, ans);
        auto right = dfs(root->right, ans);

        int sum = left.first + right.first + root->val;
        int count = left.second + right.second + 1;

        if (root->val == sum / count)
            ans++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};