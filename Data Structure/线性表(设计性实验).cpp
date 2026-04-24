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

int reserve(sqlist& L) {
	int* n = new int[100];
	for (int i = L.length - 1,j=0;i >= 0;i--,j++) {
		n[j] = L.elem[i];
	}
	delete L.elem;
	L.elem = n;
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


	cout << "转置后的顺序表为:" << endl;
	reserve(l);
	for (i = 0;i < l.length;i++)cout << l.elem[i]<< " ";
}
