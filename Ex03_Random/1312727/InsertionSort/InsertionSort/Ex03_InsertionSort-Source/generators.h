#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int genRandomIntArray(int nArray, int arrSize, char* fileName);
int genOrderedIntArray(int nArray, int arrSize, char* fileName, bool increase);
void bestCase(int nArray, int arrSize, char* fileName);
void worstCase(int nArray, int arrSize, char* fileName);
void averageCase(int nArray, int arrSize, char* fileName);
