#include <iostream>
#include <vector>
using namespace std;



int getMax(int arr[], int n)
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


void countSort(int arr[], int n, int exp)
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


void radixSort(int arr[], int n)
{
	int max = getMax(arr, n);

	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(arr, n, exp);
	}
	
}

int main()
{
	int arr[] = { 12, 34, 56, 778, 90, 1, 6, 7, 6, 7, 10, 22, 1000 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	radixSort(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;

}
