#include "QuickSort.h"
#include <random>
#include <chrono>
#include <algorithm>
#include<iostream>
using namespace std;

// 教材的快速排序
void QuickSortOriginal(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && arr[j] >= pivot) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] <= pivot) i++;
            if (i < j) arr[j--] = arr[i];
        }
        arr[i] = pivot;
        QuickSortOriginal(arr, low, i - 1);
        QuickSortOriginal(arr, i + 1, high);
    }
}

// 三数取中法优化
int MedianOfThree(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);
    return mid;
}

void QuickSortOptimized(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot_idx = MedianOfThree(arr, low, high);
        swap(arr[low], arr[pivot_idx]);
        int pivot = arr[low];
        int i = low, j = high;
        while (i < j) {
            while (i < j && arr[j] >= pivot) j--;
            if (i < j) arr[i++] = arr[j];
            while (i < j && arr[i] <= pivot) i++;
            if (i < j) arr[j--] = arr[i];
        }
        arr[i] = pivot;
        QuickSortOptimized(arr, low, i - 1);
        QuickSortOptimized(arr, i + 1, high);
    }
}

// 生成测试数据
vector<int> GenerateRandomData(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, size * 10);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
    return data;
}

vector<int> GenerateNearlySortedData(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = i;
    }
    // 随机交换5%的元素
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, size - 1);
    for (int i = 0; i < size / 20; ++i) {
        int a = dis(gen);
        int b = dis(gen);
        swap(data[a], data[b]);
    }
    return data;
}

vector<int> GenerateRepeatedData(int size) {
    vector<int> data(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    for (int i = 0; i < size; ++i) {
        data[i] = dis(gen);
    }
    return data;
}

// 性能测试函数
void PerformanceTest(void (*sortFunc)(vector<int>&, int, int),const string& sortName,const vector<int>& data) {
    vector<int> testData = data;
    auto start = chrono::high_resolution_clock::now();
    sortFunc(testData, 0, testData.size() - 1);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout << sortName << " time: " << duration.count() << " ms" << endl;

    // 验证排序结果是否正确
    if (!is_sorted(testData.begin(), testData.end())) {
        cerr << "排序失败！" << endl;
    }
}