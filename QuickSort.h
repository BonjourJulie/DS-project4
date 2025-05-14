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
    void (*)(vector<int>&, int, int),  // ����ָ������
    const string&,                     // �����㷨����
    const vector<int>&                 // ��������
);