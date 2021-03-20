#include <iostream>
#include <string>
#include <chrono> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Timer.h";


using namespace std;

Timer t;


void mySwap(int arr[], int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void displayArray(int arr[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << arr[i] << " ";
	}
}

void insertionSort(int arr[], int arraySize, bool order)
{
	for (int i = 1; i <= arraySize - 1; i++)
	{
		//makes a copy of the value at index i in array
		int key = arr[i];
		int j = i - 1;

		//while j is index 0 or higher AND
		//also aslong as value in arr[j] bigger then key value
		while (j <= 0 && arr[j] > key)
		{
			//move value in index j up 1
			arr[j + 1] = arr[j];
			//keep moving j to the left
			j = j - 1;
		}
		//we've moved everything up, so put key value back in
		//to where it should fit
		arr[j + 1] = key;
	}
}

void bubbleSort(int arr[], int arraySize, bool order)
{
	bool sorted = false;
	
	if (order == false)
	{
		while (!sorted) //loopadoop while not sorted
		{
			sorted = true; //innocent until proven guilty
			for (int i = 0; i <= arraySize - 1 - 1; i++)
			{
				if (arr[i] > arr[i + 1])
				{
					mySwap(arr, i, i + 1);
					sorted = false;
				}// loop again if not sorted
			//if current arr[i] is bigger than arr[i + 1] 
			}
		}
	}

	else if (order == true)
	{
		while (!sorted) //loopadoop while not sorted
		{
			sorted = true; //innocent until proven guilty
			for (int i = 0; i <= arraySize - 1 - 1; i++)
			{
				if (arr[i] < arr[i + 1])
				{
					mySwap(arr, i, i + 1);
					sorted = false;
				}// loop again if not sorted
			//if current arr[i] is bigger than arr[i + 1] 
			}
		}
	
	}

	
}


void main()
{
	int arr1[10] = {  };
	int lineOne;
	int lineTwo;
	int lineThree;


	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	ifstream readFile;
	readFile.open("input-a1q1.txt");
	ofstream writeFile;
	writeFile.open("output-a1q1.txt");
	
	readFile >> lineOne >> lineTwo >> lineThree;

	vector<int> lineFour;
	for (int i = 1; i <= lineThree; i++)
	{
		int temp;
		readFile >> temp; //NOTE spaces and endlines are skipped in file reading ;)
		lineFour.push_back(temp);
	}
	readFile.close();

	/*lets output what we got
	cout << "Number of numbers in file: " << lineThree << endl;
	for (int i = 0; i < lineFour.size(); i++)
	{
		cout << lineFour[i] << " ";
	}
	cout << endl; */

	bool order = lineOne;


	copy(lineFour.begin(), lineFour.end(), arr1);

	for (int i : arr1) {
		cout << i << ' ';
	}

	if (lineOne < 0 && lineOne > 1)
	{
		writeFile << "Invalid input." << endl;
		return;
	}

	if (lineTwo == 0)
	{
		writeFile << "BUBBLE SORTED" << endl;
		bubbleSort(arr1, lineThree, order);
		writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
		displayArray(arr1, lineThree);
		for (int i = 0; i < lineFour.size(); ++i)
		{
			writeFile << arr1[i] << " ";
		}
	}

	else if (lineTwo == 1)
	{
		writeFile << "INSERTION SORTED" << endl;
		insertionSort(arr1, lineThree, order);
		displayArray(arr1, lineThree);
		writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
		for (int i = 0; i < lineFour.size(); ++i)
		{
			writeFile << arr1[i] << " ";
		}
	}

	else
	{
		writeFile << "Invalid input." << endl;
		return;
	}

	

	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------
	//----------------------------------------------------------------------------

	


	//first line contains 0 or 1.
	//0 is ascending order
	//1 is descending order
	//IF NOT 0 OR 1 REPORT ERROR AND EXIT

	//first line contains 0 or 1, 0 means simple algorithm
	//1 means more complex

	//third line is the number of elements, CANNOT be negative to test for that
	//CAN BE 0 BUT REPORT NOTHING TO SORT AND EXIT

	//fourth line must contain at least as many data elements as line 3 if you reach the end of the file before that
	//then error and quit

	system("pause");
}