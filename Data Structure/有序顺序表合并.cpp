#include <stdio.h>
#define MAXSIZE 100  // 顺序表最大容量

// 定义顺序表结构
typedef struct {
    int data[MAXSIZE];
    int length;  // 当前元素个数
} SqList;

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


