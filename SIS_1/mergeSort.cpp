#include "sortAlgos.h"
#include <vector>
using namespace std;

long long comparisons = 0;
long long elementCopies = 0;

// merges alredy sorted halves int one sorted range
void merge(vector<int>& arr, int left, int mid, int right)
{
	int s1 = mid - left + 1;
	int s2 = right - mid;

	vector<int> Left(s1), Right(s2);

	for (int i = 0; i < s1; i++)
	{
		Left[i] = arr[left + i];
		elementCopies++;
	}
	
	
	for (int j = 0; j < s2; j++)
	{
		Right[j] = arr[mid + 1 + j];
		elementCopies++;
	}


	int i = 0, j = 0;
	int k = left;

	while (i < s1 && j < s2)
	{
		comparisons++;

		if(Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			elementCopies++;
			i++;
		}
		else
		{
			arr[k] = Right[j];
			elementCopies++;
			j++;
		}
		k++;
	}

	while (i < s1)
	{
		arr[k] = Left[i];
		elementCopies++;
		i++;
		k++;
	}

	while (j < s2)
	{
		arr[k] = Right[j];
		elementCopies++;
		j++;
		k++;
	}
}


void mergeSort(vector<int>& arr, int left, int right)
{
	// base case: 0 and 1 elements in arr are already sorted 
	if (left >= right)
	{
		return;
	}

	// unlike (left + right) / 2, this version avoids interger overflow 
	int mid = left + (right - left) / 2;

	// sort each half recursively and then merge sorted halves
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
}

