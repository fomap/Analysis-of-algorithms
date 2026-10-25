#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <iterator>

#include "sortAlgos.h"

using namespace std;

void writeSortedFile(const string& filename, const vector<int>& sorted, const double run[3], double median)
{
	ofstream out(filename);

	if (!out.is_open()) {
		cerr << "Error: Could not open " << filename << endl;
		return;
	}

	out << "runs (ms): " << run[0] << ", " << run[1] << ", " << run[2] << " | median: " << median << "\n";
	for (int value : sorted) {
		out << value << "\n";
	}
}


void print(vector<int>& arr)
{
	for (const auto& value : arr) {
		cout << value << " ";
	}

	cout << endl;
}

double median(double a, double b, double c)
{
	if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
	if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
	return c;
}

double timerMergeSort(const vector<int>& numbers, double run[3], vector<int>& sorted)
{
	for (int attmpt = 0; attmpt < 3; attmpt++) {
		vector<int> arr = numbers;

		auto start = chrono::steady_clock::now();
		mergeSort(arr, 0, (int)arr.size() - 1);
		auto end = chrono::steady_clock::now();

		run[attmpt] = chrono::duration<double, milli>(end - start).count();
		sorted = arr;
	}
	return median(run[0], run[1], run[2]);
}


double timerRadixSort(const vector<int>& numbers, double run[3], vector<int>& sorted)
{
	for (int attmpt = 0; attmpt < 3; attmpt++) {
		vector<int> arr = numbers;

		auto start = chrono::steady_clock::now();
		radixSort(arr, (int)arr.size());
		auto end = chrono::steady_clock::now();

		run[attmpt] = chrono::duration<double, milli>(end - start).count();
		sorted = arr;
	}
	return median(run[0], run[1], run[2]);
}



int main()
{
	for (int i = 0; i < 5; i++)
	{
		string filename = "data_" + to_string(i) + ".txt";
		ifstream file(filename);

		if (!file.is_open()) {
			cerr << "Error: Could not open the file!" << endl;
			return 1;
		}

		vector<int> numbers((istream_iterator<int>(file)), istream_iterator<int>());
		file.close();
	

		double mergeTimes[3], radixTimes[3];
		vector<int> mergeSorted, radixSorted;

		double mergeMs = timerMergeSort(numbers, mergeTimes, mergeSorted);
		double radixMs = timerRadixSort(numbers, radixTimes, radixSorted);

		writeSortedFile("mergeSort_" + to_string(i) + ".txt", mergeSorted, mergeTimes, mergeMs);
		writeSortedFile("radixSort_" + to_string(i) + ".txt", radixSorted, radixTimes, radixMs);

	
	}

}