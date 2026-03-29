#include <iostream>
typedef struct LNode {
	int data;
	struct LNode* next;
}LNode,*LinkList;



LinkList merge(LinkList& a, LinkList& b) {
    // 创建新链表的头结点
    LinkList L = new LNode;
    L->next = NULL;

    // p 遍历 a，q 遍历 b，r 指向新链表末尾
    LinkList p = a->next, q = b->next, r = L;

    // 同时遍历两个链表，按大小合并
    while (p != NULL && q != NULL) {
        if (p->data <= q->data) {
            r->next = p;   // 直接链上节点，不复制
            p = p->next;
        }
        else {
            r->next = q;
            q = q->next;
        }
        r = r->next;       // 尾指针后移
    }

    // 处理剩余节点
    if (p != NULL) r->next = p;
    if (q != NULL) r->next = q;

    return L;
}



int main()
{
   
}

