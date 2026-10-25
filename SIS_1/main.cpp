#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>

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
	ifstream file("data_0.txt");


	// make vector<int> arr from gen data;
	if (!file.is_open()) {
		cerr << "Error: Could not open the file!" << endl;
		return 1;
	}
	vector<int> numbers((istream_iterator<int>(file)), istream_iterator<int>());
	file.close();



	ofstream mergeSortFile("mergeSort_0.txt");

	if (!mergeSortFile.is_open()) {
		cerr << "Error: Could not open the mergeSortFile!" << endl;
		return 1;
	}
	
	vector<int> arr1 = numbers;
	
	mergeSort(arr1, 0, (int)arr1.size() - 1);

	for (int value : arr1) {
		mergeSortFile << value << "\n";
	}
	mergeSortFile.close();



	ofstream radixSortFile("radixSort_0.txt");

	if (!radixSortFile.is_open()) {
		cerr << "Error: Could not open the radixSortFile!" << endl;
		return 1;
	}

	vector<int> arr2 = numbers;

	mergeSort(arr2, 0, (int)arr2.size() - 1);

	for (int value : arr2) {
		radixSortFile << value << "\n";
	}
	radixSortFile.close();

}