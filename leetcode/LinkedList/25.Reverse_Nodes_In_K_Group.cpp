/*
https://leetcode-cn.com/problems/reverse-nodes-in-k-group/

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.

*/

/*
    迭代加递归 K个一组反转链表
    分解问题为：
    1. 反转head开头的k个节点 --> 子链表1
    2. 递归反转剩下的子链表 reverseKGroup(cur, k);    cur = head->next(k) 子链表2
    3. 连接 两条子链表 1 2
    
    4. 递归终止条件：head == NULL; 子链表节点数不足k个
    5. 反转head开头的k个节点：头插法；head != cur（子链表的头节点） 反转终止条件为遍历到子链表的头节点
    
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int i = 0;
        ListNode* cur = head;
        for (; i < k-1; ++i) {
            cur = cur->next;
            if (cur == NULL) {  //不足k个节点，无需反转
                return head;
            }
        }

        cur = cur->next;    //下一轮反转的头节点

        ListNode* last = head;  //反转之后的尾节点
        ListNode* NewHead = NULL;

        /*反转k个节点*/
        while (head != cur) {
            ListNode* next = head->next;
            head->next = NewHead;
            NewHead = head;
            head = next;
        }
        
        last->next = reverseKGroup(cur, k); //连接子链表

        return NewHead;
    }
};

