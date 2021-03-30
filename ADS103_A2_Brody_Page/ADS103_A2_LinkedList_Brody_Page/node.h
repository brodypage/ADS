#pragma once
#include <iostream>
#include <string>

using namespace std;
class Node
{
public:
	//data
	int element;

	//pointer to next node
	Node* next;

	//contructors
	Node();
	Node(int element);
};

