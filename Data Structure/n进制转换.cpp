#include<iostream>
using namespace std;

// 先声明指针类型，解决循环定义问题
struct stack;
typedef stack* stackPtr;

// 栈节点
struct stack {
	int data;
	stackPtr next;
	// 构造函数初始化 next 为空
	stack() { next = NULL; }
};

// 链栈（带头节点）
typedef struct {
	stackPtr front;
}Linkstack;

// 初始化
bool Initstack(Linkstack& p) {
	p.front = new stack;
	p.front->next = NULL;
	return true;
}

// 入栈
bool put(Linkstack& p, int e) {
	stackPtr s = new stack;
	s->data = e;
	s->next = p.front->next;
	p.front->next = s;
	return true;
}

// 出栈：返回栈顶元素
int get(Linkstack& p) {
	if (p.front->next == NULL) return -1;
	stackPtr temp = p.front->next;
	int re = temp->data;
	p.front->next = temp->next;
	delete temp;  // 释放节点，防止内存泄漏
	return re;
}

// 判断栈是否为空
bool empty(Linkstack& p) {
	// 空返回 true，非空返回 false
	return p.front->next == NULL;
}

// 数制转换
void zh() {
	Linkstack p;
	Initstack(p);
	int a, n; cin >> a >> n;

	// 入栈
	while (a / n != 0) {
		put(p, a % n);
		a /= n;
	}
	put(p, a);

	// 出栈输出
	while (!empty(p)) {
		cout << get(p) << '/';
	}
}

int main() {
	zh();
}