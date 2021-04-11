/*
    https://leetcode-cn.com/problems/reverse-linked-list/

    Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

/*
    递归反转单链表
    1. 递归终止条件： head->next == NULL; 最后一个节点
    2. 递归公式：reverse(head->next); head与一条已经反转好的节点相连
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

 ListNode* reverse(ListNode* head) {
     if (head->next == NULL) return head;
     
     ListNode* last = reverse(head->next);
     head->next->next = head;
     head->next = NULL;
     return last;
 }

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next ==NULL) {
            return head;
        }

        return reverse(head);
    }
};   


/*
    迭代反转单链表
    1. 遍历链表，头插法反转链表
    2. head->next = NULL; 链表头节点作为反转后的尾节点，next指针需要置NULL
    3. ListNode* tmp = cur->next; 因为要使用头插法，当前节点的next要指向new_head，所以需要先保存，防止丢失
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* cur = head->next;
        ListNode* rev_head = head;
        head->next = NULL;
        while(cur) {
            ListNode* tmp = cur->next;
            cur->next = rev_head;
            rev_head = cur;
            cur = tmp;
        }

        return rev_head;
    }
};


/*
  参照 https://leetcode.com/problems/reverse-linked-list/discuss/58125/In-place-iterative-and-recursive-Java-solution  优化代码
  1. 不需要cur指针，直接使用head进行遍历
  2. 不需要head->next 置为NULL，直接将NewHead置NULL开始
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
    ListNode* reverseList(ListNode* head) {

        ListNode* NewHead = NULL;
        while(head) {
            ListNode* next = head->next;
            head->next = NewHead;
            NewHead = head;
            head = next;
        }

        return NewHead;
    }
};

