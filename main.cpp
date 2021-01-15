#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"

using namespace std;

void displayToh(Stack* t1, Stack* t2, Stack* t3) {
	t1->display();
	t2->display();
	t3->display();
	cout << endl;
}

//Makes move between t1 and t2 in whatever direction is legal
void makeMove(Stack* t1, Stack* t2) {
	if (t1->empty()) {
		t1->push(t2->pop());
	}
	else if (t2->empty()) {
		t2->push(t1->pop());
	}
	else if (((Disc*)(t1->top()))->getSize() < ((Disc*)(t2->top()))->getSize()) {
		t2->push(t1->pop());
	}
	else {
		t1->push(t2->pop());
	}
}

void toh(int n)
{
	Stack* t1 = new Stack();
	Stack* t2 = new Stack();
	Stack* t3 = new Stack();
	
	
	for (int i = n; i >= 1; i--)
	{
		Disc* d = new Disc(i);
		t1->push(d);
	}
	
	displayToh(t1, t2, t3);
	
	if (n % 2 == 0) {
		while (!(t1->empty() && (t2->empty() || t3->empty()))) //While the tower hasn't completely moved
		{
			makeMove(t1, t2);
			displayToh(t1, t2, t3);
			if (!(t1->empty() && (t2->empty() || t3->empty()))) {
				makeMove(t1, t3);
				displayToh(t1, t2, t3);
			}
			if (!(t1->empty() && (t2->empty() || t3->empty()))) {
				makeMove(t2, t3);
				displayToh(t1, t2, t3);
			}
		}
	}
	else {
		while (!(t1->empty() && (t2->empty() || t3->empty()))) //While the tower hasn't completely moved
		{
			makeMove(t1, t3);
			displayToh(t1, t2, t3);
			if (!(t1->empty() && (t2->empty() || t3->empty()))) {
				makeMove(t1, t2);
				displayToh(t1, t2, t3);
			}
			if (!(t1->empty() && (t2->empty() || t3->empty()))) {
				makeMove(t2, t3);
				displayToh(t1, t2, t3);
			}
		}
	}
	
	delete t1;
	delete t2;
	delete t3;
}
int main()
{
    int n;
    cout << "enter the number of disks: ";
    cin >> n;
    toh(n);
    return 0;
}