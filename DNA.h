#pragma once
#include <vector>
#include <string>

using namespace std;

int mergeAndCount(string& s, int left, int mid, int right, string& temp);
int count(string& s, int low, int high, string& temp);
void insertSort(vector<string>& v, int& m, const int n);
void test01();
