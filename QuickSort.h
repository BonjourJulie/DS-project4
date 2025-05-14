#pragma once
#include <vector>
#include <string>

using namespace std;

void QuickSortOriginal(vector<int>& arr, int low, int high);
void QuickSortOptimized(vector<int>& arr, int low, int high);
vector<int> GenerateRandomData(int size);
vector<int> GenerateNearlySortedData(int size);
vector<int> GenerateRepeatedData(int size);
void PerformanceTest(
    void (*)(vector<int>&, int, int),  // 函数指针类型
    const string&,                     // 排序算法名称
    const vector<int>&                 // 测试数据
);