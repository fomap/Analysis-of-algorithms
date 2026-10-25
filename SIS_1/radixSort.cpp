#include "sortAlgos.h"
#include <vector>
using namespace std;

long long digitInspections = 0;
long long elementsPlacements =  0;


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

// count sort of arr by one decimal digit
void countSort(vector<int>& arr, int n, int exp)
{
	vector<int> outputArr(n);

	int i, count[10] = { 0 }; 

	for (i = 0; i < n; i++)
	{
		int digit = (arr[i] / exp) % 10;
		digitInspections++;
		count[digit]++;
	}


	for (i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];

	}

	for (i = n - 1; i >= 0; i--)
	{
		int digit = (arr[i] / exp) % 10;
		digitInspections++;
		outputArr[count[digit] - 1] = arr[i];
		elementsPlacements++;
		count[digit]--;
	}

	for (i = 0; i < n; i++)
	{
		arr[i] = outputArr[i];
		elementsPlacements++;
	}

}


//sorting of elements by ones digit, tens, hundreds etc. 
void radixSort(vector<int>& arr, int n)
{
	if (arr.empty()) return; //handling of empty list

	int max = getMax(arr, n);

	//one counting sort pass per digit until exp is largen than the max value; 
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp);
	}
	
}
