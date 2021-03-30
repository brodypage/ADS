#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;
class List
{
public:
	Node* head = NULL;

	int count();
	void displayList();

	void insertAtBeginning(int element);
	void insertAtEnd(int element);
	void deleteAtFront();
	void deleteAtEnd();
};