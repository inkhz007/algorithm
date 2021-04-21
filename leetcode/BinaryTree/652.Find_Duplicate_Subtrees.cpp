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
递归思想分解问题，针对每个节点应该干什么？
1. root节点，我必须知道我为根节点这颗树长什么样（先知道左右子树长什么样）
2. ！！！左子树+右子树+root等于这颗树长什么样
3. 使用map判断是否重复，和保证只返回任意一个重复子树的根节点
*/

class Solution {
public:
    map<string, int> treeMap;
    vector<TreeNode*> retVec;

    string traverse(TreeNode* root) {
        if (root == NULL) {
            return "#";
        }

        string left = traverse(root->left);
        string right = traverse(root->right);
        
        /*left + right + root !!!*/
        string result = left + "," + right + "," + to_string(root->val);
        if (treeMap.find(result) == treeMap.end()) {
            treeMap[result] = 1;
        } else {
            treeMap[result]+=1;
            if (treeMap[result] == 2) {
                retVec.push_back(root);
            }
        }
        return result;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return retVec;
    }
};