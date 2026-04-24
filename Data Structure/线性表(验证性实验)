#include<iostream>
using namespace std;
typedef struct {
	int* elem;
	int length;
	int listsize;
}sqlist;

int init_List(sqlist& L) {
	L.elem = new int[100];
	if (!L.elem)return 0;
	else
	{
		L.length = 0;
		L.listsize = 100;
		return 1;
	}
}

int list_insert(sqlist&L,int i,int e) {
	if (i > L.length || L.length == L.listsize)return 0;
	for (int j = L.length;j >= i;j--) {
		L.elem[j] = L.elem[j-1];
	}
	L.elem[i-1] = e;
	L.length++;
	return 1;
}

int list_delete(sqlist& L, int i) {
	int* p, * q;
	if ((i < 1) || i > (L.length))return 0;
	for (int j = i;j < L.length;j++) {
		L.elem[j-1] = L.elem[j];
	}
	L.length--;
	return 1;
}

int main() {
	sqlist l;
	int* p;int a;int e;int b;
	int i;
	if (!init_List(l)) {
		cout << "内存分配失败" << endl;
		exit(0);
	}
	else
		p = l.elem;
	cout << "输入顺序表的长度l.length的值：" << endl;
	cin >> l.length;
	cout << "输入" << l.length << "个数：" << endl;
	for (i = 0;i < l.length;i++)cin >> *p++;
	cout << "创建的顺序表为：" << endl;
	for (i = 0;i < l.length;i++)cout << l.elem[i]<< " ";
	cout << endl;

	cout << "输入要插入的位置：" << endl;
	cin >> a;
	cout << "输入要插入的数："<<endl;
	cin >> e;
	list_insert(l, a, e);
	cout << "插入后的顺序表为："<<endl;
	for (i = 0;i < l.length;i++)cout << l.elem[i] << " ";
	cout << endl;

	cout << "输入要删除的位置:" << endl;
	cin >> b;
	list_delete(l,b);
	cout << "删除后的顺序表为:" << endl;
	for (i = 0;i < l.length;i++)cout << l.elem[i]<< " ";
}
