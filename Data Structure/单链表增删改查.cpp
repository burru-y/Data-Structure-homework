#include <iostream>
using namespace std;

// 1. 定义单链表节点
struct Node
{
    int data;       // 数据
    Node* next;     // 指向下一个节点的指针
};

// 2. 尾插法创建链表
Node* createList(int n)
{
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++)
    {
        // 新建节点
        Node* p = new Node;
        cin >> p->data;
        p->next = NULL;

        if (head == NULL)
        {
            head = p;
            tail = p;
        }
        else
        {
            tail->next = p;
            tail = p;
        }
    }
    return head;
}

// 3. 遍历输出链表
void printList(Node* head)
{
    Node* p = head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// 4. 按值查找节点
void searchNode(Node* head, int x)
{
    Node* p = head;
    int pos = 1;
    while (p != NULL && p->data != x)
    {
        p = p->next;
        pos++;
    }
    if (p == NULL)
        cout << "未找到" << endl;
    else
        cout << "找到了，在第 " << pos << " 个位置" << endl;
}

// 5. 在指定位置插入节点
Node* insertNode(Node* head, int pos, int x)
{
    if (pos < 1)
    {
        cout << "位置无效" << endl;
        return head;
    }

    Node* p = new Node;
    p->data = x;
    p->next = NULL;

    // 插在头部
    if (pos == 1)
    {
        p->next = head;
        head = p;
        return head;
    }

    // 找到第 pos-1 个节点
    Node* q = head;
    int i = 1;
    while (q != NULL && i < pos - 1)
    {
        q = q->next;
        i++;
    }

    if (q == NULL)
    {
        cout << "超出范围" << endl;
        delete p;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
    return head;
}

// 6. 删除指定位置的节点
Node* deleteNode(Node* head, int pos)
{
    if (head == NULL || pos < 1)
    {
        cout << "删除失败" << endl;
        return head;
    }

    Node* p = head;
    // 删除头节点
    if (pos == 1)
    {
        head = head->next;
        delete p;
        return head;
    }

    // 找到第 pos-1 个节点
    Node* q = NULL;
    int i = 1;
    while (p != NULL && i < pos)
    {
        q = p;
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        cout << "超出范围" << endl;
    }
    else
    {
        q->next = p->next;
        delete p;
    }
    return head;
}

int main()
{
    int n, x, pos;
    cout << "输入节点个数：";
    cin >> n;

    cout << "输入 " << n << " 个数字：";
    Node* head = createList(n);

    cout << "链表：";
    printList(head);

    // 查找
    cout << "输入要查找的值：";
    cin >> x;
    searchNode(head, x);

    // 插入
    cout << "输入插入位置和值：";
    cin >> pos >> x;
    head = insertNode(head, pos, x);
    printList(head);

    // 删除
    cout << "输入要删除的位置：";
    cin >> pos;
    head = deleteNode(head, pos);
    printList(head);

    return 0;
}
