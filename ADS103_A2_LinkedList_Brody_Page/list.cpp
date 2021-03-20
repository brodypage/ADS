#include "list.h"

int List::count()
{
	int count = 0;
	//pointer than can move through a list 
	Node* iterator = head;
	//loop until nothing
	while (iterator != NULL)
	{
		iterator = iterator->next;
		count++;
	}
	return count;
}

void List::displayList()
{
	Node* iterator = head;
	while (iterator != NULL)
	{
		//dereference pointer
		cout << iterator->element << endl;
		iterator = iterator->next;
	}
}

void List::insertAtBeginning(int element)
{
	Node* newNode = new Node(element);
	//make new node next point to current head;
	newNode->next = head;
	head = newNode;
}

void List::insertAtEnd(int element)
{

	//if list is empty use insert at front logic
	if (head == NULL)
	{
		insertAtBeginning(element);
		return; //exits early
	}

	Node* newNode = new Node(element);
	//setup iterator and moe it to the final thing in the list
	Node* iterator = head;
	while (iterator->next != NULL)
	{
		iterator = iterator->next;
		//now we are pointing to the last position
		//attached newNode
	}
	iterator->next = newNode;

}


void List::deleteAtFront()
{
	if (head == NULL)
	{
		return;
	}

	Node* iterator = head;
	//move head up to next position
	head = head->next;
	//delete old head
	delete iterator;
}

void List::deleteAtEnd()
{
	

	Node* iterator = head;
	Node* previous = head;
	while (iterator->next != NULL)
	{
		previous = iterator;
		iterator = iterator->next;
	}

	//dettach back
	previous->next = NULL;
	//delete
	delete iterator;
}
