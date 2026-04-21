#include <iostream>
using namespace std;

// 定义多项式的节点结构
typedef struct PolyNode {
    float coef;             // 系数
    int expn;               // 指数
    struct PolyNode* next;  // 指向下一个节点的指针
} PolyNode, * Polynomial;

// 初始化多项式
// 创建一个带头结点的空链表
void InitList(Polynomial& P) {
    P = new PolyNode; // C++ 使用 new
    P->next = NULL;
}

void InsertTerm(Polynomial& P, float coef, int expn) {
    PolyNode* pre = P; // pre指向头结点
    PolyNode* cur = P->next; // cur指向首元结点

    // 寻找插入位置：找到第一个指数大于当前expn的节点
    while (cur && cur->expn < expn) {
        pre = cur;
        cur = cur->next;
    }

    // 找到了相同指数的项 (合并同类项)
    if (cur && cur->expn == expn) {
        cur->coef += coef;
        // 如果系数相加后为0，则需要删除该节点
        if (cur->coef == 0) {
            pre->next = cur->next;
            delete cur; // C++ 使用 delete
        }
    }
    // 没找到相同指数，或者到了表尾，需要插入新节点
    else {
        if (coef != 0) {
            PolyNode* s = new PolyNode; // C++ 使用 new
            s->coef = coef;
            s->expn = expn;
            s->next = cur; // 新节点指向原来的后继
            pre->next = s; // 前驱指向新节点
        }
    }
}

/*
 * 创建多项式
 */
void CreatePolyn(Polynomial& P, int m) {
    InitList(P);
    cout << "请输入 " << m << " 项的系数和指数 (例如: 3 2 代表 3x^2):" << endl;
    for (int i = 0; i < m; i++) {
        float c;
        int e;
        cin >> c >> e;
        InsertTerm(P, c, e);
    }
}

/**
 * 多项式相加: Pc = Pa + Pb
 */
void AddPolyn(Polynomial& Pa, Polynomial& Pb, Polynomial& Pc) {
    InitList(Pc);

    PolyNode* ha = Pa->next; // ha指向Pa的首元结点
    PolyNode* hb = Pb->next; // hb指向Pb的首元结点
    PolyNode* hc = Pc;       // hc始终指向Pc的尾结点 (尾插法)

    while (ha && hb) {
        // 比较指数
        if (ha->expn < hb->expn) {
            // Pa的指数小，将Ha节点复制一份接到Pc后面
            PolyNode* s = new PolyNode;
            s->coef = ha->coef;
            s->expn = ha->expn;
            s->next = NULL;
            hc->next = s;
            hc = s;
            ha = ha->next;
        }
        else if (ha->expn > hb->expn) {
            // Pb的指数小，将Hb节点复制一份接到Pc后面
            PolyNode* s = new PolyNode;
            s->coef = hb->coef;
            s->expn = hb->expn;
            s->next = NULL;
            hc->next = s;
            hc = s;
            hb = hb->next;
        }
        else {
            // 指数相同，系数相加
            float sum = ha->coef + hb->coef;
            if (sum != 0) {
                PolyNode* s = new PolyNode;
                s->coef = sum;
                s->expn = ha->expn;
                s->next = NULL;
                hc->next = s;
                hc = s;
            }
            // 无论系数和是否为0，pa和pb的当前节点都向后移
            ha = ha->next;
            hb = hb->next;
        }
    }

    // 将剩余的节点接在Pc后面
    while (ha) {
        PolyNode* s = new PolyNode;
        s->coef = ha->coef;
        s->expn = ha->expn;
        s->next = NULL;
        hc->next = s;
        hc = s;
        ha = ha->next;
    }
    while (hb) {
        PolyNode* s = new PolyNode;
        s->coef = hb->coef;
        s->expn = hb->expn;
        s->next = NULL;
        hc->next = s;
        hc = s;
        hb = hb->next;
    }
}

/**
 * 打印多项式
 */
void PrintPolyn(Polynomial P) {
    PolyNode* p = P->next;
    if (!p) {
        cout << 0 << endl;
        return;
    }

    int first = 1;
    while (p) {
        // 处理符号
        if (p->coef > 0 && !first) cout << "+";

            cout << p->coef;
        

        // 处理指数
        if (p->expn > 1) {
            cout << "x^";
            cout << p->expn;
        }
        else if (p->expn == 1) {
            cout << "x";
        }
  

        p = p->next;
        first = 0;
    }
    cout << endl; // printf("\n") 改为 cout << endl
}


void DestroyPolyn(Polynomial& P) {
    PolyNode* q;
    while (P) {
        q = P->next;
        delete P; // C++ 使用 delete
        P = q;
    }
}

int main() {
    Polynomial Pa, Pb, Pc;
    int m, n;

    cout << "请输入多项式A的项数: ";
    cin >> m;
    CreatePolyn(Pa, m);

    cout << "请输入多项式B的项数: ";
    cin >> n;
    CreatePolyn(Pb, n);

    cout << "\n多项式 A: ";
    PrintPolyn(Pa);
    cout << "多项式 B: ";
    PrintPolyn(Pb);

    AddPolyn(Pa, Pb, Pc);

    cout << "结果 A+B: ";
    PrintPolyn(Pc);

    DestroyPolyn(Pa);
    DestroyPolyn(Pb);
    DestroyPolyn(Pc);

    return 0;
}
