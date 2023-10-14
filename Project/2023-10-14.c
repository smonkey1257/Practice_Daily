#define _CRT_SECURE_NO_WARNINGS 1


struct ListNode {
    int val;
    struct ListNode *next;
};

 /*
     ���ڴ�������node��û��ǰ����㣬ֱ��free�����ƻ�������ṹ
     ��ˣ��������߾ȹ��ķ�ʽ�����£�
         4->5->1->7
     => 4->1->1->7
     ����ͨ����node���ǰ����㣬Ȼ��ȥ��node����һ��ɾ��
 */
void deleteNode(struct ListNode* node) {

    // ��node����һ������ֵ������node���
    node->val = node->next->val;

    // ����node->next��λ��
    struct ListNode* temp = node->next;

    // �ı����ӹ�ϵ
    node->next = temp->next;

    free(temp);
}