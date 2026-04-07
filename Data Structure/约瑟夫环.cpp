#include<iostream>
using namespace std;

struct node;

//循环链表节点
typedef struct node {
	node* next;
	node* prior;
	int index;
} node;

//循环链表头节点
typedef struct {
	node* head;
	int length;
} linkedlist;

//初始化循环链表；
bool init(linkedlist& p) {
	p.head = new node;
	p.head->next = p.head;
	p.head->prior = p.head;
	p.head->index = -1;
	p.length = 0;
	return true;
}

//添加节点
bool add(linkedlist& p,int e) {
	node* a = p.head;
	while (a->next != p.head) {
		a = a->next;
	}
	node* ad = new node;
	ad->index = e;
	ad->next = a->next;
	ad->next->prior = ad;
	a->next = ad;
	ad->prior = a;
	p.length++ ;
	return true;
}

//从 cur 开始数 m 个，删除该节点，cur 更新为下一个数据节点
bool remove(linkedlist& p, node*& cur, int m) {
	if (p.length <= 1) return false;

	// 从 cur 开始走 m-1 步，跳过 head
	for (int i = 1; i < m; i++) {
		cur = cur->next;
		if (cur == p.head)
			cur = cur->next;
	}

	node* del = cur;
	// 下一轮的起点
	cur = del->next;
	if (cur == p.head)
		cur = cur->next;

	// 删除
	del->prior->next = del->next;
	del->next->prior = del->prior;
	delete del;
	p.length--;
	return true;
}


//判断还剩几个节点
int size(linkedlist&p) {
	
	return p.length;
}

int main() {
	linkedlist p;
	init(p);
	int n,m;
	cout << "请输入人数：" << endl;
	cin >> n;
	cout << "kill第几个人：" << endl;
	cin >> m;
	for (int i = 1;i <= n;i++) {
		add(p,i);
	}
	node* cur = p.head->next;
	while (size(p) != 1) {
		remove(p, cur, m);
	}
	cout << p.head->next->index;
}
