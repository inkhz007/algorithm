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
 /*
 解决思想：每个节点需要做的就是，通过前序中序的结果，找出root节点，再分割出前序中序的左子树 和 右子树 递归调用

 前序遍历：[root|  root->left  |  root->right  ] preStart preEnd
 中序遍历：[  root->left  |root|  root->right  ] inStart inEnd

 1. 通过前序遍历结果的第一个索引就可以找到root值
 2. root值和中序遍历就可以 分割得到中序 左子树和右子树
 3. 通过步骤2 可以拿到 root节点的索引index 左子树的长度 index - inStart，从而可以得到 前序的左子树和右子树

 找个例子画图辅助最容易分析
 4. 前序分割：   root --> preStart;
                root->left: preStart+1 --> preStart+(index-inStart)
                root->right: preStart+(index-inStart)+1 -> preEnd
    
    中序分割：   root->left: inStart --> index-1
                root->right: index+1 --> inEnd

5. 递归公式：root->left = build( preorder, preStart+1, preStart+(index-inStart),
                                inorder, inStart, index-1);
            root->right = build( preorder, preStart+(index-inStart)+1, preEnd
                                 inorder, index+1, inEnd);
6. 递归终止条件：preStart > preEnd || inStart > inEnd
 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, \
                    vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);

        int i = inStart;
        for (; i <= inEnd; ++i) {
            if (inorder[i] == preorder[preStart]) {
                break;
            }
        }

        root->left = build( preorder, preStart+1, preStart+(i-inStart), \
                            inorder, inStart, i-1);
        root->right = build( preorder, preStart+(i-inStart)+1, preEnd, \
                            inorder, i+1, inEnd);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};