#include <iostream>
using namespace std;

#define MAXSIZE 100

struct SqStack {
    char data[MAXSIZE];
    int top;
};

void InitStack(SqStack &S) {
    S.top = -1;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool Push(SqStack &S, char ch) {
    if (S.top == MAXSIZE - 1) return false;
    S.data[++S.top] = ch;
    return true;
}

bool Pop(SqStack &S, char &x) {
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

char GetTop(SqStack S) {
    if (S.top == -1) return '\0';
    return S.data[S.top];
}

bool StatusMatching() {
    // 检验表达式中所含括号是否正确匹配，如果匹配，则返回true，否则返回false
    // 表达式以 "#" 结束
    SqStack S;
    InitStack(S);           // 初始化空栈
    int flag = 1;           // 标记匹配结果以控制循环及返回结果
    char ch;
    cin >> ch;              // 读入第一个字符
    while (ch != '#' && flag) {  // 假设表达式以 "#" 结尾
        switch (ch) {
            case '[':
            case '(':           // 若是左括号，则将其压入栈
                Push(S, ch);
                break;
            case ')':           // 若是 ")"，则根据当前栈顶元素的值分情况考虑
                if (!StackEmpty(S) && GetTop(S) == '(') {
                    char x;
                    Pop(S, x);  // 若栈非空且栈顶元素是 "("，则正确匹配
                } else
                    flag = 0;   // 若栈空或栈顶元素不是 "("，则错误匹配
                break;
            case ']':           // 若是 "]"，则根据当前栈顶元素的值分情况考虑
                if (!StackEmpty(S) && GetTop(S) == '[') {
                    char x;
                    Pop(S, x);  // 若栈非空且栈顶元素是 "["，则正确匹配
                } else
                    flag = 0;   // 若栈空或栈顶元素不是 "["，则错误匹配
                break;
        }
        cin >> ch;              // 继续读入下一个字符
    }
    if (StackEmpty(S) && flag) return true;   // 匹配成功
    else return false;                         // 匹配失败
}

int main() {
    cout << "请输入表达式（以#结尾）：" << endl;
    if (StatusMatching())
        cout << "括号匹配成功！" << endl;
    else
        cout << "括号匹配失败！" << endl;
    return 0;
}
