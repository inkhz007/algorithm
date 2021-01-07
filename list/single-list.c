#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct ListNode{
    int val;
    struct ListNode* next;
    //todo ListNode(int x) : val(x), next(NULL) {}
};

typedef struct ListNode *PNode;
typedef struct ListNode Node;

/*定义一个哑节点，简化链表代码*/
Node g_head;

/*
 * 插入一个元素到链表中
*/
void insert(int val) {
   //头插法
   PNode* node = (PNode*)malloc(sizeof(Node)); 
   if (node == NULL) {
       printf("malloc error\n");
       return;
   }

   memset(node, 0, sizeof(*node));
   node->val = val;

   PNode* tmp = g_head.next;
   g_head.next = node;
   node->next = tmp;
}

/*
 * 从链表中删除一个元素
*/
void delete() {

}

/*
 * 查找一个元素是否在链表中
 * return: true 是 ； false 否
*/
bool find(int target) {
    struct ListNode* cur = g_head.next;

    while (cur) {
        if (cur->val == target) {
            return true;
        }
    }

    return false;
}

int main() {
    printf("%d\n", g_head.val);
    printf("%p\n", g_head.next);
    printf("%d\n", find(1));
}

