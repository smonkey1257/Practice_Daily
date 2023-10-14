#define _CRT_SECURE_NO_WARNINGS 1


struct ListNode {
    int val;
    struct ListNode *next;
};

 /*
     对于传进来的node，没有前驱结点，直接free结点会破坏单链表结构
     因此，采用曲线救国的方式，如下：
         4->5->1->7
     => 4->1->1->7
     我们通过把node变成前驱结点，然后去把node的下一个删除
 */
void deleteNode(struct ListNode* node) {

    // 将node的下一个结点的值拷贝到node结点
    node->val = node->next->val;

    // 保存node->next的位置
    struct ListNode* temp = node->next;

    // 改变连接关系
    node->next = temp->next;

    free(temp);
}