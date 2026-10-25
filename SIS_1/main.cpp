#include <iostream>
#include <vector>
#include "sortAlgos.h"
using namespace std;


void print(vector<int>& arr)
{
	for (const auto& value : arr) {
		cout << value << " ";
	}

	cout << endl;
}


int main()
{
	vector<int> arr1 = {10101 , 99, 21, 17, 4 , 0};
	vector<int> arr2 = arr1;

	cout << "Given array is \n";
	print(arr1);

	mergeSort(arr1, 0, arr1.size() - 1);
	radixSort(arr2, arr2.size());

	cout << "Merge sort \n";
	print(arr1);


	cout << "Radix sort \n";
	print(arr2);


}