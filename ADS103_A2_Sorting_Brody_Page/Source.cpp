#include <iostream>
#include <string>
#include <chrono> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Timer.h"


using namespace std;

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

int partition(int arr1[], int low, int high, bool order)
{
	int pivot = arr1[low];
	int i = low, j = high;

	if (order == false)
	{
		while (i < j)
		{

			do {
				i++;
			} while (arr1[i] <= pivot);


			do {
				j--;
			} while (arr1[j] > pivot);

			if (i < j)
				swap(arr1[i], arr1[j]);
		}
		swap(arr1[low], arr1[j]);


		return j;
	}

	else if (order == true)
	{
		while (i < j)
		{

			do {
				i++;
			} while (arr1[i] > pivot);


			do {
				j--;
			} while (arr1[j] < pivot);

			if (i < j)
				swap(arr1[i], arr1[j]);
		}
		swap(arr1[low], arr1[j]);


		return j;
	}

}

void quickSort(int arr1[], int low, int high, bool order)
{
	
	if (low < high)
	{
		int partitionIndex = partition(arr1, low, high, order);
		quickSort(arr1, low, partitionIndex, order);
		quickSort(arr1, partitionIndex + 1, high, order);
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
	int lineOne;
	int lineTwo;
	int lineThree;


	//----------------------------------------------------------------------------
	//---------------------READ AND WRITE-----------------------------------------
	//----------------------------------------------------------------------------

	ifstream readFile;
	readFile.open("input-a1q1.txt");
	ofstream writeFile;
	writeFile.open("output-a1q1.txt");

	readFile >> lineOne >> lineTwo >> lineThree;

	int* array = new int(lineThree);

	for (int i = 0; i < lineThree; i++)
	{
		if (readFile.eof())
		{
			writeFile << "Line Three error. There are less elements than specified!";
			return;
		}
		 readFile >> array[i];
	}

	readFile.close(); //stop reading file

	bool order = lineOne; // tests true or false to determine whether it will be ascending or descending

	//----------------------------------------------------------------------------
	//---------------------ERROR TESTING------------------------------------------
	//----------------------------------------------------------------------------

	if (lineOne != 0 && lineOne != 1)
	{
		writeFile << "Line One error. Must be 0 or 1." << endl; // if line one less than 0 and greater than one, quit
		return;
	}

	if (lineTwo != 0 && lineTwo != 1)
	{
		writeFile << "Line Two error. Must be 0 or 1." << endl; // if line one less than 0 and greater than one, quit
		return;
	}


	if (lineThree < 0)
	{
		writeFile << "Line three error. Must either be a positive value or if 0, there is nothing to sort." << endl;
		return;
	}

	//----------------------------------------------------------------------------
	//---------------------SORTING------------------------------------------------
	//----------------------------------------------------------------------------

	if (lineTwo == 0)
	{
		//if line two = 0, bubble sort
		writeFile << "BUBBLE SORTED" << endl;
		Timer t;
		bubbleSort(array, lineThree, order);
		writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
		displayArray(array, lineThree);
		for (int i = 0; i < lineThree; ++i)
		{
			writeFile << array[i] << " ";
		}
	}

	else if (lineTwo == 1)
	{
		//if line two equals 1, quick sort
		writeFile << "QUICK SORTED" << endl;
		Timer t;
		quickSort(array, 0, lineThree, order);
		displayArray(array, lineThree);
		writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
		for (int i = 0; i < lineThree; ++i)
		{
			writeFile << array[i] << " ";
		}
	}

	else
	{
		//if neither 0 or 1, quit
		writeFile << "Second line error. Must be 0 or 1." << endl;
		return;
	}

	system("pause");
}