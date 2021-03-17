#include <iostream>
#include <string>
#include <chrono> 
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <vector>
#include "List.h"
#include "Timer.h"

using namespace std;

void main()
{
	//VARIABLES
	List list1;
	List list2;
	Timer t;
	int n = rand(); //VARIABLE TO INSERT INTO LIST


	// FILE READING
	ifstream readFile;
	ofstream writeFile;
	readFile.open("input-a1q2.txt");
	int amountNumbers;
	readFile >> amountNumbers;
	writeFile.open("output-a1q2.txt");


	// -------------------------------------------------------------------------------
	// --------------------INSERT AT FRONT------------------------------------------
	// -------------------------------------------------------------------------------
	writeFile << "INSERT AT FRONT" << endl;
	writeFile << "Amount of numbers detected in file: " << amountNumbers << endl;

	for (int i = 0; i < amountNumbers; i++) // WHILE 0 IS LESS THAN WHATEVER THE NUMBER IN FILES, ADD TO BEGINNING
	{
		list1.insertAtBeginning(n);
	}
	writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
	writeFile << "Size of list: " << list1.count() << endl << endl;


	Sleep(2000);

	// -------------------------------------------------------------------------------
	// --------------------DELETE FROM FRONT------------------------------------------
	// -------------------------------------------------------------------------------

	writeFile << "DELETE FROM FRONT" << endl;
	writeFile << "Amount of numbers detected in list: " << list1.count() << endl;

	for (int i = 0; i < amountNumbers; i++)
	{
		list1.deleteAtFront();
	}
	writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
	writeFile << "Size of list after deleting from front: " << list1.count() << endl << endl;

	Sleep(2000);

	// -------------------------------------------------------------------------------
	// --------------------INSERT AT END------------------------------------------
	// -------------------------------------------------------------------------------

	writeFile << "INSERT AT END" << endl;
	writeFile << "Amount of numbers detected in file: " << amountNumbers << endl;

	for (int i = 0; i < amountNumbers; i++) // WHILE 0 IS LESS THAN WHATEVER THE NUMBER IN FILES, AND TO END
	{
		list2.insertAtEnd(n);
	}
	
	writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl;
	writeFile << "Size of list: " << list2.count() << endl << endl;
	Sleep(2000);


	// -------------------------------------------------------------------------------
	// --------------------DELETE FROM END------------------------------------------
	// -------------------------------------------------------------------------------

	writeFile << "DELETE FROM END" << endl;
	writeFile << "Amount of numbers detected in list: " << list2.count() << endl;

	for (int i = 0; i < amountNumbers; i++)
	{
		list2.deleteAtEnd();

	}
	writeFile << "Time elapsed: " << t.elapsed() << " Milliseconds" << endl << endl;
	writeFile << "Size of list after deleting from end: " << list2.count() << endl;


	system("pause");

}