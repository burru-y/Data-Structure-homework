#include <iostream>
#include<algorithm>
using namespace std;
#define MAXSIZE 200

typedef struct {
    int data[MAXSIZE];
    int length;  // 当前元素个数
} Set;
bool init(Set& p) {
    p.length = 0;
    return true;
}

bool push(Set& p, int t) {

    if (p.length == MAXSIZE)return false;

    p.data[p.length] = t;

    p.length += 1;
    return true;
}


bool fd(Set L,int a) {
    for (int i = 0;i < L.length;i++) {
        if (L.data[i] == a)return false;
    }
    return true;
}

// 合并两个集合 LA LB
void MergeSqList(Set LA, Set LB, Set* LC) {
    for (int i = 0; i < LA.length; i++) {
        push(*LC, LA.data[i]);
    }
    for (int i = 0;i < LB.length;i++) {
        if (fd(LA, LB.data[i])) {
            push(*LC,LB.data[i]);
        }
    }
}

void print(Set* p) {
    for (int i = 0;i < p->length;i++) {
        cout << p->data[i] << " ";
    }
    cout << endl;
}

int main() {
    Set a, b;int m, n;
    init(a);
    init(b);
    cout << "请输入a,b集合元素个数" << endl;
    while (true) {

        cin >> m >> n;
        if (m + n > MAXSIZE)cout << "元素过多，请重新输入";
        else break;
    }
    cout << "请输入a,b集合元素" << endl;
    for (int i = 0;i < m;i++) {
        int t;cin >> t;
        push(a, t);
    }
    for (int i = 0;i < n;i++) {
        int t;cin >> t;
        push(b, t);
    }
    Set* c = new Set;
    init(*c);
    MergeSqList(a, b, c);
    cout << "合并后的集合为：";
    print(c);
    sort(c->data, c->data + c->length );
    cout << "排序后的集合为：";
    print(c);
    return 0;
}
