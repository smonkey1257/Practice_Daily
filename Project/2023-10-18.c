/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //1. �����õ���������ĳ���
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

    // ���β��㲻һ�£�˵�����ཻ����������
    if (curA != curB)
    {
        return NULL;
    }

    // 2. ���������߲�ֵ��
    struct ListNode* longHead = headA;
    struct ListNode* shortHead = headB;
    longHead = lengthA > lengthB ? headA : headB;
    shortHead = lengthA > lengthB ? headB : headA;

    for (int i = 0; i < abs(lengthA - lengthB); i++)
    {
        longHead = longHead->next;
    }

    // 3. ��������ͬʱ��
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

        if (fast == slow)        // �л������ڻ�������
            return true;
    }
    return false;               // ���������޻�
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

        // �л�
        // ����slowָ�򣬶���ͬʱ����
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

    // �޻�����NULL
    return NULL;
}