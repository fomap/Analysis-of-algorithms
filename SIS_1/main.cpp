#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <iomanip>
#include <iterator>

#include "sortAlgos.h"

using namespace std;

void writeSortedFile(const string& filename, const vector<int>& sorted, 
					const double run[3], double median,
					const string& op1Name, long long op1,
					const string& op2Name, long long op2)
{
	ofstream out(filename);

	if (!out.is_open()) {
		cerr << "Error: Could not open " << filename << endl;
		return;
	}

	out << "runs (ms): " << run[0] << ", " << run[1] << ", " << run[2]
						<< " | median: " << median
						<< " | " << op1Name << ": " << op1
						<< " | " << op2Name << ": " << op2 << "\n";
	
	for (int value : sorted) {
		out << value << "\n";
	}
}


//gets median of the 3 runs
double median(double a, double b, double c)
{
	if ((a <= b && b <= c) || (c <= b && b <= a)) return b;
	if ((b <= a && a <= c) || (c <= a && a <= b)) return a;
	return c;
}


//runs merge sort 3 times on the same input and returns median time. 
double timerMergeSort(const vector<int>& numbers, double run[3], vector<int>& sorted)
{
	for (int attmpt = 0; attmpt < 3; attmpt++) {


		//fresh unsorted copy every run
		vector<int> arr = numbers;

		comparisons = 0;
		elementCopies = 0;

		// starting the count only when sorting is performed. Reading file, copying elements and printing are not included
		auto start = chrono::steady_clock::now();
		mergeSort(arr, 0, (int)arr.size() - 1);
		auto end = chrono::steady_clock::now();

		run[attmpt] = chrono::duration<double, milli>(end - start).count();
		sorted = arr;
	}
	return median(run[0], run[1], run[2]);
}

//runs radix sort 3 times on the same input and returns median time
double timerRadixSort(const vector<int>& numbers, double run[3], vector<int>& sorted)
{
	for (int attmpt = 0; attmpt < 3; attmpt++) {

		//fresh unsorted copy every run
		vector<int> arr = numbers;

		digitInspections = 0;
		elementsPlacements = 0;

		// starting the count only when sorting is performed. Reading file, copying elements and printing are not included
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
	cout << left
		<< setw(10) << "Size"
		<< setw(14) << "Merge (ms)" << setw(14) << "Comparisons" << setw(12) << "Copies"
		<< setw(14) << "Radix (ms)" << setw(14) << "Inspections" << setw(12) << "Placements"
		<< "\n";

	// results.csv 
	ofstream results("results.csv");
	if (!results.is_open()) {
		cerr << "Error: Could not open results.csv" << endl;
		return 1;
	}

	results << "size,"
		<< "merge_run1_ms,merge_run2_ms,merge_run3_ms,merge_median_ms,merge_comparisons,merge_copies,"
		<< "radix_run1_ms,radix_run2_ms,radix_run3_ms,radix_median_ms,radix_digit_inspections,radix_placements\n";


	// same dataset per input size;
	for (int i = 0; i < 5; i++)
	{
		string filename = "data_" + to_string(i) + ".txt";
		ifstream file(filename);

		if (!file.is_open()) {
			cerr << "Error: Could not open the file!" << endl;
			return 1;
		}

		//read values from file and copy to vector
		vector<int> numbers((istream_iterator<int>(file)), istream_iterator<int>());
		file.close();
	

		double mergeTimes[3], radixTimes[3];
		vector<int> mergeSorted, radixSorted;

		//pass the same unordered data to sorting algorithms
		double mergeMs = timerMergeSort(numbers, mergeTimes, mergeSorted);
		double radixMs = timerRadixSort(numbers, radixTimes, radixSorted);


		//has the counter the last run however they are the because same input produces the same counters
		writeSortedFile("mergeSort_" + to_string(i) + ".txt", mergeSorted, mergeTimes, mergeMs,
			"comparisons", comparisons, "copies", elementCopies);
		writeSortedFile("radixSort_" + to_string(i) + ".txt", radixSorted, radixTimes, radixMs,
			"digit inspections", digitInspections, "placements", elementsPlacements);

		//displays the table per input size
		cout << setw(10) << numbers.size()
			<< setw(14) << mergeMs << setw(14) << comparisons << setw(12) << elementCopies
			<< setw(14) << radixMs << setw(14) << digitInspections << setw(12) << elementsPlacements
			<< "\n";

		
		results << numbers.size() << ","
			<< mergeTimes[0] << "," << mergeTimes[1] << "," << mergeTimes[2] << ","
			<< mergeMs << "," << comparisons << "," << elementCopies << ","
			<< radixTimes[0] << "," << radixTimes[1] << "," << radixTimes[2] << ","
			<< radixMs << "," << digitInspections << "," << elementsPlacements << "\n";

	}
	results.close();
	return 0;
}