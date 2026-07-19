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
    int solve(TreeNode* root, int &count){
        if(!root){
            return 0;
        }

        int l = solve(root -> left, count);
        int r = solve(root -> right, count);

        // cout << l << " " << r << endl;

        if(l == 0 && r == 0){
            count++;
        }
        else if(root -> val == max(root -> val, max(l, r))){
            count++;
        }

        return max(root -> val, max(l, r));
    }
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        int val = solve(root, count);
        return count;
    }
};