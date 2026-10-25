#include "sortAlgos.h"
#include <iostream>
#include <vector>
using namespace std;



int getMax(vector<int>& arr, int n)
{
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}


void countSort(vector<int>& arr, int n, int exp)
{
	vector<int> outputArr(n);

	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
	{
		count[(arr[i] / exp) % 10]++;
	}


	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];

	}



	for (i = n - 1; i >= 0; i--)
	{
		outputArr[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = outputArr[i];
	}

}


void radixSort(vector<int>& arr, int n)
{
	if (arr.empty()) return;

	int max = getMax(arr, n);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp);
	}
	
}

//int main()
//{
//	vector<int> arr = { };
//	int n = arr.size();
//
//	cout << "Given array is \n";
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	radixSort(arr, n);
//
//
//	cout << "Output array is \n";
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//
//}
