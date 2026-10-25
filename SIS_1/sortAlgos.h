#pragma once
#include <vector>

extern long long comparisons;
extern long long elementCopies;

extern long long digitInspections;
extern long long elementsPlacements;

void mergeSort(std::vector<int>& arr, int left, int right);
void radixSort(std::vector<int>& arr, int n);

