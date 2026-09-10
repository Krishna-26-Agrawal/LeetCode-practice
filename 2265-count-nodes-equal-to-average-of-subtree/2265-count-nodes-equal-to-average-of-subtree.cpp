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
    pair<int, int> solve(TreeNode* root, int &count){
        if(!root){
            return {0, 0};
        }

        auto leftVal = solve(root -> left, count);
        auto rightVal = solve(root -> right, count);

        int sum = leftVal.first + rightVal.first;
        int n = leftVal.second + rightVal.second;

        if((sum + root -> val) / (n + 1) == root -> val){
            count++;
        }

        return {sum + root -> val, n + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        auto ans = solve(root, count);
        return count;
    }
};