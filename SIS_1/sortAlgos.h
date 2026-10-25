#pragma once
#include <vector>

// Merge sort
extern long long comparisons; // key comparisons: Left[i] <= Right[i]
extern long long elementCopies; // element writes into Left/Right + back into arr

// Radix sort
extern long long digitInspections; // digit extraction (value / exp) % 10
extern long long elementsPlacements; // writes into outputArr + the copy back into arr

void mergeSort(std::vector<int>& arr, int left, int right);
void radixSort(std::vector<int>& arr, int n);

