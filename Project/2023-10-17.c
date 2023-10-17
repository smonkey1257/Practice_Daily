/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
  // 快慢指针法，快指针先走k步，然后快、慢指针一起走，直到fast == NULL
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // 细节1：空链表直接返回
    if (pListHead == NULL)
        return NULL;

    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;

    while (k--)
    {
        // 细节2：先走k步时，fast成为NULL，说明k过大，不存在该节点
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }

    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ListNode;
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // list1 == NULL
    if (list1 == NULL)
        return list2;

    // list2 == NULL
    if (list2 == NULL)
        return list1;

    // 都不为空
    // 带哨兵位头结点，处理newHead == NULL时的链接
    ListNode* newHead = (ListNode*)malloc(sizeof(ListNode));
    ListNode* newTail = newHead;

    while (list1 && list2)
    {
        if (list1->val <= list2->val)
        {
            newTail->next = list1;
            newTail = newTail->next;
            list1 = list1->next;
        }
        else
        {
            newTail->next = list2;
            newTail = newTail->next;
            list2 = list2->next;
        }
    }

    if (list1)
    {
        newTail->next = list1;
    }

    if (list2)
    {
        newTail->next = list2;
    }

    // 删除哨兵位头节点
    ListNode* temp = newHead->next;
    free(newHead);
    return temp;
}



/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // 将链表分割成小于x、大于等于x的两部分，再将它们链接在一起，这个的时间复杂度是最低的
        ListNode* lessHead = new ListNode(0);
        ListNode* lessTail = lessHead;
        ListNode* greatHead = new ListNode(0);
        ListNode* greatTail = greatHead;

        while (pHead)
        {
            if (pHead->val < x)
            {
                lessTail->next = pHead;
                lessTail = lessTail->next;
                pHead = pHead->next;
                lessTail->next = nullptr;
            }
            else
            {
                greatTail->next = pHead;
                greatTail = greatTail->next;
                pHead = pHead->next;
                greatTail->next = nullptr;
            }
        }
        // 链接两个链表
        lessTail->next = greatHead->next;

        // 删除两个哨兵位结点
        ListNode* tempL = lessHead;
        lessHead = lessHead->next;
        ListNode* tempG = greatHead;
        greatHead = greatHead->next;
        free(tempG);
        free(tempL);

        return lessHead;
    }
};



/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    // 获取链表中间节点啊
    ListNode* GetMiddleNode(ListNode* head) {
        ListNode* fast, * slow;
        fast = slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    // 逆置链表
    ListNode* ReverseList(ListNode* head) {
        // 0 个元素
        if (head == nullptr)
            return nullptr;
        // 1 个元素
        if (head->next == nullptr)
            return head;

        // 2 个以上元素
        ListNode* prev = head;
        ListNode* cur = head->next;
        ListNode* temp = head->next;

        prev->next = nullptr;
        do
        {
            temp = cur;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
        } while (cur != nullptr);
        return prev;
    }

    bool chkPalindrome(ListNode* plist) {
        // 第一步获取中间结点
        ListNode* midNode = GetMiddleNode(plist);

        // 第二步逆置后半部分链表
        ListNode* RList = ReverseList(midNode);

        // 第三步比较两个链表
        ListNode* curP = plist;
        ListNode* curR = RList;
        while (curR)
        {
            if (curR->val != curP->val)
            {
                return false;
            }

            curP = curP->next;
            curR = curR->next;
        }

        return true;
    }
};