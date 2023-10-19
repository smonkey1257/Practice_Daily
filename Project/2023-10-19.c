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

    // 原链表结点后追加拷贝结点
    struct Node* cur = head;
    while (cur)
    {
        // 开辟拷贝结点
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;

        // 插入拷贝结点
        newnode->next = cur->next;
        cur->next = newnode;
        cur = newnode->next;
    }

    // 链接关系拷贝
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

    // 分离两个链表
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

// 支持动态增长的栈
typedef int STDataType;
typedef struct Stack
{
    STDataType* a;
    int top; // 栈顶
    int capacity; // 容量
}ST;

// 初始化栈
void StackInit(ST* ps)
{
    //结构体的地址不能为空
    assert(ps);

    ps->a = NULL;
    ps->top = 0;
    ps->capacity = 0;
}

// 销毁栈(内存泄露)
void StackDestroy(ST* ps)
{
    assert(ps);
    free(ps->a);
    ps->a = NULL;
    ps->capacity = ps->top = 0;
}

// 检测栈是否为空，如果为空返回true，如果不为空false 
bool StackEmpty(ST* ps)
{
    return ps->top == 0;
}
// 入栈
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //栈满了要考虑扩容
    if (ps->capacity == ps->top)
    {
        int NewCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * NewCapacity);
        if (tmp == NULL)
        {
            printf("扩容失败！\n");
            exit(-1);
        }
        //扩容成功
        ps->a = tmp;
        ps->capacity = NewCapacity;
    }
    ps->a[ps->top] = x;
    ps->top++;
}

// 出栈
void StackPop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    ps->top--;
}

// 获取栈顶元素
STDataType StackTop(ST* ps)
{
    assert(ps);
    assert(!StackEmpty(ps));
    return ps->a[ps->top - 1];
}

// 获取栈中有效元素个数
int StackSize(ST* ps)
{
    assert(ps);
    return ps->top;
}

/*
括号匹配分两种，一：类型匹配；二：数量匹配
1. 每个右括号都有一个最近的同类型左括号和其匹配
2. 左括号和右括号的数量相等
如果第一个括号是左括号，入栈；遇到右括号，栈顶括号出栈左括号，匹配；最后栈空返回true，否则返回false
如果第一个括号是右括号，直接返回false
*/
bool isValid(char* s) {
    // 如果第一个括号是右括号，直接返回false
    if (*s == ')' || *s == '}' || *s == ']' || *s == '\0')
        return false;

    ST* st = (ST*)malloc(sizeof(ST));
    StackInit(st);

    while (*s)
    {
        // 左括号入栈
        if (*s == '(' || *s == '{' || *s == '[')
        {
            StackPush(st, *s);
        }

        // 右括号，出左括号匹配（期间栈空返回fasle）
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