/* Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Note:

    The number of nodes in the tree is between 1 and 1000.
    node.val is 0 or 1.
    The answer will not exceed 2^31 - 1. */

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
    int ans;
    void f(TreeNode* node, int curr, int l){
        if(!node)
            return;
        
        if(!node->left && !node->right){
            ans += curr*2+node->val;
            // cout<<ans<<endl;
            return;
        }
        
        f(node->left, curr*2+node->val, l*2);
        f(node->right, curr*2+node->val, l*2);
    }
    int sumRootToLeaf(TreeNode* root) {
        ans = 0;
        int curr=0, l=1;
        f(root, curr, l);
        return ans;
    }
};
