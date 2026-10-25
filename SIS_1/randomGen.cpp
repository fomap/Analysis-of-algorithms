#include <iostream>
#include <fstream>
#include <random>
#include <string>
using namespace std;

int main()
{
	int recordNum = 5;

	unsigned int seed = 67;
	mt19937 rng(seed);

	int randSize[] = { 1000, 5000, 10000, 50000, 100000 };

	uniform_int_distribution<int> dist(0, 9999999);

	for (int i = 0; i < 5; i++)
	{

		string filename = "data_" + to_string(i) + ".txt";

		ofstream outputfile(filename);

		if (outputfile.is_open()) {

			for (int j = 0; j < randSize[i]; j++)
			{
				outputfile << dist(rng) << endl;
			}
			outputfile.close();
		}
		else 
		{
			cerr << "Error opening file!" << endl;
		}
	}

	cout << "data was written!!!" << endl;
	return 0;

}