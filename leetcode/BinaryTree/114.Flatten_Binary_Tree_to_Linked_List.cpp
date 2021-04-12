/*
https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/

Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

/*
    二叉树的问题要转换为每个节点需要怎么进行处理（递归分解子问题）
    1. 当前节点root，左子树已经转换为链表1，右子树 链表2
    2. 递归公式：flatten(root.left); flatten(root.right)
    3. 连接 root节点，链表1和链表2
    
    后序遍历，因为要先将左子树和右子树转换成链表
*/


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
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        TreeNode* right = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode* cur = root;
        while(cur->right) {
            cur = cur->right;
        }

        cur->right = right;
    }
};

