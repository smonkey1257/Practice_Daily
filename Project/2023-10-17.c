/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
  // ����ָ�뷨����ָ������k����Ȼ��졢��ָ��һ���ߣ�ֱ��fast == NULL
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // ϸ��1��������ֱ�ӷ���
    if (pListHead == NULL)
        return NULL;

    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;

    while (k--)
    {
        // ϸ��2������k��ʱ��fast��ΪNULL��˵��k���󣬲����ڸýڵ�
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

    // ����Ϊ��
    // ���ڱ�λͷ��㣬����newHead == NULLʱ������
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

    // ɾ���ڱ�λͷ�ڵ�
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
        // ������ָ��С��x�����ڵ���x�������֣��ٽ�����������һ�������ʱ�临�Ӷ�����͵�
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
        // ������������
        lessTail->next = greatHead->next;

        // ɾ�������ڱ�λ���
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
    // ��ȡ�����м�ڵ㰡
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

    // ��������
    ListNode* ReverseList(ListNode* head) {
        // 0 ��Ԫ��
        if (head == nullptr)
            return nullptr;
        // 1 ��Ԫ��
        if (head->next == nullptr)
            return head;

        // 2 ������Ԫ��
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
        // ��һ����ȡ�м���
        ListNode* midNode = GetMiddleNode(plist);

        // �ڶ������ú�벿������
        ListNode* RList = ReverseList(midNode);

        // �������Ƚ���������
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