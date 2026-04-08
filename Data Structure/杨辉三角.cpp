#include <iostream>
#include <vector>
using namespace std;


// 队列节点：存储一行数据
struct Node {
    vector<int> data;
    Node* next;
};

// 队头、队尾指针
Node* front = NULL;
Node* rear = NULL;

// 入队
void push(vector<int> val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

    if (front == NULL) {  // 空队列
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

// 出队
void pop() {
    if (front == NULL) return;
    Node* temp = front;
    front = front->next;
    delete temp;
    if (front == NULL) rear = NULL;
}

// 获取队头元素
vector<int> getFront() {
    return front->data;
}

// 判断队列是否为空
bool isEmpty() {
    return front == NULL;
}

// 实现杨辉三角
void yanghui(int n) {
    // 第一行入队
    push({1});

    for (int i = 0; i < n; i++) {
        // 取出队头
        vector<int> prev = getFront();
        pop();

        // 打印当前行
        for (int num : prev) {
            cout << num << " ";
        }
        cout << endl;

        // 生成新行
        vector<int> curr;
        curr.push_back(1);
        for (int j = 1; j < prev.size(); j++) {
            curr.push_back(prev[j-1] + prev[j]);
        }
        curr.push_back(1);

        // 新行入队
        push(curr);
    }
}

int main() {
    int rows;
    cout << "请输入杨辉三角行数：";
    cin >> rows;
    yanghui(rows);
    return 0;
}
