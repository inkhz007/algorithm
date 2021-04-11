/*
https://leetcode-cn.com/problems/palindrome-linked-list/

Given the head of a singly linked list, return true if it is a palindrome.
*/


/*
    递归判断链表是否是回文串
    
    void traverse(ListNode* head) {
        //前序遍历
        
        traverse(head->next);
        
        //后续遍历
    }
    
    1. 利用递归退栈，后续遍历链表的方式，实现双指针偏移判断

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
ListNode* left;

public:
    bool traverse(ListNode* right) {
        if (right == NULL) {
            return true;
        }
        bool ret = traverse(right->next);

        if (ret == false || left->val != right->val){
            return false;
        }

        left=left->next;    //递归退一层栈，左指针就右移一位
        return true;
    }
    bool isPalindrome(ListNode* head) {
        left = head;
        return traverse(head);
    }
};



/*
    1. 利用双指针技巧-快慢指针，找到后半段链表的头节点
    2. reverse(right) 反转后半段链表
    3. 遍历left和right进行回文链表的判断
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
ListNode* left;

public:
    ListNode* reverse(ListNode* right) {
        ListNode* NewHead = NULL;
        while(right) {
            ListNode* next = right->next;
            right->next = NewHead;
            NewHead = right;
            right = next;
        }
        return NewHead;
    }

    ListNode* GetMidRightNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast!= NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != NULL)  {
            slow = slow->next;
        } //奇数，前进一步

        return slow;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        ListNode* left = head;
        ListNode* right = GetMidRightNode(head);
        right = reverse(right);

        while(right) {
            if (left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }

        return true;
    }
};


/*
https://leetcode.com/problems/palindrome-linked-list/discuss/64501/Java-easy-to-understand

也是用的快慢指针和反转后半部分链表的思想
*/

public boolean isPalindrome(ListNode head) {
    ListNode fast = head, slow = head;
    while (fast != null && fast.next != null) {
        fast = fast.next.next;
        slow = slow.next;
    }
    if (fast != null) { // odd nodes: let right half smaller
        slow = slow.next;
    }
    slow = reverse(slow);
    fast = head;
    
    while (slow != null) {
        if (fast.val != slow.val) {
            return false;
        }
        fast = fast.next;
        slow = slow.next;
    }
    return true;
}

public ListNode reverse(ListNode head) {
    ListNode prev = null;
    while (head != null) {
        ListNode next = head.next;
        head.next = prev;
        prev = head;
        head = next;
    }
    return prev;
}