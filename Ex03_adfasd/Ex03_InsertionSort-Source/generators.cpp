#include "generators.h"

// Generate arrays of random integers
// Usage: <number_of_arrays> <size_of_array> <output_file>
// Example: 1000 1000 data.txt
int genRandomIntArray(int nArray, int arrSize, char* fileName)
{	
	srand(time(NULL));

	ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		cout << "genIntArray: Error opening output file.";
		return 0;
	}

	for (int i = 0; i < nArray - 1; i++)
	{
		for (int j = 0; j < arrSize - 1; j++)
		{
			outFile << rand() << ' ';
		}
		outFile << rand() << endl;
	}
	
	for (int j = 0; j < arrSize - 1; j++)
	{
		outFile << rand() << ' ';
	}
	outFile << rand();

	outFile.close();

	return 1;
}