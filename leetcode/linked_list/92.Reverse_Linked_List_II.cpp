/*
    https://leetcode-cn.com/problems/reverse-linked-list/

    Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
*/

/*
    递归反转链表的m-n个节点
    1. 反转链表的前N个节点（reverseN）
    2. 递归公式: reverseN(head->next, n-1) 和 当前节点与反转后的链表连接；
    3. 递归终止条件：n==1 需要反转的最后一个节点，并保存后续链表头
    
    4. head - M之间的链表不需要反转
    5. 递归公式：head->next = reverseBetween(head->next, m-1, n - 1);
    6. 递归终止条件 m == 1 需要反转的第一个节点，调用reverseN；
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
 ListNode* successor = NULL;

 ListNode* reverseN(ListNode* head, int n) {
     if (n == 1) {  //需要反转的最后一个节点
        successor = head->next;
        return head;
     }

     ListNode* last = reverseN(head->next, n-1);
     head->next->next = head;
     head->next = successor;
     return last;
 }

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        if (left == 1) {
            return reverseN(head, right);
        }

        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
};

/*
    迭代反转链表的m-n个节点
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode dummpy(0);
        ListNode* pre = &dummpy;
        dummpy.next = head;

        int i = 0;
        for (; i < left-1; ++i) { 
            pre = head; //保留反转链表的前驱节点
            head = head->next; 
        }

        ListNode* last = head;  //保留反转链表的尾节点

        // 头插法反转 m-n 节点
        ListNode* NewHead = NULL;
        for (i = 0; i < right-left+1; ++i) {
            ListNode* next = head->next;
            head->next = NewHead;
            NewHead = head;
            head = next;
        }

        pre->next = NewHead;    //连接前驱节点
        last->next = head;      //连接后续节点

        return dummpy.next;
    }
};


/*
https://leetcode.com/problems/reverse-linked-list-ii/discuss/30666/Simple-Java-solution-with-clear-explanation

leetcode 投票最高的反转是用迭代法
1. 遍历pre 到 最要反转的节点
2. 头插法反转 m-n
*/