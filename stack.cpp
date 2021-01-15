#include<stdio.h>
#include<iostream>
#include<math.h>
#include <stack.h>
#include "disc.h"
using namespace std;

Stack::Stack()
{
	pTop = NULL;
}

Stack::~Stack()
{
	Node * parser = pTop;
	while (parser != NULL) {
		Node * thisNode = parser;
		parser = parser->pNext;
		delete thisNode;
	}
}

void Stack::push(void* inData)
{
	Node * newTop = new Node;
	newTop->data = inData;
	if (empty()) {
		newTop->pNext = NULL;
	}
	else {
		newTop->pNext = pTop;
	}
	pTop = newTop;
}
void* Stack::pop()
{
	void* output = pTop->data;
	pTop = pTop->pNext;
	return output;
}

void* Stack::top()
{
	return (pTop->data);
}

bool Stack::empty()
{
	return (pTop == NULL);
}

void Stack::display()
{
	//cout<<endl;
	Node *p1;
	p1 = pTop;
	while (p1 != NULL)
	{
		cout << ((Disc*)(p1->data))->toString() << "\t";
		p1 = p1->pNext;
	}
	cout<<endl;
}