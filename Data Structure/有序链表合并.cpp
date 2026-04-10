#include <iostream>
using namespace std;

// 单链表结点定义
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode, * LinkList;

void CreateList(LinkList& L) {
    L = new LNode;   // 创建头结点
    L->next = NULL;
    LNode* r = L;    // 尾指针

    int n;
    cout << "请输入元素个数：";
    cin >> n;
    cout << "请输入" << n << "个递增的整数：";
    for (int i = 0; i < n; i++) {
        LNode* s = new LNode;
        cin >> s->data;
        s->next = NULL;
        r->next = s;
        r = s;
    }
}


void PrintList(LinkList L) {
    LNode* p = L->next;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


LinkList merge(LinkList& a, LinkList& b) {
    // 创建新链表头结点
    LinkList L = new LNode;
    L->next = NULL;

    // p 遍历a，q遍历b，r指向新链表末尾
    LNode* p = a->next, * q = b->next, * r = L;

    // 按大小合并
    while (p && q) {
        if (p->data <= q->data) {
            r->next = p;
            p = p->next;
        }
        else {
            r->next = q;
            q = q->next;
        }
        r = r->next;
    }

    // 接上剩余部分
    r->next = p ? p : q;

    return L;
}

int main() {
    LinkList A, B, C;

    cout << "创建有序链表 A：" << endl;
    CreateList(A);
    cout << "A：";
    PrintList(A);

    cout << "创建有序链表 B：" << endl;
    CreateList(B);
    cout << "B：";
    PrintList(B);

    // 合并
    C = merge(A, B);
    cout << "合并后的有序链表 C：";
    PrintList(C);

    return 0;
}
