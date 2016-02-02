#include "generators.h"
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
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

bool cmp(int x, int y)
{
	return x > y;
}
void getRanVec(vector<int>& a, int n, bool increase, bool strictOrder)
{
	
	a.resize(n);
	a[0] = rand();
	for (int i = 1; i < a.size(); ++i)
		a[i] = a[i-1] + rand() + int(strictOrder);
	if (!increase)
		reverse(a.begin(), a.end());
	
}
int genOrderedIntArray(int nArray, int arrSize, char* fileName, bool increase)
{
	srand(time(0));
	ofstream outFile(fileName);
	if (!outFile.is_open())
	{
		cout << "genIntArray: Error opening output file.";
		return 0;
	}

	vector<int> a;
	for (int i = 0; i < nArray - 1; i++)
	{
		getRanVec(a, arrSize, increase, 1);
		for (int j = 0; j < arrSize - 1; j++)
		{
			outFile << a[j] << ' ';
		}
		outFile << a[arrSize-1] << endl;
	}

	getRanVec(a, arrSize, increase, 1);
	for (int j = 0; j < arrSize - 1; j++)
	{
		outFile << a[j] << ' ';
	}
	outFile << a[arrSize-1];

	outFile.close();
}

void  bestCase(int nArray, int arrSize, char* fileName)
{
	genOrderedIntArray(nArray, arrSize, fileName, 0);
}
void worstCase(int nArray, int arrSize, char* fileName)
{
	genOrderedIntArray(nArray, arrSize, fileName, 1);
}
void averageCase(int nArray, int arrSize, char* fileName)
{
	genRandomIntArray(nArray, arrSize, fileName);
}
