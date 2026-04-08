#include<iostream>
#include<string>
using namespace std;
struct Node {
	string name;
	Node *next;
};
struct queue {
	Node* head = NULL;
	Node* rear = NULL;
};

//添加节点
bool push(queue& p, string s) {
	if (p.head == NULL) {
		Node *temp = new Node;
		temp->name = s;
		temp->next = NULL;
		p.head = temp;
		p.rear = temp;
	}
	else {
		Node* temp = new Node;
		temp->name = s;
		temp->next = NULL;
		p.rear->next = temp;
		p.rear = temp;
	}
	return true;
}

//取队头元素
string front(queue&p) {
	if (p.head == NULL)return "";
	Node* temp = p.head;
	if (p.head->next)p.head = p.head->next;
	else p.head = NULL;
	string s = temp->name;
	delete temp;
	return s;
}

//判断队列是否为空
bool isEmpty(queue& p) {
	if (p.head)return false;
	else return true;
}

int main() {
	//男生队列与女生队列
	queue boy,girl;
	//男生人数与女生人数
	int n, m;
	cout << "请输入男生人数：";
	cin >> n;
	cout << "请输入女生人数：";
	cin >> m;
	//男生姓名
	cout << "请输入所有男生姓名:";
	for (int i = 0;i < n;i++) {
		string s;cin >> s;
		push(boy, s);
	}
	//女生姓名
	cout << "请输入所有女生姓名:";
	for (int i = 0;i < m;i++) {
		string s;cin >> s;
		push(girl, s);
	}
	//舞伴匹配
	while (!isEmpty(boy) && !isEmpty(girl)) {
		//输出舞伴
		cout << front(boy) << " with " << front(girl) << endl;
	}
	//男生有剩余
	if (!isEmpty(boy)) {
		cout << "下次第一个是" << front(boy);
	}
	//女生有剩余
	else if (!isEmpty(girl)) {
		cout << "下次第一个是" << front(girl);
	}

}
