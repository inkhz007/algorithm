/*
116. Populating Next Right Pointers in Each Node
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

 

Follow up:

You may only use constant extra space.
Recursive approach is fine, you may assume implicit stack space does not count as extra space for this problem.
 
*/

/*
    递归分解问题：
    1. 分解为每个节点需要做的事情，这道题是做不到的，因为有node1->right 与 node2->left相连接的情况
    2. 修改递归函数的参数，增加为两个节点(node1 node2)
    3. 递归终止条件: node1 == NULL || node2 == NULL;
    4. 递归公式：connect(node1->left, node1->right);  connect(node1->right, node2->left); connect(node2->left, node2->right);
    5. node->next = node2 （因为传入函数的已经是需要连接的两个节点了）
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connect(Node* node1, Node* node2) {
        if (node1 == NULL || node2 == NULL) {
            return;
        }
        connect(node1->left, node1->right);
        connect(node1->right, node2->left);
        connect(node2->left, node2->right);

        node1->next = node2;
    }

    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        connect(root->left, root->right);
        return root;
    }
};