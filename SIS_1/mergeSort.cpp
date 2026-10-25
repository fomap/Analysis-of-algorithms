#include "sortAlgos.h"
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
	int start1 = mid - left + 1;
	int start2 = right - mid;

	vector<int> Left(start1), Right(start2);

	for (int i = 0; i < start1; i++)
	{
		Left[i] = arr[left + i];
	}
	
	
	for (int j = 0; j < start2; j++)
	{
		Right[j] = arr[mid + 1 + j];
	}


	int i = 0, j = 0;
	int k = left;

	while (i < start1 && j < start2)
	{
		if(Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			i++;
		}
		else
		{
			arr[k] = Right[j];
			j++;
		}
		k++;
	}

	while (i < start1)
	{
		arr[k] = Left[i];
		i++;
		k++;
	}

	while (j < start2)
	{
		arr[k] = Right[j];
		j++;
		k++;
	}
}


void mergeSort(vector<int>& arr, int left, int right)
{
	if (left >= right)
	{
		return;
	}

	int mid = left + (right - left) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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
//	mergeSort(arr, 0, n - 1);;
//
//	cout << "Output array is \n";
//	for (int i = 0; i < n; i++)
//		cout << arr[i] << " ";
//	cout << endl;
//
//	return 0;
//}