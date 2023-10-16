//NC248 ��Ҷ��֮��
/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */
 /**
  * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
  *
  *
  * @param root TreeNode��
  * @return int����
  */
int sumOfLeftLeaves(struct TreeNode* root) {
    // ���Ϊ�շ���0
    if (root == NULL)
    {
        return 0;
    }

    // ���Ϊ��Ҷ�ӽ�㣬���ۼ�
    int sum = 0;
    if (root->left && root->left->left == NULL && root->left->right == NULL)
    {
        sum = root->left->val;
    }

    // ǰ��ݹ����
    return sum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}



/**
 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
 *
 *
 * @param n int����
 * @param m int����
 * @return int����
 */
#include <stdlib.h>
typedef struct ListNode ListNode;

// ����������Ϊn�Ļ�������
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

// ɾ������ĳλ�ý��
void deleteNode(struct ListNode* node) {

    // ��node����һ������ֵ������node���
    node->val = node->next->val;

    // ����node->next��λ��
    struct ListNode* temp = node->next;

    // �ı����ӹ�ϵ
    node->next = temp->next;

    free(temp);
}
// NC132 ���������Լɪ������
int ysf(int n, int m) {
    // ������������
    ListNode* list = CreateCircularLinkedList(n);

    // ��������ѭ��ɾ������
    int count = 1;
    ListNode* cur = list;
    while (cur->next != cur)
    {
        if (count == m)
        {
            // ɾ��curָ��Ľ����
            deleteNode(cur);

            // ����count
            count = 1;
        }
        else
        {
            // ������
            cur = cur->next;
            ++count;
        }
    }
    return cur->val;
}



/**
 * 203. �Ƴ�����Ԫ��
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* removeElements(ListNode* head, int val) {
    // ���head == NULL��cur����NULL�������޷�����ѭ����ֱ�ӷ��ؿա�
    ListNode* cur = head;
    ListNode* prev = head;

    while (cur != NULL)
    {
        // ͷɾ
        if (head->val == val)
        {
            head = head->next;
            free(cur);
            cur = head;
        }
        // �м�ɾ + βɾ
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
 * 206. ��ת����
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
ListNode* reverseList(ListNode* head) {
    // 0 ��Ԫ��
    if (head == NULL)
        return NULL;
    // 1 ��Ԫ��
    if (head->next == NULL)
        return head;

    // 2 ������Ԫ��
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
 * 876. ������м���
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 // ����ָ�뷨
 // ��ָ��һ��ѭ������������ָ��һ��ѭ����һ��
 // ѭ���˳�����Ϊfast == NULL or fast->next == NULL��
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