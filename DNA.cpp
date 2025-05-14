#pragma once
#include "DNA.h"
#include<iostream>
#include<vector>
#include<string>

using namespace std;

// 计算逆序数的归并排序
int mergeAndCount(string& s, int left, int mid, int right, string& temp) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;

    while (i <= mid && j <= right) {
        if (s[i] <= s[j]) {
            temp[k++] = s[i++];
        }
        else {
            temp[k++] = s[j++];
            invCount += (mid - i + 1);
        }
    }
    while (i <= mid) temp[k++] = s[i++];
    while (j <= right) temp[k++] = s[j++];

    for (int l = left; l <= right; ++l) s[l] = temp[l];

    return invCount;
}

int count(string& s, int low, int high, string& temp) {
    int invCount = 0, n = s.size();

    if (low < high) {
        int mid = (low + high) / 2;
        invCount += count(s, low, mid, temp);
        invCount += count(s, mid + 1, high, temp);
        invCount += mergeAndCount(s, low, mid, high, temp);
    }
    return invCount;
}

void insertSort(vector<string>& v, int& m, const int n) {
    string s(m, '\0');
    vector<int> countList(n);
    vector<string> vtmp = v;

    for (int i = 0; i < n; i++) {
        countList[i] = count(vtmp[i], 0, m - 1, s);
    }
    for (int i = 1; i < n; i++) {
        if (countList[i] <= countList[i - 1]) {
            string temp = v[i];
            int countTemp = countList[i];
            int j = i - 1;
            while (j >= 0 && (countList[j] > countTemp || (countList[j] == countTemp && v[j] < temp))) {
                v[j + 1] = v[j];
                countList[j + 1] = countList[j];
                j--;
            }
            v[j + 1] = temp;
            countList[j + 1] = countTemp;
        }


    }

}

void test01() {
    int n = 6, m = 10;
    vector<string> v = { "AACATTAAGG","TTTGGCCAAA","GATCAGATTT","CCCGGGGGGA","ATCGATGCAT" ,"TTTTGGCCAA" };
    insertSort(v, m, n);
    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }

}
