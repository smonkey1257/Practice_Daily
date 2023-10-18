/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //1. 遍历得到两个链表的长度
    int lengthA = 0;
    struct ListNode* curA = headA;
    while (curA->next)
    {
        ++lengthA;
        curA = curA->next;
    }

    int lengthB = 0;
    struct ListNode* curB = headB;
    while (curB->next)
    {
        ++lengthB;
        curB = curB->next;
    }

    // 如果尾结点不一致，说明不相交，立即返回
    if (curA != curB)
    {
        return NULL;
    }

    // 2. 长链表先走差值步
    struct ListNode* longHead = headA;
    struct ListNode* shortHead = headB;
    longHead = lengthA > lengthB ? headA : headB;
    shortHead = lengthA > lengthB ? headB : headA;

    for (int i = 0; i < abs(lengthA - lengthB); i++)
    {
        longHead = longHead->next;
    }

    // 3. 两个链表同时走
    while (longHead != shortHead)
    {
        longHead = longHead->next;
        shortHead = shortHead->next;
    }
    return longHead;
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)        // 有环，会在环内相遇
            return true;
    }
    return false;               // 不相遇，无环
}



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;

        // 有环
        // 重置slow指向，二者同时出发
        if (fast == slow)
        {
            slow = head;
            while (fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }

    // 无环返回NULL
    return NULL;
}