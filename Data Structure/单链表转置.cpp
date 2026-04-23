#include<iostream>
using namespace std;

/*
单链表逆置
*/

//单链表节点
typedef struct LNode {
	int data;
	LNode* next;
}LNode;

//单链表头节点初始化
void init(LNode * l) {
	l->data = 0;
	l->next = NULL;
}

//单链表结点插入
void insert(LNode * l,int a) {
	LNode* temp = l;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	LNode* newl = new LNode;
	newl->data = a;
	newl->next = NULL;
	temp->next = newl;
}

//单链表逆置
void reserve(LNode * l) {
	LNode* temp1 = l->next;
	LNode* temp2 = temp1->next;
	LNode* nex = temp2->next;	
	while (nex!=NULL) {
		temp2->next = temp1;
		temp1 = temp2;
		temp2 = nex;
		nex = nex->next;
	}
	temp2->next = temp1;
	l->next->next = NULL;
	l->next = temp2;
}

void print(LNode * l) {
	LNode* p = l->next;
	while (p != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
int main(){
	int m, n;
	LNode* head=new LNode;
	init(head);
	cout << "请输入链表元素个数";
	cin >> m;
	cout << "请输入"<<m<<"个元素";
	for (int i = 0;i < m;i++) {
		cin >> n;
		insert(head,n);
	}
	cout << "转置前：";
	print(head);
	cout << endl;
	reserve(head);
	cout << "转置后：";
	print(head);
	cout << endl;
}
