#include "DNA.h"
#include "QuickSort.h"
#include <iostream>
using namespace std;

int main() {
    // 第一题测试
    int n, m;
    cin >> n;
    cin >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i].size() != m) {
            cerr << "错误：第 " << i + 1 << " 个字符串长度不是 " << m << "，请重新输入。\n";
            --i;
        }
    }

    insertSort(v, m, n);
    for (const auto& s : v) {
        cout << s << endl;
    }

    // 第二题测试
    const int DATA_SIZE = 1000; 

    cout << "=== 随机数据测试 ===" << endl;
    auto randomData = GenerateRandomData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "教材快速排序", randomData);
    PerformanceTest(QuickSortOptimized, "改进快速排序", randomData);

    cout << "\n=== 相近数据测试 ===" << endl;
    auto nearlySortedData = GenerateNearlySortedData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "教材快速排序", nearlySortedData);
    PerformanceTest(QuickSortOptimized, "改进快速排序", nearlySortedData);

    cout << "\n=== 重复数据测试 ===" << endl;
    auto repeatedData = GenerateRepeatedData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "教材快速排序", repeatedData);
    PerformanceTest(QuickSortOptimized, "改进快速排序", repeatedData);

    return 0;
}
