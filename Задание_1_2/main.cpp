#include <iostream>
#include "ClassA.h"
#include "ClassB.h"
using namespace std;


int main()
{
	{
		ClassA obj1;
		ClassA obj2("Hello");
	}
	
	ClassB* ptr1 = new ClassB();
	ClassB* ptr2 = new ClassB("Bye");
	
	delete ptr1;
	delete ptr2;
}