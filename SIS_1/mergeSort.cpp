#include "sortAlgos.h"
#include <vector>
using namespace std;

long long comparisons = 0;
long long elementCopies = 0;

void merge(vector<int>& arr, int left, int mid, int right)
{
	int start1 = mid - left + 1;
	int start2 = right - mid;

	vector<int> Left(start1), Right(start2);

	for (int i = 0; i < start1; i++)
	{
		Left[i] = arr[left + i];
		elementCopies++;
	}
	
	
	for (int j = 0; j < start2; j++)
	{
		Right[j] = arr[mid + 1 + j];
		elementCopies++;
	}


	int i = 0, j = 0;
	int k = left;

	while (i < start1 && j < start2)
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

	while (i < start1)
	{
		arr[k] = Left[i];
		elementCopies++;
		i++;
		k++;
	}

	while (j < start2)
	{
		arr[k] = Right[j];
		elementCopies++;
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

