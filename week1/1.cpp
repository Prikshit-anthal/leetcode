

// https : // leetcode.com/problems/path-sum-ii/


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
        class Solution
{
    vector<vector<int>> ans;

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {

        vector<int> curr;

        if (root != NULL)
            transverse(root, targetSum, curr);

        return ans;
    }

    void transverse(TreeNode *root, int targetSum, vector<int> &curr)
    {
        curr.push_back(root->val);
        targetSum -= root->val;

        if (root->right == NULL && root->left == NULL)
        {
            if (targetSum == 0)
                ans.push_back(curr);

            curr.pop_back();
            targetSum += root->val;
            return;
        }

        if (root->left != NULL)
            transverse(root->left, targetSum, curr);
        if (root->right != NULL)
            transverse(root->right, targetSum, curr);

        curr.pop_back();
        targetSum += root->val;
    }
};