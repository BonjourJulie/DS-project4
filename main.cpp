#include "DNA.h"
#include "QuickSort.h"
#include <iostream>
using namespace std;

int main() {
    // ��һ�����
    int n, m;
    cin >> n;
    cin >> m;

    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i].size() != m) {
            cerr << "���󣺵� " << i + 1 << " ���ַ������Ȳ��� " << m << "�����������롣\n";
            --i;
        }
    }

    insertSort(v, m, n);
    for (const auto& s : v) {
        cout << s << endl;
    }

    // �ڶ������
    const int DATA_SIZE = 1000; 

    cout << "=== ������ݲ��� ===" << endl;
    auto randomData = GenerateRandomData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "�̲Ŀ�������", randomData);
    PerformanceTest(QuickSortOptimized, "�Ľ���������", randomData);

    cout << "\n=== ������ݲ��� ===" << endl;
    auto nearlySortedData = GenerateNearlySortedData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "�̲Ŀ�������", nearlySortedData);
    PerformanceTest(QuickSortOptimized, "�Ľ���������", nearlySortedData);

    cout << "\n=== �ظ����ݲ��� ===" << endl;
    auto repeatedData = GenerateRepeatedData(DATA_SIZE);
    PerformanceTest(QuickSortOriginal, "�̲Ŀ�������", repeatedData);
    PerformanceTest(QuickSortOptimized, "�Ľ���������", repeatedData);

    return 0;
}
