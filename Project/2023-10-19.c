/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
        return NULL;

    // ԭ�������׷�ӿ������
    struct Node* cur = head;
    while (cur)
    {
        // ���ٿ������
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;

        // ���뿽�����
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode->next;
    }

    // ���ӹ�ϵ����
    struct Node* old = head;
    struct Node* new = head->next;
    struct Node* copyHead = new;

    while (1)
    {
        new->random = old->random == NULL ? NULL : old->random->next;

        if (new->next == NULL)
            break;

        old = new->next;
        new = old->next;
    }

    // ������������
    old = head;
    new = head->next;
    while (1)
    {
        if (new->next == NULL)
            break;

        old->next = new->next;
        old = old->next;
        new->next = old->next;
        new = new->next;
    }
    old->next = NULL;

    return copyHead;
}



#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top; // ջ��
    int capacity; // ����
}ST;

// ��ʼ��ջ
void StackInit(ST* ps)
{
    //�ṹ��ĵ�ַ����Ϊ��
    assert(ps);

    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

// ����ջ(�ڴ�й¶)
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ���true�������Ϊ��false 
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}
// ��ջ
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //ջ����Ҫ��������
    if (ps->capacity == ps->top)
    {
        int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * NewCapacity);
        if (tmp == NULL)
        {
            printf("����ʧ�ܣ�\n");
            exit(-1);
        }
        //���ݳɹ�
        ps->a = tmp;
        ps->capacity = NewCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}

// ��ջ
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

// ��ȡջ��Ԫ��
STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}

/*
����ƥ������֣�һ������ƥ�䣻��������ƥ��
1. ÿ�������Ŷ���һ�������ͬ���������ź���ƥ��
2. �����ź������ŵ��������
�����һ�������������ţ���ջ�����������ţ�ջ�����ų�ջ�����ţ�ƥ�䣻���ջ�շ���true�����򷵻�false
�����һ�������������ţ�ֱ�ӷ���false
*/
bool isValid(char* s) {
    // �����һ�������������ţ�ֱ�ӷ���false
    if (*s == ')' || *s == '}' || *s == ']' || *s == '\0')
        return false;

    ST* st = (ST*)malloc(sizeof(ST));
    StackInit(st);

    while (*s)
    {
        // ��������ջ
        if (*s == '(' || *s == '{' || *s == '[')
        {
            StackPush(st, *s);
        }

        // �����ţ���������ƥ�䣨�ڼ�ջ�շ���fasle��
        else if (*s == ')' || *s == '}' || *s == ']')
        {
            if (StackEmpty(st))
            {
                return false;
            }
            else
            {
                char top = StackTop(st);
                StackPop(st);
                if ((*s == ')' && top != '(') ||
                    (*s == '}' && top != '{') ||
                    (*s == ']' && top != '['))
                {
                    return false;
                }
            }
        }
        ++s;
    }
    return StackEmpty(st);
}