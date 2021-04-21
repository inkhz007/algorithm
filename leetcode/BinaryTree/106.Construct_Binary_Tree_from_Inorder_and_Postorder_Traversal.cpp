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
   TreeNode* build(vector<int>& inorder, int inStart, int inEnd, \
                    vector<int>& postorder, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int i = inStart;
        for (; i <= inEnd; ++i) {
            if (inorder[i] == postorder[postEnd]){
                break;
            }
        }

        root->left = build( inorder, inStart, i-1,
                            postorder, postStart, postStart+(i-inStart)-1);
        root->right = build( inorder, i+1, inEnd,
                             postorder, postStart+(i-inStart), postEnd-1);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1);
    }
};