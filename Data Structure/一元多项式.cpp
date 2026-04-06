#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef struct {
	float coef;
	int expn;
}Polynomial;

typedef struct {
	Polynomial* elem;
	int length;
}SqList;

bool add(SqList&q,float coef,int expn) {
	if (q.length == 100)return false;
	q.elem[q.length].coef = coef;
	q.elem[q.length].expn = expn;
	q.length++;
	return true;
}

bool Init(SqList&q) {
	Polynomial*elem = new Polynomial[MAXSIZE];
	q.elem = elem;
	q.length = 0;
	return true;
}

bool get(int i, SqList& p, float& a, int& b) {
	if (i < 1 || i>100)return false;
	a = p.elem[i - 1].coef;
	b = p.elem[i - 1].expn;
	return true;
}

int main() {
	int n;//多项式项数
    float coef, expn;//每项的系数与指数
	SqList p;
	Init(p);
	cout << "输入项数：" << endl;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cout << "第" << i + 1 << "项系数"<<endl;
		cin >> coef;
		cout << "第" << i + 1 << "项指数"<<endl;
		cin >> expn;
		add(p,coef,expn);
	}
	int x;
	cout << "输入x" << endl;
	cin >> x;
	float sum = 0;
	for (int i = 0;i < n;i++) {
		float a;
		int  b,ad=1;
		get(i + 1, p, a, b);
		for (int j=0;j < b;j++) {
			ad *= x;
		}
		ad *= a;
		sum += ad;
	}
	cout << sum;
}


