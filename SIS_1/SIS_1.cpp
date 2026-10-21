#include <iostream>
using namespace std;

void merge(int arr[], int left, int right, int mid)
{
	int start1 = mid - left + 1;
	int start2 = right - mid;

	int* Left = new int[start1];
	int* Right = new int[start2];

	for (int i = 0; i < start1; i++)
		Left[i] = arr[left + i];
	for (int j = 0; j < start2; j++)
		Right[j] = arr[mid + 1 + j];

	int i = 0, j = 0;
	int k = left;

	while (i < start1 && j < start2)
	{
		if (Left[i] <= Right[j])
		{
			arr[k++] = Left[i++];
		}
		else
		{
			arr[k++] = Right[j++];
		}
	}

	while (i < start1)
	{
		arr[k++] = Left[i++];
	}

	while (j < start2)
	{
		arr[k++] = Right[j++];
	}

	delete Left;
	delete Right;

}

void sort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		sort(arr, left, mid);
		sort(arr, mid + 1, right);

		merge(arr, left, right, mid);
	}
}



int main()
{
	int arr[] = {12, 34, 56, 778, 90, 1, 6, 7, 6, 7, 10, 22};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
	cout << endl;

	sort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	for (int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
	cout << endl;

	return 0;
}

