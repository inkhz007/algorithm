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
 1. 每一个根节点需要干什么？
 2. root：找到当前输入数组的最大值，构造root节点
 3. 通过控制起止下标，传入左右数组，递归构造左右子树
 4. 递归公式 index = max; root(nums[index])
             root->left = constructMaximumBinaryTree(nums, start, index-1) 
             root->right = constructMaximumBinaryTree(nums, index+1, right)
 5. 递归终止条件：start > right 
 */
 
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums, size_t left, size_t right) {
        if (left > right) {
            return NULL;
        }

        size_t i = left;
        size_t index = left;
        int max = nums[left];

        for (; i <= right; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                index = i;
            }
        }

        TreeNode* root = new TreeNode(max);

        //特别注意最大值为第一个节点（左子树为NULL）和最后一个节点（右子树为NULL的情况，因为没有拷贝新的vector，防止索引错乱
        if (index == left) {
            root->left = NULL;
        } else {
            root->left = constructMaximumBinaryTree(nums, left, index-1);
        }

        if (index == right) {
            root->right = NULL;
        } else {
            root->right = constructMaximumBinaryTree(nums, index+1, right);
        }

        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }

        return constructMaximumBinaryTree(nums, 0, nums.size()-1);
    }
};

/*
This solution is inspired by @votrubac
Here is his brilliant solution
https://discuss.leetcode.com/topic/98454/c-9-lines-o-n-log-n-map

The key idea is:

We scan numbers from left to right, build the tree one node by one step;
We use a stack to keep some (not all) tree nodes and ensure a decreasing order;
For each number, we keep pop the stack until empty or a bigger number; The bigger number (if exist, it will be still in stack) is current number's root, and the last popped number (if exist) is current number's left child (temporarily, this relationship may change in the future); Then we push current number into the stack.

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> stk;
        for (int i = 0; i < nums.size(); ++i)
        {
            TreeNode* cur = new TreeNode(nums[i]);
            while (!stk.empty() && stk.back()->val < nums[i])
            {
                cur->left = stk.back();
                stk.pop_back();
            }
            if (!stk.empty())
                stk.back()->right = cur;
            stk.push_back(cur);
        }
        return stk.front();
    }
};
This solution will be slightly faster than normal recursive solution.

Again, great thanks to @votrubac !!!
*/