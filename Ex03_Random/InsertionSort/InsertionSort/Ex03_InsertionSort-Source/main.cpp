#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "generators.h"
#include "file_readers.h"
#include "algorithms.h"
#include "file_getter.h"
using namespace std;

void run(istream& in, ostream& out, int& countAssign, int& countCompare)
{
	while (in.good())	// get every data piece
	{
		// reset count results
		countAssign = 0;
		countCompare = 0;
		
		// get one piece of data
		// CHANGE HERE TO YOUR READER
		vector<int> arr = readIntArray(in);
		
		// run algorithm once on a piece of data
		// CHANGE HERE TO YOUR ALGORITHM
		insertion_sort(arr, countAssign, countCompare);
		
		// save count results
		out << countAssign << "\t" << countCompare << endl;	
	}
}


int main(int argc, char* argv[])
{

	if (argc != 6)
	{
		cout << "Usage: run.exe <number_of_data> <data_size> <data_file> <output_file> <type>" << endl;
		cout << "Example: run.exe 1000 1000 data.txt result.txt 1" << endl;
		cout << "Type: 1 (best case), 2 (worst case), 3 (average case)" << endl;
		return 0;
	}
	
	// get data sizes
	int n, m;
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	
	// generate data
	// CHANGE HERE TO YOUR DATA GENERATOR
	// COMMENT IF YOU ALREADY HAVE DATA
	if (strcmp(argv[5], "1") == 0)
	{
		bestCase(m, n, argv[3]);
	}
	else
		if (strcmp(argv[5], "2") == 0)
		{
			worstCase(m, n, argv[3]);
		}
		else
		{
			averageCase(m, n, argv[3]);
		}
	
	ifstream inFile(argv[3]);
	ofstream outFile(argv[4]);
	// open files
	if (!inFile.is_open() || !outFile.is_open())
	{
		cout << "run: Error opening files" << endl;
		return 1;
	}
	
	int countAssign, countCompare;
	// run algorithm and count
	run(inFile, outFile, countAssign, countCompare);
	
	// close files
	inFile.close();
	outFile.close();

	return 0;
}