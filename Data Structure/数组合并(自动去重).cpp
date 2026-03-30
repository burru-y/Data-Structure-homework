#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    vector<int> result;

    // 将第一个数组的元素加入结果
    for (int num : arr1) {
        result.push_back(num);
    }

    // 将第二个数组的元素加入结果
    for (int num : arr2) {
        result.push_back(num);
    }

    // 排序
    sort(result.begin(), result.end());

    // 去重
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;
}



int main() {

    return 0;
}
