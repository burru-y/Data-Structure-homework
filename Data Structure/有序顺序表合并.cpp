#include <iostream>
#define MAXSIZE 100  // 顺序表最大容量
using namespace std;
// 定义顺序表结构
typedef struct {
    int data[MAXSIZE];
    int length;  // 当前元素个数
} SqList;
bool init(SqList&p) {
    p.length = 0;
    return true;
}

bool push(SqList& p,int t) {
  
    if (p.length == MAXSIZE)return false;
  
        p.data[p.length] = t;
  
    p.length += 1;
    return true; 
}


// 合并两个递增有序顺序表 LA、LB 到 LC，LC 依然递增有序
void MergeSqList(SqList LA, SqList LB, SqList* LC) {
    int i = 0, j = 0, k = 0;

    // 双指针遍历，取较小元素
    while (i < LA.length && j < LB.length) {
        if (LA.data[i] <= LB.data[j]) {
            LC->data[k++] = LA.data[i++];
        }
        else {
            LC->data[k++] = LB.data[j++];
        }
    }

    // 处理 LA 剩余元素
    while (i < LA.length) {
        LC->data[k++] = LA.data[i++];
    }

    // 处理 LB 剩余元素
    while (j < LB.length) {
        LC->data[k++] = LB.data[j++];
    }

    LC->length = k;  // 更新长度
}

void print(SqList*p){
    for (int i = 0;i < p->length;i++) {
        cout << p->data[i] << " ";
}
    cout << endl;
}

int main() {
    SqList a, b;int m, n;
    init(a);
    init(b);
    cout << "请输入a,b有序顺序表元素个数" << endl;
    while (true) {
       
        cin >> m >> n;
        if (m + n > MAXSIZE)cout << "元素过多，请重新输入";
        else break;
    }
    cout << "请输入a,b有序顺序表元素" << endl;
    for (int i = 0;i < m;i++) {
        int t;cin >> t;
        push(a, t);
    }
    for (int i = 0;i < n;i++) {
        int t;cin >> t;
        push(b, t);
    }
    SqList *c=new SqList;
    init(*c);
    MergeSqList(a, b, c);
    cout << "合并后的有序表为：";
    print(c);
    return 0;
}


