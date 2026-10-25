#include <iostream>
#include <fstream>
using namespace std;

int main()
{


	ofstream outputfile("data.txt");


	if (!outputfile.is_open())
	{
		cerr << "error! cant open file!!!";
	}

	outputfile << "Hello, World!\n";
	outputfile << "Age: " << 25 << "\n";

	outputfile.close();

	cout << "data was written!!!";
	return 0;

}