//NC248 左叶子之和
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
  *
  *
  * @param root TreeNode类
  * @return int整型
  */
int sumOfLeftLeaves(struct TreeNode* root) {
    // 结点为空返回0
    if (root == NULL)
    {
        return 0;
    }

    // 如果为左叶子结点，就累加
    int sum = 0;
    if (root->left && root->left->left == NULL && root->left->right == NULL)
    {
        sum = root->left->val;
    }

    // 前序递归遍历
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}



/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param n int整型
 * @param m int整型
 * @return int整型
 */
#include <stdlib.h>
typedef struct ListNode ListNode;

// 创建结点个数为n的环形链表
ListNode* CreateCircularLinkedList(int n)
{
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int i = 1;
    head = tail = (ListNode*)malloc(sizeof(ListNode));
    tail->val = 1;
    for (i = 2; i <= n; i++)
    {
        tail->next = (ListNode*)malloc(sizeof(ListNode));
        tail = tail->next;
        tail->val = i;
    }
    tail->next = head;
    return head;
}

// 删除链表某位置结点
void deleteNode(struct ListNode* node) {

    // 将node的下一个结点的值拷贝到node结点
    node->val = node->next->val;

    // 保存node->next的位置
    struct ListNode* temp = node->next;

    // 改变连接关系
    node->next = temp->next;

    free(temp);
}
// NC132 环形链表的约瑟夫问题
int ysf(int n, int m) {
    // 创建环形链表
    ListNode* list = CreateCircularLinkedList(n);

    // 根据提议循环删除链表
    int count = 1;
    ListNode* cur = list;
    while (cur->next != cur)
    {
        if (count == m)
        {
            // 删除cur指向的结点结点
            deleteNode(cur);

            // 重置count
            count = 1;
        }
        else
        {
            // 往后走
            cur = cur->next;
            ++count;
        }
    }
    return cur->val;
}



/**
 * 203. 移除链表元素
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* removeElements(ListNode* head, int val) {
    // 如果head == NULL，cur就是NULL，程序无法进入循环，直接返回空。
    ListNode* cur = head;
    ListNode* prev = head;

    while (cur != NULL)
    {
        // 头删
        if (head->val == val)
        {
            head = head->next;
            free(cur);
            cur = head;
        }
        // 中间删 + 尾删
        else
        {
            if (cur->val == val)
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
            else
            {
                prev = cur;
                cur = cur->next;
            }
        }
    }
    return head;
}



/**
 * 206. 反转链表
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* reverseList(ListNode* head) {
    // 0 个元素
    if (head == NULL)
        return NULL;
    // 1 个元素
    if (head->next == NULL)
        return head;

    // 2 个以上元素
    ListNode* prev = head;
    ListNode* cur = head->next;
    ListNode* temp = head->next;

    prev->next = NULL;
    while (1)
    {
        temp = cur;
        cur = cur->next;
        temp->next = prev;
        prev = temp;

        if (cur == NULL)
            break;
    }
    return prev;
}



/**
 * 876. 链表的中间结点
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // 快慢指针法
 // 快指针一次循环走两步，慢指针一次循环走一步
 // 循环退出条件为fast == NULL or fast->next == NULL。
typedef struct ListNode ListNode;
ListNode* middleNode(ListNode* head) {
    ListNode* fast, * slow;
    fast = slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}